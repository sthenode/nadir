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
///   File: suspended.hpp
///
/// Author: $author$
///   Date: 2/2/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_SUSPENDED_HPP
#define _XOS_BASE_SUSPENDED_HPP

#include "xos/base/exception.hpp"

namespace xos {

typedef int suspend_status;
enum {
    resume_success,
    suspend_success = resume_success,

    suspend_failed,
    suspend_busy,
    suspend_interrupted,
    suspend_invalid,

    resume_failed,
    resume_busy,
    resume_interrupted,
    resume_invalid
};

template <class TString>
inline TString suspend_status_to_string(suspend_status status) {
    switch (status) {
    case suspend_success: return TString("suspend_success");
    case suspend_failed: return TString("suspend_failed");
    case suspend_busy: return TString("suspend_busy");
    case suspend_interrupted: return TString("suspend_interrupted");
    case suspend_invalid: return TString("suspend_invalid");

    case resume_failed: return TString("resume_failed");
    case resume_busy: return TString("resume_busy");
    case resume_interrupted: return TString("resume_interrupted");
    case resume_invalid: return TString("resume_invalid");
    }
    return TString("unknown");
}

///////////////////////////////////////////////////////////////////////
///  Class: suspend_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = exception_implementt<suspend_status, char, char_string>, 
 class TExtends = exceptiont<suspend_status, char, char_string, TImplements> >
class _EXPORT_CLASS suspend_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    
    typedef typename implements::status_t status_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    suspend_exceptiont(status_t status): extends(status) {
    }
    suspend_exceptiont(const suspend_exceptiont &copy): extends(copy) {
    }
    virtual ~suspend_exceptiont() {
    }

    virtual string_t status_to_string() const {
        return suspend_status_to_string<string_t>(this->status());
    }
};
typedef suspend_exceptiont<> suspend_exception;

typedef implement_base suspendedt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: suspendedt
///////////////////////////////////////////////////////////////////////
template <class TImplements = suspendedt_implements>
class _EXPORT_CLASS suspendedt: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef suspendedt<> suspended;

} /// namespace xos

#endif /// _XOS_BASE_SUSPENDED_HPP 
