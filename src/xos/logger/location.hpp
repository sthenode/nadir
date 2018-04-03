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
///   File: location.hpp
///
/// Author: $author$
///   Date: 4/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_LOCATION_HPP
#define _XOS_LOGGER_LOCATION_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace logger {

typedef implement_base location_implementt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: location_implementt
///////////////////////////////////////////////////////////////////////
template <class TImplements = location_implementt_implements>
class _EXPORT_CLASS location_implementt: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef location_implementt<> location_implement;

typedef location_implement locationt_implements;
typedef base locationt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: locationt
///////////////////////////////////////////////////////////////////////
template <class TImplements = locationt_implements, class TExtends = locationt_extends>
class _EXPORT_CLASS locationt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    locationt(const locationt &copy) {
    }
    locationt() {
    }
    virtual ~locationt() {
    }
};
typedef locationt<> location;

} /// namespace logger
} /// namespace xos

#endif /// _XOS_LOGGER_LOCATION_HPP 
        

