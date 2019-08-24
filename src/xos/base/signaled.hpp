///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
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
///   File: signaled.hpp
///
/// Author: $author$
///   Date: 8/19/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_SIGNALED_HPP
#define _XOS_BASE_SIGNALED_HPP

#include "xos/base/waited.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Enum: signal_status
///////////////////////////////////////////////////////////////////////
typedef int signal_status;
enum {
    signal_success = wait_success,
    signal_failed,
    signal_busy,
    signal_interrupted,
    signal_invalid
};
template <class TString = char_string>
inline const TString signal_status_to_string(signal_status status) {
    switch (status) {
    case signal_success: return TString("signal_success");
    case signal_failed: return TString("signal_failed");
    case signal_busy: return TString("signal_busy");
    case signal_interrupted: return TString("signal_interrupted");
    case signal_invalid: return TString("signal_invalid");
    }
    return TString(wait_status_to_string<TString>(status));
}
///////////////////////////////////////////////////////////////////////
///  Class: signal_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<typename TStatus = signal_status,
 class TImplements = exception_implementt<TStatus, char, char_string>, 
 class TExtends = exceptiont<TStatus, char, char_string, TImplements> >
class _EXPORT_CLASS signal_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::status_t status_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    signal_exceptiont(status_t status): extends(status) {
    }
    signal_exceptiont(const signal_exceptiont &copy): extends(copy) {
    }
    virtual ~signal_exceptiont() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t status_to_string() const {
        return signal_status_to_string(this->status());
    }
};
typedef signal_exceptiont<> signal_exception;

///////////////////////////////////////////////////////////////////////
///  Class: signaledt
///////////////////////////////////////////////////////////////////////
template <class TImplements = waited>
class _EXPORT_CLASS signaledt: virtual public TImplements {
public:
    typedef TImplements implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool signal() { 
        if (signal_success == (this->untimed_signal())) {
            return true;
        }
        return false; 
    }
    virtual signal_status try_signal() { 
        return signal_failed; 
    }
    virtual signal_status timed_signal(mseconds_t milliseconds) { 
        return signal_failed; 
    }
    virtual signal_status untimed_signal() { 
        return signal_failed; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS signaledt
typedef signaledt<> signaled;

} /// namespace xos

#endif /// _XOS_BASE_SIGNALED_HPP 
