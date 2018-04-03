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
///   File: version.cpp
///
/// Author: $author$
///   Date: 4/2/2018
///////////////////////////////////////////////////////////////////////
#include "xos/lib/nadir/version.hpp"

#if !defined(XOS_LIB_NADIR_VERSION_MAJOR)
#define XOS_LIB_NADIR_VERSION_MAJOR 0
#endif /// !defined(XOS_LIB_NADIR_VERSION_MAJOR)

#if !defined(XOS_LIB_NADIR_VERSION_MINOR)
#define XOS_LIB_NADIR_VERSION_MINOR 0
#endif /// !defined(XOS_LIB_NADIR_VERSION_MINOR)

#if !defined(XOS_LIB_NADIR_VERSION_RELEASE)
#define XOS_LIB_NADIR_VERSION_RELEASE 0
#endif /// !defined(XOS_LIB_NADIR_VERSION_RELEASE)

namespace xos {
namespace lib {
namespace nadir {

///////////////////////////////////////////////////////////////////////
///  Class: version
///////////////////////////////////////////////////////////////////////
unsigned version::major() {
    return XOS_LIB_NADIR_VERSION_MAJOR;
}
unsigned version::minor() {
    return XOS_LIB_NADIR_VERSION_MINOR;
}
unsigned version::release() {
    return XOS_LIB_NADIR_VERSION_RELEASE;
}

} /// namespace nadir
} /// namespace lib
} /// namespace xos
