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
///   File: logged.hpp
///
/// Author: $author$
///   Date: 4/13/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_LOGGED_HPP
#define _XOS_BASE_LOGGED_HPP

#include "xos/base/base.hpp"

namespace xos {

typedef implement_base loggedt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: loggedt
///////////////////////////////////////////////////////////////////////
template <class TImplements = loggedt_implements>
class _EXPORT_CLASS loggedt: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual bool set_is_logged(bool to = true) {
        return is_logged();
    }
    virtual bool is_logged() const {
        return true;
    }

    virtual bool set_is_err_logged(bool to = true) {
        return is_err_logged();
    }
    virtual bool is_err_logged() const {
        return true;
    }

    virtual bool set_is_logged_debug(mseconds_t threashold) {
        return is_logged_debug(threashold);
    }
    virtual bool is_logged_debug(mseconds_t milliseconds) const {
        mseconds_t threashold = is_logged_debug_threashold();
        return (milliseconds >= threashold);
    }
    virtual mseconds_t is_logged_debug_threashold() const {
        return 500;
    }
};
typedef loggedt<> logged;

namespace extended {

typedef xos::logged loggedt_implements;
typedef base loggedt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: loggedt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = loggedt_implements, class TExtends = loggedt_extends>
class _EXPORT_CLASS loggedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    loggedt(bool is_logged, bool is_err_logged)
    : is_logged_(is_logged), is_err_logged_(is_err_logged) {
    }
    loggedt(bool is_logged)
    : is_logged_(is_logged), is_err_logged_(true) {
    }
    loggedt(const loggedt &copy)
    : is_logged_(copy.is_logged()), is_err_logged_(copy.is_err_logged()) {
    }
    loggedt(): is_logged_(true), is_err_logged_(true) {
    }
    virtual ~loggedt() {
    }
    
    virtual bool set_is_logged(bool to = true) {
        is_logged_ = to;
        return is_logged_;
    }
    virtual bool is_logged() const {
        return is_logged_;
    }
    virtual bool set_is_err_logged(bool to = true) {
        is_err_logged_ = to;
        return is_err_logged_;
    }
    virtual bool is_err_logged() const {
        return is_err_logged_;
    }

protected:
    bool is_logged_, is_err_logged_;
};
typedef loggedt<> logged;

} /// namespace extended

} /// namespace xos

#endif /// _XOS_BASE_LOGGED_HPP 
        

