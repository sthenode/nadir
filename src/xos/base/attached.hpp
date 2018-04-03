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
///   File: attached.hpp
///
/// Author: $author$
///   Date: 4/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_ATTACHED_HPP
#define _XOS_BASE_ATTACHED_HPP

#include "xos/base/exception.hpp"
#include "xos/io/logger.hpp"

namespace xos {

enum attach_status {
    detach_success,
    attach_success = detach_success,
    attach_failed,
    detach_failed
};
template <class TString>
inline const TString attach_status_to_string(attach_status status) {
    switch (status) {
    case attach_success: return TString("attach_success");
    case attach_failed: return TString("attach_failed");
    case detach_failed: return TString("detach_failed");
    }
    return TString("unknown");
}
///////////////////////////////////////////////////////////////////////
///  Class: attach_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<typename TStatus = exception_status,
 typename TChar = char, class TString = char_stringt<TChar>,
 class TImplements = exception_implementt
 <TStatus, TChar, TString>, class TExtends = exception>
class _EXPORT_CLASS attach_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef TStatus status_t;
    typedef TString string_t;
    typedef TChar char_t;

    attach_exceptiont(status_t status): extends(status) {
    }
    attach_exceptiont(const attach_exceptiont &copy): extends(copy) {
    }
    virtual ~attach_exceptiont() {
    }

    virtual string_t status_to_string() const {
        return attach_status_to_string(this->status());
    }
};
typedef attach_exceptiont<> attach_exception;

typedef implement_base attachert_implements;
///////////////////////////////////////////////////////////////////////
///  Class: attachert
///////////////////////////////////////////////////////////////////////
template 
<typename TAttached = pointer_t, 
 typename TUnattached = int,TUnattached VUnattached = 0,
 class TImplements = attachert_implements>
class _EXPORT_CLASS attachert: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    virtual bool detached() {
        if (((attached_t)unattached) != (this->attached_to())) {
            if (((attached_t)unattached) != (this->detach())) {
                return true;
            }
            return false;
        }
        return true;
    }
    virtual attached_t attach(attached_t detached) {
        return ((attached_t)unattached);
    }
    virtual attached_t detach() {
        return ((attached_t)unattached);
    }
    virtual attached_t attached_to() const {
        return ((attached_t)unattached);
    }
};
typedef attachert<> attacher;

typedef base attachedt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: attachedt
///////////////////////////////////////////////////////////////////////
template 
<typename TAttached = pointer_t, 
 typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplement = attachert_implements, class TExtends = attachedt_extends,
 class TImplements = attachert
 <TAttached, TUnattached, VUnattached, TImplement> >
class _EXPORT_CLASS attachedt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    attachedt(attached_t detached): attached_to_(detached) {
    }
    attachedt(const attachedt &copy): attached_to_(copy.attached_to()) {
    }
    attachedt(): attached_to_((attached_t)unattached) {
    }
    virtual ~attachedt() {
        if (!(this->detached())) {
            const attach_exception e(detach_failed);
            LOG_ERROR("...failed on this->detached() throw (const attach_exception e(detach_failed))...");
            throw (e);
        }
    }

    virtual attached_t attach(attached_t detached) {
        attached_to_ = detached;
        return attached_to_;
    }
    virtual attached_t detach() {
        attached_t detached = attached_to_;
        attached_to_ = ((attached_t)unattached);
        return detached;
    }
    virtual attached_t attached_to() const {
        return attached_to_;
    }

protected:
    attached_t attached_to_;
};
typedef attachedt<> attached;

} /// namespace xos

#endif /// _XOS_BASE_ATTACHED_HPP 
