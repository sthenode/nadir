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
///   File: function.hpp
///
/// Author: $author$
///   Date: 4/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_FUNCTION_HPP
#define _XOS_LOGGER_FUNCTION_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace logger {

typedef implement_base function_implementt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: function_implementt
///////////////////////////////////////////////////////////////////////
template <class TImplements = function_implementt_implements>
class _EXPORT_CLASS function_implementt: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef function_implementt<> function_implement;

typedef function_implement functiont_implements;
typedef base functiont_extends;
///////////////////////////////////////////////////////////////////////
///  Class: functiont
///////////////////////////////////////////////////////////////////////
template <class TImplements = functiont_implements, class TExtends = functiont_extends>
class _EXPORT_CLASS functiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    functiont(const functiont &copy) {
    }
    functiont() {
    }
    virtual ~functiont() {
    }
};
typedef functiont<> function;

} /// namespace logger
} /// namespace xos

#endif /// _XOS_LOGGER_FUNCTION_HPP 
        

