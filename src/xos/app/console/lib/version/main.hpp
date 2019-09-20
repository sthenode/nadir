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
///   File: main.hpp
///
/// Author: $author$
///   Date: 9/20/2019
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_LIB_VERSION_MAIN_HPP
#define XOS_APP_CONSOLE_LIB_VERSION_MAIN_HPP

#include "xos/app/console/lib/version/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace lib {
namespace version {

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TVersion = xos::lib::nadir::version, 
 class TExtends = main_optt<TVersion>, 
 class TImplements = typename TExtends::implements>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename implements::file_t file_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    protected:
}; /// class _EXPORT_CLASS maint

typedef maint<> main;


} /// namespace version
} /// namespace lib
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_LIB_VERSION_MAIN_HPP
