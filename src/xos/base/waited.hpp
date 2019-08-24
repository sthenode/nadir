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
///   File: waited.hpp
///
/// Author: $author$
///   Date: 4/13/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_WAITED_HPP
#define _XOS_BASE_WAITED_HPP

#include "xos/base/exception.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Enum: wait_status
///////////////////////////////////////////////////////////////////////
typedef int wait_status;
enum {
    continue_success,
    wait_success = continue_success,

    wait_failed,
    continue_failed,
    
    wait_busy,
    wait_interrupted,
    wait_invalid,

    continue_busy,
    continue_interrupted,
    continue_invalid
};
template <class TString = char_string>
inline const TString wait_status_to_string(wait_status status) {
    switch (status) {
    case wait_success: return TString("wait_success");

    case wait_failed: return TString("wait_failed");
    case continue_failed: return TString("continue_failed");

    case wait_busy: return TString("wait_busy");
    case wait_interrupted: return TString("wait_interrupted");
    case wait_invalid: return TString("wait_invalid");

    case continue_busy: return TString("continue_busy");
    case continue_interrupted: return TString("continue_interrupted");
    case continue_invalid: return TString("continue_invalid");
    }
    return TString("unknown");
}
///////////////////////////////////////////////////////////////////////
///  Class: wait_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = exception_implementt<wait_status, char, char_string>, 
 class TExtends = exceptiont<wait_status, char, char_string, TImplements> >
class _EXPORT_CLASS wait_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::status_t status_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    wait_exceptiont(status_t status): extends(status) {
    }
    wait_exceptiont(const wait_exceptiont &copy): extends(copy) {
    }
    virtual ~wait_exceptiont() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string_t status_to_string() const {
        return wait_status_to_string(this->status());
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef wait_exceptiont<> wait_exception;

typedef implement_base waitedt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: waitedt
///////////////////////////////////////////////////////////////////////
template <class TImplements = waitedt_implements>
class _EXPORT_CLASS waitedt: virtual public TImplements {
public:
    typedef TImplements implements;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool wait() { 
        if (wait_success == (this->untimed_wait())) {
            return true;
        }
        return false; 
    }
    virtual wait_status try_wait() { 
        return wait_failed; 
    }
    virtual wait_status untimed_wait() { 
        return wait_failed; 
    }
    virtual wait_status timed_wait(mseconds_t milliseconds) { 
        return wait_failed; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool continued() { 
        if (continue_success == (this->untimed_continued())) {
            return true;
        }
        return false; 
    }
    virtual wait_status try_continued() { 
        return continue_failed; 
    }
    virtual wait_status untimed_continued() { 
        return continue_failed; 
    }
    virtual wait_status timed_continued(mseconds_t milliseconds) { 
        return continue_failed; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef waitedt<> waited;

typedef waited continuedt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: continuedt
///////////////////////////////////////////////////////////////////////
template <class TImplements = continuedt_implements>
class _EXPORT_CLASS continuedt: virtual public TImplements {
public:
    typedef TImplements implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool wait() { 
        return true; 
    }
    virtual wait_status try_wait() { 
        return wait_success; 
    }
    virtual wait_status untimed_wait() { 
        return wait_success; 
    }
    virtual wait_status timed_wait(mseconds_t milliseconds) { 
        return wait_success; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef continuedt<> continued;

typedef implement_base waitt_implements;
typedef base waitt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: waitt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = waitt_implements, class TExtends = waitt_extends>
class _EXPORT_CLASS waitt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    waitt(waited& _waited): waited_(_waited) {
        if (!(waited_.wait())) {
            wait_exception e(wait_failed);
            throw (e);
        }
    }
    virtual ~waitt() {
    }
private:
    waitt(const waitt &copy) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    waited& waited_;
};
typedef waitt<> wait;

} /// namespace xos

#endif /// _XOS_BASE_WAITED_HPP 
