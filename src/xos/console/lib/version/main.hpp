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
///   Date: 1/31/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_LIB_VERSION_MAIN_HPP
#define _XOS_CONSOLE_LIB_VERSION_MAIN_HPP

#include "xos/console/lib/version/main_opt.hpp"
#include "xos/lib/nadir/version.hpp"

namespace xos {
namespace console {
namespace lib {
namespace version {

typedef main_opt maint_extends;
typedef maint_extends::implements maint_implements;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TLibVersion = xos::lib::nadir::version,
 class TImplements = maint_implements, class TExtends = maint_extends>
class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef TLibVersion lib_version_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint(): run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (run_) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = this->version_run(argc, argv, env);
        }
        return err;
    }
    virtual int version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::lib::version& which_version = lib_version_t::which();
        const string_t version = which_version.to_string();
        const char_t* name = which_version.name();
        this->outlln("library ", name, " version = ", version.chars(), NULL);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_version_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::version_run;
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS maint
typedef maint<> main;

} /// namespace version
} /// namespace lib
} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_LIB_VERSION_MAIN_HPP 
