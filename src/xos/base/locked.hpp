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
///   File: locked.hpp
///
/// Author: $author$
///   Date: 4/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_LOCKED_HPP
#define _XOS_BASE_LOCKED_HPP

#include "xos/base/exception.hpp"

namespace xos {

typedef int lock_status;
enum {
    unlock_success,
    lock_success = unlock_success,

    lock_failed,
    unlock_failed,
    
    lock_busy,
    lock_interrupted,
    lock_invalid,

    unlock_busy,
    unlock_interrupted,
    unlock_invalid
};
template <class TString>
inline const TString lock_status_to_string(lock_status status) {
    switch (status) {
    case lock_success: return TString("lock_success");

    case lock_failed: return TString("lock_failed");
    case unlock_failed: return TString("unlock_failed");

    case lock_busy: return TString("lock_busy");
    case lock_interrupted: return TString("lock_interrupted");
    case lock_invalid: return TString("lock_invalid");

    case unlock_busy: return TString("unlock_busy");
    case unlock_interrupted: return TString("unlock_interrupted");
    case unlock_invalid: return TString("unlock_invalid");
    }
    return TString("unknown");
}
///////////////////////////////////////////////////////////////////////
///  Class: lock_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = exception_implementt<lock_status, char, char_string>, 
 class TExtends = exceptiont<lock_status, char, char_string, TImplements> >
class _EXPORT_CLASS lock_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    
    typedef typename implements::status_t status_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    lock_exceptiont(status_t status): extends(status) {
    }
    lock_exceptiont(const lock_exceptiont &copy): extends(copy) {
    }
    virtual ~lock_exceptiont() {
    }

    virtual string_t status_to_string() const {
        return lock_status_to_string<string_t>(this->status());
    }
};
typedef lock_exceptiont<> lock_exception;

typedef implement_base lockedt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: lockedt
///////////////////////////////////////////////////////////////////////
template <class TImplements = lockedt_implements>
class _EXPORT_CLASS lockedt: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual bool lock() { 
        return false; 
    }
    virtual lock_status try_lock() { 
        return lock_failed; 
    }
    virtual lock_status untimed_lock() { 
        return lock_failed; 
    }
    virtual lock_status timed_lock(mseconds_t milliseconds) { 
        return lock_failed; 
    }
    virtual bool unlock() { 
        return false; 
    }
};
typedef lockedt<> locked;

typedef locked unlockedt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: unlockedt
///////////////////////////////////////////////////////////////////////
template <class TImplements = unlockedt_implements>
class _EXPORT_CLASS unlockedt: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual bool lock() { 
        return true; 
    }
    virtual lock_status try_lock() { 
        return lock_success; 
    }
    virtual lock_status untimed_lock() { 
        return lock_success; 
    }
    virtual lock_status timed_lock(mseconds_t milliseconds) { 
        return lock_success; 
    }
    virtual bool unlock() { 
        return true; 
    }
};
typedef unlockedt<> unlocked;

typedef implement_base lockt_implements;
typedef base lockt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: lockt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = lockt_implements, class TExtends = lockt_extends>
class _EXPORT_CLASS lockt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    lockt(locked& _locked, mseconds_t milliseconds): locked_(_locked) {
        lock_status status = lock_failed;
        if (lock_success != (status = locked_.timed_lock(milliseconds))) {
            lock_exception e(status);
            throw (e);
        }
    }
    lockt(locked& _locked): locked_(_locked) {
        if (!(locked_.lock())) {
            lock_exception e(lock_failed);
            throw (e);
        }
    }
    virtual ~lockt() {
        if (!(locked_.unlock())) {
            lock_exception e(unlock_failed);
            throw (e);
        }
    }
private:
    lockt(const lockt &copy) {
    }

protected:
    locked& locked_;
};
typedef lockt<> lock;

///////////////////////////////////////////////////////////////////////
///  Class: try_lockt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = lockt_implements, class TExtends = lockt_extends>
class _EXPORT_CLASS try_lockt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    try_lockt(locked& _locked): locked_(_locked) {
        lock_status status = lock_failed;
        if (lock_success != (status = locked_.try_lock())) {
            lock_exception e(status);
            throw (e);
        }
    }
    virtual ~try_lockt() {
        if (!(locked_.unlock())) {
            lock_exception e(unlock_failed);
            throw (e);
        }
    }
private:
    try_lockt(const try_lockt &copy) {
    }

protected:
    locked& locked_;
};
typedef try_lockt<> try_lock;

} /// namespace xos

#endif /// _XOS_BASE_LOCKED_HPP 
