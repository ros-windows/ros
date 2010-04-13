// !!!!!!!!!!!!!!!!!!!!!!! This is a generated file, do not edit manually

/*
 * Copyright (c) 2008, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#if (ROSCONSOLE_MIN_SEVERITY > ROSCONSOLE_SEVERITY_DEBUG)
#define ROS_DEBUG(...)
#define ROS_DEBUG_STREAM(args)
#define ROS_DEBUG_NAMED(name, ...)
#define ROS_DEBUG_STREAM_NAMED(name, args)
#define ROS_DEBUG_COND(cond, ...)
#define ROS_DEBUG_STREAM_COND(cond, args)
#define ROS_DEBUG_COND_NAMED(cond, name, ...)
#define ROS_DEBUG_STREAM_COND_NAMED(cond, name, args)
#else
#define ROS_DEBUG(...) ROS_LOG(ros::console::levels::Debug, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define ROS_DEBUG_STREAM(args) ROS_LOG_STREAM(ros::console::levels::Debug, ROSCONSOLE_DEFAULT_NAME, args)
#define ROS_DEBUG_NAMED(name, ...) ROS_LOG(ros::console::levels::Debug, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define ROS_DEBUG_STREAM_NAMED(name, args) ROS_LOG_STREAM(ros::console::levels::Debug, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, args)
#define ROS_DEBUG_COND(cond, ...) ROS_LOG_COND(cond, ros::console::levels::Debug, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define ROS_DEBUG_STREAM_COND(cond, args) ROS_LOG_STREAM_COND(cond, ros::console::levels::Debug, ROSCONSOLE_DEFAULT_NAME, args)
#define ROS_DEBUG_COND_NAMED(cond, name, ...) ROS_LOG_COND(cond, ros::console::levels::Debug, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define ROS_DEBUG_STREAM_COND_NAMED(cond, name, args) ROS_LOG_STREAM_COND(cond, ros::console::levels::Debug, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, args)
#endif

#if (ROSCONSOLE_MIN_SEVERITY > ROSCONSOLE_SEVERITY_INFO)
#define ROS_INFO(...)
#define ROS_INFO_STREAM(args)
#define ROS_INFO_NAMED(name, ...)
#define ROS_INFO_STREAM_NAMED(name, args)
#define ROS_INFO_COND(cond, ...)
#define ROS_INFO_STREAM_COND(cond, args)
#define ROS_INFO_COND_NAMED(cond, name, ...)
#define ROS_INFO_STREAM_COND_NAMED(cond, name, args)
#else
#define ROS_INFO(...) ROS_LOG(ros::console::levels::Info, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define ROS_INFO_STREAM(args) ROS_LOG_STREAM(ros::console::levels::Info, ROSCONSOLE_DEFAULT_NAME, args)
#define ROS_INFO_NAMED(name, ...) ROS_LOG(ros::console::levels::Info, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define ROS_INFO_STREAM_NAMED(name, args) ROS_LOG_STREAM(ros::console::levels::Info, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, args)
#define ROS_INFO_COND(cond, ...) ROS_LOG_COND(cond, ros::console::levels::Info, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define ROS_INFO_STREAM_COND(cond, args) ROS_LOG_STREAM_COND(cond, ros::console::levels::Info, ROSCONSOLE_DEFAULT_NAME, args)
#define ROS_INFO_COND_NAMED(cond, name, ...) ROS_LOG_COND(cond, ros::console::levels::Info, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define ROS_INFO_STREAM_COND_NAMED(cond, name, args) ROS_LOG_STREAM_COND(cond, ros::console::levels::Info, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, args)
#endif

#if (ROSCONSOLE_MIN_SEVERITY > ROSCONSOLE_SEVERITY_WARN)
#define ROS_WARN(...)
#define ROS_WARN_STREAM(args)
#define ROS_WARN_NAMED(name, ...)
#define ROS_WARN_STREAM_NAMED(name, args)
#define ROS_WARN_COND(cond, ...)
#define ROS_WARN_STREAM_COND(cond, args)
#define ROS_WARN_COND_NAMED(cond, name, ...)
#define ROS_WARN_STREAM_COND_NAMED(cond, name, args)
#else
#define ROS_WARN(...) ROS_LOG(ros::console::levels::Warn, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define ROS_WARN_STREAM(args) ROS_LOG_STREAM(ros::console::levels::Warn, ROSCONSOLE_DEFAULT_NAME, args)
#define ROS_WARN_NAMED(name, ...) ROS_LOG(ros::console::levels::Warn, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define ROS_WARN_STREAM_NAMED(name, args) ROS_LOG_STREAM(ros::console::levels::Warn, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, args)
#define ROS_WARN_COND(cond, ...) ROS_LOG_COND(cond, ros::console::levels::Warn, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define ROS_WARN_STREAM_COND(cond, args) ROS_LOG_STREAM_COND(cond, ros::console::levels::Warn, ROSCONSOLE_DEFAULT_NAME, args)
#define ROS_WARN_COND_NAMED(cond, name, ...) ROS_LOG_COND(cond, ros::console::levels::Warn, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define ROS_WARN_STREAM_COND_NAMED(cond, name, args) ROS_LOG_STREAM_COND(cond, ros::console::levels::Warn, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, args)
#endif

#if (ROSCONSOLE_MIN_SEVERITY > ROSCONSOLE_SEVERITY_ERROR)
#define ROS_ERROR(...)
#define ROS_ERROR_STREAM(args)
#define ROS_ERROR_NAMED(name, ...)
#define ROS_ERROR_STREAM_NAMED(name, args)
#define ROS_ERROR_COND(cond, ...)
#define ROS_ERROR_STREAM_COND(cond, args)
#define ROS_ERROR_COND_NAMED(cond, name, ...)
#define ROS_ERROR_STREAM_COND_NAMED(cond, name, args)
#else
#define ROS_ERROR(...) ROS_LOG(ros::console::levels::Error, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define ROS_ERROR_STREAM(args) ROS_LOG_STREAM(ros::console::levels::Error, ROSCONSOLE_DEFAULT_NAME, args)
#define ROS_ERROR_NAMED(name, ...) ROS_LOG(ros::console::levels::Error, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define ROS_ERROR_STREAM_NAMED(name, args) ROS_LOG_STREAM(ros::console::levels::Error, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, args)
#define ROS_ERROR_COND(cond, ...) ROS_LOG_COND(cond, ros::console::levels::Error, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define ROS_ERROR_STREAM_COND(cond, args) ROS_LOG_STREAM_COND(cond, ros::console::levels::Error, ROSCONSOLE_DEFAULT_NAME, args)
#define ROS_ERROR_COND_NAMED(cond, name, ...) ROS_LOG_COND(cond, ros::console::levels::Error, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define ROS_ERROR_STREAM_COND_NAMED(cond, name, args) ROS_LOG_STREAM_COND(cond, ros::console::levels::Error, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, args)
#endif

#if (ROSCONSOLE_MIN_SEVERITY > ROSCONSOLE_SEVERITY_FATAL)
#define ROS_FATAL(...)
#define ROS_FATAL_STREAM(args)
#define ROS_FATAL_NAMED(name, ...)
#define ROS_FATAL_STREAM_NAMED(name, args)
#define ROS_FATAL_COND(cond, ...)
#define ROS_FATAL_STREAM_COND(cond, args)
#define ROS_FATAL_COND_NAMED(cond, name, ...)
#define ROS_FATAL_STREAM_COND_NAMED(cond, name, args)
#else
#define ROS_FATAL(...) ROS_LOG(ros::console::levels::Fatal, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define ROS_FATAL_STREAM(args) ROS_LOG_STREAM(ros::console::levels::Fatal, ROSCONSOLE_DEFAULT_NAME, args)
#define ROS_FATAL_NAMED(name, ...) ROS_LOG(ros::console::levels::Fatal, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define ROS_FATAL_STREAM_NAMED(name, args) ROS_LOG_STREAM(ros::console::levels::Fatal, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, args)
#define ROS_FATAL_COND(cond, ...) ROS_LOG_COND(cond, ros::console::levels::Fatal, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__)
#define ROS_FATAL_STREAM_COND(cond, args) ROS_LOG_STREAM_COND(cond, ros::console::levels::Fatal, ROSCONSOLE_DEFAULT_NAME, args)
#define ROS_FATAL_COND_NAMED(cond, name, ...) ROS_LOG_COND(cond, ros::console::levels::Fatal, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, __VA_ARGS__)
#define ROS_FATAL_STREAM_COND_NAMED(cond, name, args) ROS_LOG_STREAM_COND(cond, ros::console::levels::Fatal, std::string(ROSCONSOLE_NAME_PREFIX) + "." + name, args)
#endif
