// Copyright (c) 2009, Willow Garage, Inc.
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Willow Garage, Inc. nor the names of its
//       contributors may be used to endorse or promote products derived from
//       this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include "rosbag/view.h"
#include "rosbag/bag.h"
#include "rosbag/message_instance.h"

#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

using std::map;
using std::string;
using std::vector;

namespace rosbag {

// View::iterator

View::iterator::iterator(View const* view, bool end) : view_(view) {
	if (!end)
		populate();
}

void View::iterator::populate() {
	iters_.clear();
	foreach(MessageRange const* range, view_->ranges_)
		if (range->begin != range->end)
			iters_.push_back(ViewIterHelper(range->begin, range));

	std::sort(iters_.begin(), iters_.end(), ViewIterHelperCompare());
	view_revision_ = view_->view_revision_;
}

void View::iterator::populateSeek(vector<IndexEntry>::const_iterator iter) {
	iters_.clear();
	foreach(MessageRange const* range, view_->ranges_) {
		vector<IndexEntry>::const_iterator start = std::lower_bound(range->begin,
				range->end, iter->time, IndexEntryCompare());
		if (start != range->end)
			iters_.push_back(ViewIterHelper(start, range));
	}

	std::sort(iters_.begin(), iters_.end(), ViewIterHelperCompare());
	while (iter != iters_.back().iter)
		increment();

	view_revision_ = view_->view_revision_;
}

bool View::iterator::equal(View::iterator const& other) const {
	// We need some way of verifying these are actually talking about
	// the same merge_queue data since we shouldn't be able to compare
	// iterators from different Views.

	if (iters_.empty())
		return other.iters_.empty();
	if (other.iters_.empty())
		return false;

	return iters_.back().iter == other.iters_.back().iter;
}

void View::iterator::increment() {
	if (view_revision_ != view_->view_revision_)
		populateSeek(iters_.back().iter);

	iters_.back().iter++;
	if (iters_.back().iter == iters_.back().range->end)
		iters_.pop_back();

	std::sort(iters_.begin(), iters_.end(), ViewIterHelperCompare());
}

//! \todo some check in case we are at end
MessageInstance View::iterator::dereference() const {
	ViewIterHelper const& i = iters_.back();
	return MessageInstance(i.range->topic_info, *(i.iter), *(i.range->bag_query->first));
}

// View
View::View() : view_revision_(0) { }

View::~View() {
	foreach(MessageRange* range, ranges_)
		delete range;
	foreach(BagQuery* query, queries_)
		delete query;
}

//! Simply copy the merge_queue state into the iterator
View::iterator View::begin() const { return iterator(this);       }

//! Default constructed iterator signifies end
View::iterator View::end()   const { return iterator(this, true); }

//! \todo: this doesn't work for now
uint32_t       View::size()  const { return 0;                    }

void View::addQuery(Bag& bag, Query const& query) {
	vector<ViewIterHelper> iters;

	queries_.push_back(new BagQuery(&bag, query));

	for (map<string, TopicInfo*>::iterator i = bag.topic_infos_.begin(); i != bag.topic_infos_.end(); i++) {
		if (!query.evaluate(i->second))
			continue;

		map<string, vector<IndexEntry> >::iterator j = bag.topic_indexes_.find(i->second->topic);
		if (j == bag.topic_indexes_.end())
			continue;

        // lower_bound/upper_bound do a binary search to find the appropriate range of Index Entries given our time range
        MessageRange* range = new MessageRange(
			std::lower_bound(j->second.begin(), j->second.end(), query.getStartTime(), IndexEntryCompare()),
			std::upper_bound(j->second.begin(), j->second.end(), query.getEndTime(),   IndexEntryCompare()),
			i->second,
			queries_.back());

        ranges_.push_back(range);
	}

	view_revision_ += 1;
}

}