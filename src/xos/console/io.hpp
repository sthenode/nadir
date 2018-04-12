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
#ifndef _XOS_CONSOLE_IO_HPP
#define _XOS_CONSOLE_IO_HPP

#include "xos/console/input.hpp"
#include "xos/console/output.hpp"
#include "xos/console/error.hpp"

namespace xos {
namespace console {

typedef unlocked iot_implements;
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

} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_IO_HPP 
        

