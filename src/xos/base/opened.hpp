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
///   File: opened.hpp
///
/// Author: $author$
///   Date: 4/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_OPENED_HPP
#define _XOS_BASE_OPENED_HPP

#include "xos/base/attached.hpp"

namespace xos {

typedef exception_status open_status;
enum {
    close_success,
    open_success = close_success,
    open_failed,
    close_failed
};
template <class TString>
inline const TString open_status_to_string(open_status status) {
    switch (status) {
    case open_success: return TString("open_success");
    case open_failed: return TString("open_failed");
    case close_failed: return TString("close_failed");
    }
    return TString("unknown");
}
///////////////////////////////////////////////////////////////////////
///  Class: open_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<typename TStatus = open_status,
 typename TChar = char, class TString = char_stringt<TChar>,
 class TImplements = exception_implementt
 <TStatus, TChar, TString>, class TExtends = exception>
class _EXPORT_CLASS open_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TStatus status_t;
    typedef TString string_t;
    typedef TChar char_t;

    open_exceptiont(status_t status): extends(status) {
    }
    open_exceptiont(const open_exceptiont &copy): extends(copy) {
    }
    virtual ~open_exceptiont() {
    }

    virtual string_t status_to_string() const {
        return open_status_to_string<string_t>(this->status());
    }
};
typedef open_exceptiont<> open_exception;

typedef implement_base openert_implements;
///////////////////////////////////////////////////////////////////////
///  Class: openert
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = openert_implements>
class _EXPORT_CLASS openert: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual bool open() {
        if ((this->closed())) {
            if ((this->set_is_open())) {
                return true;
            }
        }
        return false;
    }
    virtual bool close() {
        if ((this->is_open())) {
            this->set_is_open(false);
            if ((this->is_closed())) {
                return true;
            }
        }
        return false;
    }
    virtual bool closed() {
        if ((this->is_open())) {
            if ((this->close())) {
                return true;
            }
            return false;
        }
        return true;
    }

    virtual bool set_is_open(bool to = true) {
        return false;
    }
    virtual bool is_open() const {
        return false;
    }
    virtual bool is_closed() const {
        return false;
    }
};
typedef openert<> opener;

typedef opener openedt_implements;
typedef base openedt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: openedt
///////////////////////////////////////////////////////////////////////
template 
<typename TAttached = pointer_t, 
 typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplement = openedt_implements, class TExtend = openedt_extends,
 class TImplements = attachert<TAttached, TUnattached, VUnattached, TImplement>,
 class TExtends = attachedt<TAttached, TUnattached, VUnattached, TImplements, TExtend> >
class _EXPORT_CLASS openedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    openedt(attached_t detached, bool is_open): extends(detached), is_open_(is_open) {
    }
    openedt(attached_t detached): extends(detached), is_open_(false) {
    }
    openedt(const openedt &copy): extends(copy), is_open_(false) {
    }
    openedt(): is_open_(false) {
    }
    virtual ~openedt() {
    }
    
    virtual bool open() {
        attached_t detached = (attached_t)(unattached);
        if ((attached_t)(unattached) != (detached = this->open_attached())) {
            this->set_is_open();
            return true;
        }
        return false;
    }
    virtual bool close() {
        attached_t detached = (attached_t)(unattached);
        this->set_is_open(false);
        if ((attached_t)(unattached) != (detached = this->detach())) {
            if ((this->close_detached(detached))) {
                return true;
            }
        } else {
            return true;
        }
        return false;
    }

    virtual attached_t open_attached() {
        attached_t detached = (attached_t)(unattached);
        if ((this->closed())) {
            if ((attached_t)(unattached) != (detached = open_detached())) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t open_detached() const {
        attached_t detached = (attached_t)(unattached);
        return detached;
    }
    virtual bool close_detached(attached_t detached) const {
        if ((detached)) {
            return true;
        }
        return false;
    }

    virtual bool set_is_open(bool to = true) {
        is_open_ = to;
        return is_open_;
    }
    virtual bool is_open() const {
        return is_open_;
    }

    virtual attached_t attach_opened
    (attached_t detached, bool is_open = true) {
        this->set_is_open(is_open);
        return extends::attach(detached);
    }
    virtual attached_t detach_opened(bool& is_open) {
        is_open = this->is_open();
        return this->detach();
    }
    virtual attached_t attach(attached_t detached) {
        this->set_is_open(false);
        return extends::attach(detached);
    }
    virtual attached_t detach() {
        this->set_is_open(false);
        return extends::detach();
    }

protected:
    bool is_open_;
};
typedef openedt<> opened;

} /// namespace xos

#endif /// _XOS_BASE_OPENED_HPP 
