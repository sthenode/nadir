///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: output.hpp
///
/// Author: $author$
///   Date: 4/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_OUTPUT_HPP
#define _XOS_LOGGER_OUTPUT_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace logger {

} /// namespace logger
} /// namespace xos

///
/// STDERR_LOG_ LOCATION / FUNTION / PLAIN
/// 
#if !defined(STDERR_LOG_LOCATION)
#define STDERR_LOG_LOCATION(__message__) 
#endif /// !defined(STDERR_LOG_LOCATION)

#if !defined(STDERR_LOG_FUNCTION)
#define STDERR_LOG_FUNCTION(__message__) 
#endif /// !defined(STDERR_LOG_FUNCTION)

#if !defined(STDERR_LOG_PLAIN)
#define STDERR_LOG_PLAIN(__message__) 
#endif /// !defined(STDERR_LOG_PLAIN)

#if defined(STDERR_PLAIN_LOGGING)
#define STDERR_LOG STDERR_LOG_PLAIN
#else /// defined(STDERR_PLAIN_LOGGING)
#if defined(STDERR_FUNCTION_LOGGING)
#define STDERR_LOG STDERR_LOG_FUNCTION
#else /// defined(STDERR_FUNCTION_LOGGING)
#define STDERR_LOG STDERR_LOG_LOCATION
#endif /// defined(STDERR_FUNCTION_LOGGING)
#endif /// defined(STDERR_PLAIN_LOGGING)

///
/// STDERR_LOG_ TRACE .. FATAL
/// 
#if !defined(STDERR_LOG_TRACE)
#if defined(TRACE_BUILD)
#define STDERR_LOG_TRACE(__message__) STDERR_LOG(__message__)
#else /// defined(TRACE_BUILD)
#define STDERR_LOG_TRACE(__message__)
#endif /// defined(TRACE_BUILD)
#endif /// !defined(STDERR_LOG_TRACE)

#if !defined(STDERR_LOG_DEBUG)
#if defined(DEBUG_BUILD)
#define STDERR_LOG_DEBUG(__message__) STDERR_LOG(__message__)
#else /// defined(DEBUG_BUILD)
#define STDERR_LOG_DEBUG(__message__)
#endif /// defined(DEBUG_BUILD)
#endif /// !defined(STDERR_LOG_DEBUG)

#if !defined(STDERR_LOG_INFO)
#define STDERR_LOG_INFO(__message__) STDERR_LOG_DEBUG(__message__)
#endif /// !defined(STDERR_LOG_INFO)

#if !defined(STDERR_LOG_ERROR)
#define STDERR_LOG_ERROR(__message__) STDERR_LOG(__message__)
#endif /// !defined(STDERR_LOG_ERROR)

#if !defined(STDERR_LOG_WARN)
#define STDERR_LOG_WARN(__message__) STDERR_LOG_ERROR(__message__)
#endif /// !defined(STDERR_LOG_WARN)

#if !defined(STDERR_LOG_FATAL)
#define STDERR_LOG_FATAL(__message__) STDERR_LOG_ERROR(__message__)
#endif /// !defined(STDERR_LOG_FATAL)

///
/// ERR_LOG_ FATAL .. TRACE
/// 
#if !defined(ERR_LOG_FATAL)
#define ERR_LOG_FATAL(__message__) STDERR_LOG_FATAL(__message__)
#endif /// !defined(ERR_LOG_FATAL)

#if !defined(ERR_LOG_ERROR)
#define ERR_LOG_ERROR(__message__) STDERR_LOG_ERROR(__message__)
#endif /// !defined(ERR_LOG_ERROR)

#if !defined(ERR_LOG_WARN)
#define ERR_LOG_WARN(__message__) STDERR_LOG_WARN(__message__)
#endif /// !defined(ERR_LOG_WARN)

#if !defined(ERR_LOG_INFO)
#define ERR_LOG_INFO(__message__) STDERR_LOG_INFO(__message__)
#endif /// !defined(ERR_LOG_INFO)

#if !defined(ERR_LOG_DEBUG)
#define ERR_LOG_DEBUG(__message__) STDERR_LOG_DEBUG(__message__)
#endif /// !defined(ERR_LOG_DEBUG)

#if !defined(ERR_LOG_TRACE)
#define ERR_LOG_TRACE(__message__) STDERR_LOG_TRACE(__message__)
#endif /// !defined(ERR_LOG_TRACE)

#endif /// _XOS_LOGGER_OUTPUT_HPP 
