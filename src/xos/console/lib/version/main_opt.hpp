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
///   Date: 8/23/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_LIB_VERSION_MAIN_OPT_HPP
#define _XOS_CONSOLE_LIB_VERSION_MAIN_OPT_HPP

#include "xos/console/getopt/main.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPT "version"
#define XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTARG_RESULT 0
#define XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTARG ""
#define XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTUSE "Framework library version"
#define XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTVAL_S "v"
#define XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTVAL_C 'v'
#define XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTION \
   {XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPT, \
    XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTARG_REQUIRED, \
    XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTARG_RESULT, \
    XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_CONSOLE_LIB_VERSION_MAIN_OPTIONS_CHARS \
   XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTVAL_S \
   XOS_CONSOLE_MAIN_OPTIONS_CHARS

#define XOS_CONSOLE_LIB_VERSION_MAIN_OPTIONS_OPTIONS \
   XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTION \
   XOS_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_CONSOLE_LIB_VERSION_MAIN_ARGS 0
#define XOS_CONSOLE_LIB_VERSION_MAIN_ARGV

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace xos {
namespace console {
namespace lib {
namespace version {

typedef getopt::main main_optt_extends;
typedef main_optt_extends::implements main_optt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: main_optt
///////////////////////////////////////////////////////////////////////
template <class TImplements = main_optt_implements, class TExtends = main_optt_extends>
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
    virtual int on_version_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
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
        case XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTVAL_C:
            err = on_version_option
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
        case XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTVAL_C:
            optarg = XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTARG;
            chars = XOS_CONSOLE_LIB_VERSION_MAIN_VERSION_OPTUSE;
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = XOS_CONSOLE_LIB_VERSION_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_CONSOLE_LIB_VERSION_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_CONSOLE_LIB_VERSION_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_CONSOLE_LIB_VERSION_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS main_optt
typedef main_optt<> main_opt;

} /// namespace version
} /// namespace lib
} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_LIB_VERSION_MAIN_OPT_HPP 
