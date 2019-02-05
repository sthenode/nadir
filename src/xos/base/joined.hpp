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
///   File: joined.hpp
///
/// Author: $author$
///   Date: 2/2/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_JOINED_HPP
#define _XOS_BASE_JOINED_HPP

#include "xos/base/exception.hpp"

namespace xos {

typedef int join_status;
enum {
    fork_success,
    join_success = fork_success,

    join_failed,
    join_busy,
    join_interrupted,
    join_invalid,

    fork_failed,
    fork_busy,
    fork_interrupted,
    fork_invalid
};

template <class TString>
inline TString join_status_to_string(join_status status) {
    switch (status) {
    case join_success: return TString("join_success");
    case join_failed: return TString("join_failed");
    case join_busy: return TString("join_busy");
    case join_interrupted: return TString("join_interrupted");
    case join_invalid: return TString("join_invalid");

    case fork_failed: return TString("fork_failed");
    case fork_busy: return TString("fork_busy");
    case fork_interrupted: return TString("fork_interrupted");
    case fork_invalid: return TString("fork_invalid");
    }
    return TString("unknown");
}

///////////////////////////////////////////////////////////////////////
///  Class: join_exceptiont
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = exception_implementt<join_status, char, char_string>, 
 class TExtends = exceptiont<join_status, char, char_string, TImplements> >
class _EXPORT_CLASS join_exceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    
    typedef typename implements::status_t status_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    join_exceptiont(status_t status): extends(status) {
    }
    join_exceptiont(const join_exceptiont &copy): extends(copy) {
    }
    virtual ~join_exceptiont() {
    }

    virtual string_t status_to_string() const {
        return join_status_to_string<string_t>(this->status());
    }
};
typedef join_exceptiont<> join_exception;

typedef implement_base joinedt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: joinedt
///////////////////////////////////////////////////////////////////////
template <class TImplements = joinedt_implements>
class _EXPORT_CLASS joinedt: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual bool joined() {
        if ((this->is_forked())) {
            return this->join();
        }
        return true;
    }
    virtual bool join() {
        return false;
    }
    virtual join_status untimed_join() {
        return join_failed;
    }
    virtual join_status timed_join(mseconds_t milliseconds) {
        return join_failed;
    }
    virtual join_status try_join() {
        return join_failed;
    }

    virtual bool set_is_forked(bool to = true) {
        return false;
    }
    virtual bool is_forked() const {
        return false;
    }
};
typedef joinedt<> joined;

} /// namespace xos

#endif /// _XOS_BASE_JOINED_HPP 
