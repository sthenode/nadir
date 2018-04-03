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
///   File: created.hpp
///
/// Author: $author$
///   Date: 4/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_CREATED_HPP
#define _XOS_BASE_CREATED_HPP

#include "xos/base/attached.hpp"

namespace xos {

enum create_status {
    destroy_success,
    create_success = destroy_success,
    create_failed,
    destroy_failed
};
template <class TString>
inline const TString create_status_to_string(create_status status) {
    switch (status) {
    case create_success: return TString("create_success");
    case create_failed: return TString("create_failed");
    case destroy_failed: return TString("destroy_failed");
    }
    return TString("unknown");
}
///////////////////////////////////////////////////////////////////////
///  Class: create_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<typename TStatus = exception_status,
 typename TChar = char, class TString = char_stringt<TChar>,
 class TImplements = exception_implementt
 <TStatus, TChar, TString>, class TExtends = exception>
class _EXPORT_CLASS create_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef TStatus status_t;
    typedef TString string_t;
    typedef TChar char_t;

    create_exceptiont(status_t status): extends(status) {
    }
    create_exceptiont(const create_exceptiont &copy): extends(copy) {
    }
    virtual ~create_exceptiont() {
    }

    virtual string_t status_to_string() const {
        return create_status_to_string(this->status());
    }
};
typedef create_exceptiont<> create_exception;

typedef implement_base creatort_implements;
///////////////////////////////////////////////////////////////////////
///  Class: creatort
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = creatort_implements>
class _EXPORT_CLASS creatort: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual bool create() {
        if ((this->destroyed())) {
            if ((this->set_is_created())) {
                return true;
            }
        }
        return false;
    }
    virtual bool destroy() {
        if ((this->is_created())) {
            this->set_is_created(false);
            if ((this->is_destroyed())) {
                return true;
            }
        }
        return false;
    }
    virtual bool destroyed() {
        if ((this->is_created())) {
            if ((this->destroy())) {
                return true;
            }
            return false;
        }
        return true;
    }

    virtual bool set_is_created(bool to = true) {
        return false;
    }
    virtual bool is_created() const {
        return false;
    }
    virtual bool is_destroyed() const {
        return true;
    }
};
typedef creatort<> creator;

typedef creator createdt_implements;
typedef base createdt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: createdt
///////////////////////////////////////////////////////////////////////
template 
<typename TAttached = pointer_t, 
 typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplement = createdt_implements, class TExtend = createdt_extends,
 class TImplements = attachert<TAttached, TUnattached, VUnattached, TImplement>, 
 class TExtends = attachedt<TAttached, TUnattached, VUnattached, TImplements, TExtend> >
class _EXPORT_CLASS createdt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    createdt(attached_t detached, bool is_created): extends(detached), is_created_(is_created) {
    }
    createdt(attached_t detached): extends(detached), is_created_(false) {
    }
    createdt(const createdt &copy): extends(copy), is_created_(copy.is_created()) {
    }
    createdt(): is_created_(false) {
    }
    virtual ~createdt() {
        if (!(this->destroyed())) {
            const create_exception e(destroy_failed);
            LOG_ERROR("...failed on this->destroyed() throw (const create_exception e(destroy_failed))...");
            throw (e);
        }
    }

    virtual bool create() {
        attached_t detached = (attached_t)(unattached);
        if (((attached_t)(unattached) != (detached = this->create_attached()))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        attached_t detached = (attached_t)(unattached);
        this->set_is_created(false);
        if (((attached_t)(unattached) != (detached = this->detach()))) {
            if ((this->destroy_detached(detached))) {
                return true;
            }
        } else {
            return true;
        }
        return false;
    }

    virtual attached_t create_attached() {
        attached_t detached = (attached_t)(unattached);
        if ((this->destroyed())) {
            if (((attached_t)(unattached) != (detached = create_detached()))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t create_detached() const {
        attached_t detached = (attached_t)(unattached);
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((attached_t)(unattached) != (detached)) {
            return true;
        }
        return false;
    }

    virtual bool set_is_created(bool to = true) {
        is_created_ = to;
        return is_created_;
    }
    virtual bool is_created() const {
        return is_created_;
    }
    virtual bool is_destroyed() const {
        return !is_created_;
    }

    virtual attached_t attach_created(attached_t detached, bool is_created = true) {
        attached_t attached = this->attach(detached);
        this->set_is_created(is_created);
        return attached;
    }
    virtual attached_t detach_created(bool& is_created) {
        attached_t detached = extends::detach();
        is_created = this->is_created();
        this->set_is_created(false);
        return detached;
    }
    virtual attached_t detach() {
        attached_t detached = extends::detach();
        this->set_is_created(false);
        return detached;
    }

protected:
    bool is_created_;
};
typedef createdt<> created;

} /// namespace xos

#endif /// _XOS_BASE_CREATED_HPP 
