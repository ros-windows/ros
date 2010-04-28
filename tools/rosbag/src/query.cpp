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

#include "rosbag/query.h"
#include "rosbag/bag.h"

#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

using std::map;
using std::string;
using std::vector;
using std::multiset;

namespace rosbag {

// Query

Query::Query(ros::Time const& start_time, ros::Time const& end_time)
	: start_time_(start_time), end_time_(end_time)
{
}

Query::~Query() { }

ros::Time Query::getStartTime() const { return start_time_; }
ros::Time Query::getEndTime()   const { return end_time_;   }

bool Query::evaluate(TopicInfo const*) const { return true; }

Query* Query::clone() const { return new Query(*this); }

// TopicQuery

TopicQuery::TopicQuery(std::string const& topic, ros::Time const& start_time, ros::Time const& end_time)
    : Query(start_time, end_time)
{
    topics_.push_back(topic);
}

TopicQuery::TopicQuery(std::vector<std::string> const& topics, ros::Time const& start_time, ros::Time const& end_time)
	: Query(start_time, end_time), topics_(topics)
{
}

bool TopicQuery::evaluate(TopicInfo const* info) const {
    foreach(string const& topic, topics_)
        if (topic == info->topic)
            return true;

    return false;
}

Query* TopicQuery::clone() const { return new TopicQuery(*this); }

// TypeQuery

TypeQuery::TypeQuery(std::string const& type, ros::Time const& start_time, ros::Time const& end_time)
    : Query(start_time, end_time)
{
    types_.push_back(type);
}

TypeQuery::TypeQuery(std::vector<std::string> const& types, ros::Time const& start_time, ros::Time const& end_time)
    : Query(start_time, end_time), types_(types)
{
}

bool TypeQuery::evaluate(TopicInfo const* info) const {
    foreach(string const& type, types_)
        if (type == info->datatype)
            return true;

    return false;
}

Query* TypeQuery::clone() const { return new TypeQuery(*this); }

// BagQuery

BagQuery::BagQuery(Bag* _bag, Query const& _query, uint32_t _bag_revision) : bag(_bag), bag_revision(_bag_revision) {
    query = _query.clone();
}

BagQuery::~BagQuery() {
    delete query;
}

// MessageRange

MessageRange::MessageRange(std::multiset<IndexEntry>::const_iterator const& _begin,
                           std::multiset<IndexEntry>::const_iterator const& _end,
                           TopicInfo const* _topic_info,
                           BagQuery const* _bag_query)
	: begin(_begin), end(_end), topic_info(_topic_info), bag_query(_bag_query)
{
}

// ViewIterHelper

ViewIterHelper::ViewIterHelper(std::multiset<IndexEntry>::const_iterator _iter, MessageRange const* _range)
	: iter(_iter), range(_range)
{
}

bool ViewIterHelperCompare::operator()(ViewIterHelper const& a, ViewIterHelper const& b) {
	return (a.iter)->time > (b.iter)->time;
}

}