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
///   File: acquired.hpp
///
/// Author: $author$
///   Date: 4/13/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_ACQUIRED_HPP
#define _XOS_BASE_ACQUIRED_HPP

#include "xos/base/exception.hpp"

namespace xos {

typedef int acquire_status;
enum {
    release_success,
    acquire_success = release_success,

    acquire_failed,
    release_failed,
    
    acquire_busy,
    acquire_interrupted,
    acquire_invalid,

    release_busy,
    release_interrupted,
    release_invalid
};
template <class TString = char_string>
inline const TString acquire_status_to_string(acquire_status status) {
    switch (status) {
    case acquire_success: return TString("acquire_success");

    case acquire_failed: return TString("acquire_failed");
    case release_failed: return TString("release_failed");

    case acquire_busy: return TString("acquire_busy");
    case acquire_interrupted: return TString("acquire_interrupted");
    case acquire_invalid: return TString("acquire_invalid");

    case release_busy: return TString("release_busy");
    case release_interrupted: return TString("release_interrupted");
    case release_invalid: return TString("release_invalid");
    }
    return TString("unknown");
}
///////////////////////////////////////////////////////////////////////
///  Class: acquire_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = exception_implementt<acquire_status, char, char_string>, 
 class TExtends = exceptiont<acquire_status, char, char_string, TImplements> >
class _EXPORT_CLASS acquire_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    
    typedef typename implements::status_t status_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    acquire_exceptiont(status_t status): extends(status) {
    }
    acquire_exceptiont(const acquire_exceptiont &copy): extends(copy) {
    }
    virtual ~acquire_exceptiont() {
    }

    virtual string_t status_to_string() const {
        return acquire_status_to_string(this->status());
    }
};
typedef acquire_exceptiont<> acquire_exception;

typedef implement_base acquiredt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: acquiredt
///////////////////////////////////////////////////////////////////////
template <class TImplements = acquiredt_implements>
class _EXPORT_CLASS acquiredt: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual bool acquire() { 
        return false; 
    }
    virtual acquire_status try_acquire() { 
        return acquire_failed; 
    }
    virtual acquire_status untimed_acquire() { 
        return acquire_failed; 
    }
    virtual acquire_status timed_acquire(mseconds_t milliseconds) { 
        return acquire_failed; 
    }
    virtual bool release() { 
        return false; 
    }
};
typedef acquiredt<> acquired;

typedef acquired releasedt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: releasedt
///////////////////////////////////////////////////////////////////////
template <class TImplements = releasedt_implements>
class _EXPORT_CLASS releasedt: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual bool acquire() { 
        return true; 
    }
    virtual acquire_status try_acquire() { 
        return acquire_success; 
    }
    virtual acquire_status untimed_acquire() { 
        return acquire_success; 
    }
    virtual acquire_status timed_acquire(mseconds_t milliseconds) { 
        return acquire_success; 
    }
    virtual bool unacquire() { 
        return true; 
    }
};
typedef releasedt<> released;

typedef implement_base acquiret_implements;
typedef base acquiret_extends;
///////////////////////////////////////////////////////////////////////
///  Class: acquiret
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = acquiret_implements, class TExtends = acquiret_extends>
class _EXPORT_CLASS acquiret: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    acquiret(acquired& _acquired, mseconds_t time): acquired_(_acquired) {
        if (acquire_success != (acquired_.timed_acquire(time))) {
            acquire_exception e(acquire_failed);
            throw (e);
        }
    }
    acquiret(acquired& _acquired): acquired_(_acquired) {
        if (!(acquired_.acquire())) {
            acquire_exception e(acquire_failed);
            throw (e);
        }
    }
    virtual ~acquiret() {
    }
private:
    acquiret(const acquiret &copy) {
    }

protected:
    acquired& acquired_;
};
typedef acquiret<> acquire;

typedef implement_base releaset_implements;
typedef base releaset_extends;
///////////////////////////////////////////////////////////////////////
///  Class: releaset
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = releaset_implements, class TExtends = releaset_extends>
class _EXPORT_CLASS releaset: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    releaset(acquired& _acquired): acquired_(_acquired) {
        if (!(acquired_.release())) {
            acquire_exception e(release_failed);
            throw (e);
        }
    }
    virtual ~releaset() {
    }
private:
    releaset(const releaset &copy) {
    }

protected:
    acquired& acquired_;
};
typedef releaset<> release;

} /// namespace xos

#endif /// _XOS_BASE_ACQUIRED_HPP 
        

