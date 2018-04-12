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
///   File: exception.hpp
///
/// Author: $author$
///   Date: 4/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_EXCEPTION_HPP
#define _XOS_BASE_EXCEPTION_HPP

#include "xos/base/string.hpp"

namespace xos {

typedef int exception_status;
enum {
    exception_success,
    exception_failed
};
template <class TString>
inline TString exception_status_to_string(exception_status status) {
    switch (status) {
    case exception_success: return TString("exception_success");
    case exception_failed: return TString("exception_failed");
    }
    return TString("unknown");
}
typedef implement_base exception_implementt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: exception_implementt
///////////////////////////////////////////////////////////////////////
template 
<typename TStatus = exception_status,
 typename TChar = char, class TString = char_stringt<TChar>,
 class TImplements = exception_implementt_implements>
class _EXPORT_CLASS exception_implementt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef TStatus status_t;
    typedef TString string_t;
    typedef TChar char_t;

    virtual string_t status_to_string() const {
        return exception_status_to_string<string_t>(this->status());
    }
    virtual status_t status() const { 
        return exception_failed; 
    }
    virtual operator status_t() const {
        return status(); 
    }
};
typedef base exceptiont_extends;
///////////////////////////////////////////////////////////////////////
///  Class: exceptiont
///////////////////////////////////////////////////////////////////////
template 
<typename TStatus = exception_status,
 typename TChar = char, class TString = char_stringt<TChar>,
 class TImplements = exception_implementt<TStatus, TChar, TString>, 
 class TExtends = exceptiont_extends>
class _EXPORT_CLASS exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef TStatus status_t;
    typedef TString string_t;
    typedef TChar char_t;

    exceptiont(status_t status): status_(status) {
    }
    exceptiont(const exceptiont &copy): status_(copy.status_) {
    }
    virtual ~exceptiont() {
    }

    virtual status_t status() const { 
        return status_; 
    }
protected:
    status_t status_;
};
typedef exceptiont<> exception;

} /// namespace xos

#endif /// _XOS_BASE_EXCEPTION_HPP 
