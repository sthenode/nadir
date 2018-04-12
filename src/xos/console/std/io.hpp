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
///   File: io.hpp
///
/// Author: $author$
///   Date: 4/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_STD_IO_HPP
#define _XOS_CONSOLE_STD_IO_HPP

#include "xos/console/io.hpp"
#include "xos/console/std/input.hpp"
#include "xos/console/std/output.hpp"
#include "xos/console/std/error.hpp"

namespace xos {
namespace console {
namespace std {

typedef console::io iot_implements;
typedef input iot_in_implements;
typedef output iot_out_implements;
typedef error iot_err_implements;
///////////////////////////////////////////////////////////////////////
///  Class: iot
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = iot_implements,
 class TInImplements = iot_in_implements,
 class TOutImplements = iot_out_implements,
 class TErrImplements = iot_err_implements>
class _EXPORT_CLASS iot
: virtual public TImplements,
  virtual public TInImplements,
  virtual public TOutImplements,
  virtual public TErrImplements {
public:
    typedef TImplements implements;
    typedef TInImplements in_implements;
    typedef TOutImplements out_implements;
    typedef TErrImplements err_implements;

    typedef typename out_implements::string_t string_t;
    typedef typename out_implements::file_t file_t;
    typedef typename out_implements::null_file_t null_file_t;
    enum { null_file = out_implements::null_file};
    typedef typename out_implements::char_t char_t;
    typedef typename out_implements::end_char_t end_char_t;
    enum { end_char = out_implements::end_char };
};
typedef iot<> io;

namespace derived {

typedef std::io iot_implements;
typedef base iot_extends;
///////////////////////////////////////////////////////////////////////
///  Class: iot
///////////////////////////////////////////////////////////////////////
template <class TImplements = iot_implements, class TExtends = iot_extends>
class _EXPORT_CLASS iot: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    iot(locked& _locked): locked_(_locked) {
    }
    virtual ~iot() {
    }
private:
    iot(const iot &copy) {
    }
    
protected:
    virtual bool lock() { 
        return locked_.lock(); 
    }
    virtual lock_status try_lock() { 
        return locked_.try_lock(); 
    }
    virtual lock_status untimed_lock() { 
        return locked_.untimed_lock(); 
    }
    virtual lock_status timed_lock(mseconds_t milliseconds) { 
        return locked_.timed_lock(milliseconds); 
    }
    virtual bool unlock() { 
        return locked_.unlock(); 
    }

protected:
    locked& locked_;
};
typedef iot<> io;

} /// namespace derived

} /// namespace std
} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_STD_IO_HPP 
        

