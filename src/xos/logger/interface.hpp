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
///   File: interface.hpp
///
/// Author: $author$
///   Date: 4/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_INTERFACE_HPP
#define _XOS_LOGGER_INTERFACE_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace logger {

typedef implement_base interface_implementt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: interface_implementt
///////////////////////////////////////////////////////////////////////
template <class TImplements = interface_implementt_implements>
class _EXPORT_CLASS interface_implementt: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef interface_implementt<> interface_implement;

typedef interface_implement interfacet_implements;
typedef base interfacet_extends;
///////////////////////////////////////////////////////////////////////
///  Class: interfacet
///////////////////////////////////////////////////////////////////////
template <class TImplements = interfacet_implements, class TExtends = interfacet_extends>
class _EXPORT_CLASS interfacet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    interfacet(const interfacet &copy) {
    }
    interfacet() {
    }
    virtual ~interfacet() {
    }
};
typedef interfacet<> interface;

} /// namespace logger
} /// namespace xos

#endif /// _XOS_LOGGER_INTERFACE_HPP 
