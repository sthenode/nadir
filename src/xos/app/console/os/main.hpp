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
///   Date: 8/21/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_OS_MAIN_HPP
#define _XOS_APP_CONSOLE_OS_MAIN_HPP

#include "xos/app/console/os/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace os {

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TLibVersion = xos::lib::nadir::version,
 class TExtends = main_optt<TLibVersion>, 
 class TImplements = typename TExtends::implements>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint(): run_(0), windows_run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        if ((run_)) {
            return (this->*run_)(argc, argv, env);
        }
        return default_run(argc, argv, env);
    }
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        return this->os_run(argc, argv, env);
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (derives::*windows_run_)(int argc, char_t** argv, char_t** env);
    virtual int windows_run(int argc, char_t** argv, char_t** env) {
        if ((windows_run_)) {
            return (this->*windows_run_)(argc, argv, env);
        }
        return default_windows_run(argc, argv, env);
    }
    virtual int default_windows_run(int argc, char_t** argv, char_t** env) {
        return this->native_windows_run(argc, argv, env);
    }
    virtual int native_windows_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int crt_windows_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int osx_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int linux_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int posix_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int solaris_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int os_run(int argc, char_t** argv, char_t** env) {
        int err = this->derived_run(argc, argv, env);
        return err;
    }
    virtual int derived_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int this_version_run(int argc, char_t** argv, char_t** env) {
        int err = this->version_run(argc, argv, env);
        return err;
    }
    virtual int set_version_run(int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::this_version_run;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int set_posix_run(int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::posix_run;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_windows_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::windows_run;
        return err;
    }
    virtual int on_osx_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::osx_run;
        return err;
    }
    virtual int on_linux_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::linux_run;
        return err;
    }
    virtual int on_posix_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_posix_run(argc, argv, env);
        return err;
    }
    virtual int on_solaris_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        run_ = &derives::solaris_run;
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_native_runtime_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        windows_run_ = &derives::native_windows_run;
        return err;
    }
    virtual int on_clib_runtime_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        windows_run_ = &derives::crt_windows_run;
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS maint
typedef maint<> main;

} /// namespace os
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_OS_MAIN_HPP 
