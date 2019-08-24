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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 8/21/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_OS_MAIN_OPT_HPP
#define _XOS_APP_CONSOLE_OS_MAIN_OPT_HPP

#include "xos/app/console/main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPT "os"
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_WINDOWS_C "w" 
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_WINDOWS_S "windows" 
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_MACOSX_C "x" 
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_MACOSX_S "osx" 
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_LINUX_C "l" 
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_LINUX_S "linux" 
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_POSIX_C "p" 
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_POSIX_S "posix" 
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_SOLARIS_C "s" 
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_SOLARIS_S "solaris" 
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG \
    "{ " "(" XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_WINDOWS_C ")" XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_WINDOWS_S \
    " | " "(" XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_MACOSX_C ")" XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_MACOSX_S \
    " | " "(" XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_LINUX_C ")" XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_LINUX_S \
    " | " "(" XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_POSIX_C ")" XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_POSIX_S \
    " | " "(" XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_SOLARIS_C ")" XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_SOLARIS_S \
    " }" 
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTUSE ""
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTVAL_S "o:"
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTVAL_C 'o'
#define XOS_APP_CONSOLE_OS_MAIN_OS_OPTION \
   {XOS_APP_CONSOLE_OS_MAIN_OS_OPT, \
    XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_RESULT, \
    XOS_APP_CONSOLE_OS_MAIN_OS_OPTVAL_C}, \

#define XOS_APP_CONSOLE_OS_MAIN_RT_OPT "rt"
#define XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_NATIVE_C "n" 
#define XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_NATIVE_S "native" 
#define XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_CLIB_C "c" 
#define XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_CLIB_S "clib" 
#define XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG \
    "{ " "(" XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_NATIVE_C ")" XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_NATIVE_S \
    " | " "(" XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_CLIB_C ")" XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_CLIB_S \
    " }" 
#define XOS_APP_CONSOLE_OS_MAIN_RT_OPTUSE ""
#define XOS_APP_CONSOLE_OS_MAIN_RT_OPTVAL_S "r:"
#define XOS_APP_CONSOLE_OS_MAIN_RT_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_OS_MAIN_RT_OPTION \
   {XOS_APP_CONSOLE_OS_MAIN_RT_OPT, \
    XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_OS_MAIN_RT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_OS_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_OS_MAIN_OS_OPTVAL_S \
   XOS_APP_CONSOLE_OS_MAIN_RT_OPTVAL_S \
   XOS_APP_CONSOLE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_OS_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_OS_MAIN_OS_OPTION \
   XOS_APP_CONSOLE_OS_MAIN_RT_OPTION \
   XOS_APP_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_OS_MAIN_ARGS 0
#define XOS_APP_CONSOLE_OS_MAIN_ARGV

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace xos {
namespace app {
namespace console {
namespace os {

///////////////////////////////////////////////////////////////////////
///  Class: main_optt
///////////////////////////////////////////////////////////////////////
template 
<class TLibVersion = xos::lib::nadir::version,
 class TExtends = xos::app::console::maint<TLibVersion>, 
 class TImplements = typename TExtends::implements>

class _EXPORT_CLASS main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main_optt() {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
    }
    
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_windows_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_osx_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_linux_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_posix_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_solaris_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_native_runtime_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_clib_runtime_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_os_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            if ((!arg.compare(XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_WINDOWS_C)) 
                || (!arg.compare(XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_WINDOWS_S))) {
                err = on_windows_option
                (optval, optarg, optname, optind, argc, argv, env);
            } else {
                if ((!arg.compare(XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_MACOSX_C)) 
                    || (!arg.compare(XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_MACOSX_S))) {
                    err = on_osx_option
                    (optval, optarg, optname, optind, argc, argv, env);
                } else {
                    if ((!arg.compare(XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_LINUX_C)) 
                        || (!arg.compare(XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_LINUX_S))) {
                        err = on_linux_option
                        (optval, optarg, optname, optind, argc, argv, env);
                    } else {
                        if ((!arg.compare(XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_POSIX_C)) 
                            || (!arg.compare(XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_POSIX_S))) {
                            err = on_posix_option
                            (optval, optarg, optname, optind, argc, argv, env);
                        } else {
                            if ((!arg.compare(XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_SOLARIS_C)) 
                                || (!arg.compare(XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG_SOLARIS_S))) {
                                err = on_solaris_option
                                (optval, optarg, optname, optind, argc, argv, env);
                            } else {
                                err = extends::on_invalid_option_arg
                                (optval, optarg, optname, optind, argc, argv, env);
                            }
                        }
                    }
                }
            }
        }
        return err;
    }
    virtual int on_rt_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            if ((!arg.compare(XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_NATIVE_C)) 
                || (!arg.compare(XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_NATIVE_S))) {
                err = on_native_runtime_option
                (optval, optarg, optname, optind, argc, argv, env);
            } else {
                if ((!arg.compare(XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_CLIB_C)) 
                    || (!arg.compare(XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG_CLIB_S))) {
                    err = on_clib_runtime_option
                    (optval, optarg, optname, optind, argc, argv, env);
                } else {
                    err = extends::on_invalid_option_arg
                    (optval, optarg, optname, optind, argc, argv, env);
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_OS_MAIN_OS_OPTVAL_C:
            err = on_os_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_OS_MAIN_RT_OPTVAL_C:
            err = on_rt_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_OS_MAIN_OS_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_OS_MAIN_OS_OPTARG;
            chars = XOS_APP_CONSOLE_OS_MAIN_OS_OPTUSE;
            break;
        case XOS_APP_CONSOLE_OS_MAIN_RT_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_OS_MAIN_RT_OPTARG;
            chars = XOS_APP_CONSOLE_OS_MAIN_RT_OPTUSE;
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = XOS_APP_CONSOLE_OS_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_OS_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_OS_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_OS_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS main_optt
typedef main_optt<> main_opt;

} /// namespace os
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_OS_MAIN_OPT_HPP 
