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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 4/7/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_GETOPT_MAIN_OPT_HPP
#define _XOS_CONSOLE_GETOPT_MAIN_OPT_HPP

#include "xos/console/main.hpp"
#include <getopt.h>

enum {
    XOS_CONSOLE_MAIN_OPT_ARGUMENT_NONE     = 0,
    XOS_CONSOLE_MAIN_OPT_ARGUMENT_REQUIRED = 1,
    XOS_CONSOLE_MAIN_OPT_ARGUMENT_OPTIONAL = 2
};
#define XOS_CONSOLE_MAIN_INVALID_OPTVAL_C '?'

#define XOS_CONSOLE_MAIN_HELP_OPT "help"
#define XOS_CONSOLE_MAIN_HELP_OPTARG_REQUIRED XOS_CONSOLE_MAIN_OPT_ARGUMENT_NONE
#define XOS_CONSOLE_MAIN_HELP_OPTARG_RESULT 0
#define XOS_CONSOLE_MAIN_HELP_OPTARG ""
#define XOS_CONSOLE_MAIN_HELP_OPTUSE "Usage options"
#define XOS_CONSOLE_MAIN_HELP_OPTVAL_S "h"
#define XOS_CONSOLE_MAIN_HELP_OPTVAL_C 'h'
#define XOS_CONSOLE_MAIN_HELP_OPTION \
   {XOS_CONSOLE_MAIN_HELP_OPT, \
    XOS_CONSOLE_MAIN_HELP_OPTARG_REQUIRED, \
    XOS_CONSOLE_MAIN_HELP_OPTARG_RESULT, \
    XOS_CONSOLE_MAIN_HELP_OPTVAL_C}, \

#define XOS_CONSOLE_MAIN_USAGE_OPT "usage"
#define XOS_CONSOLE_MAIN_USAGE_OPTARG_REQUIRED XOS_CONSOLE_MAIN_HELP_OPTARG_REQUIRED
#define XOS_CONSOLE_MAIN_USAGE_OPTARG_RESULT XOS_CONSOLE_MAIN_HELP_OPTARG_RESULT
#define XOS_CONSOLE_MAIN_USAGE_OPTARG XOS_CONSOLE_MAIN_HELP_OPTARG
#define XOS_CONSOLE_MAIN_USAGE_OPTUSE XOS_CONSOLE_MAIN_HELP_OPTUSE
#define XOS_CONSOLE_MAIN_USAGE_OPTVAL_S "u"
#define XOS_CONSOLE_MAIN_USAGE_OPTVAL_C 'u'
#define XOS_CONSOLE_MAIN_USAGE_OPTION \
   {XOS_CONSOLE_MAIN_USAGE_OPT, \
    XOS_CONSOLE_MAIN_USAGE_OPTARG_REQUIRED, \
    XOS_CONSOLE_MAIN_USAGE_OPTARG_RESULT, \
    XOS_CONSOLE_MAIN_USAGE_OPTVAL_C}, \

#define XOS_CONSOLE_MAIN_OPTIONS_CHARS \
    XOS_CONSOLE_MAIN_HELP_OPTVAL_S

#define XOS_CONSOLE_MAIN_OPTIONS_OPTIONS \
    XOS_CONSOLE_MAIN_HELP_OPTION

#define NADIR_CONSOLE_MAIN_OPTIONS_CHARS XOS_CONSOLE_MAIN_OPTIONS_CHARS
#define NADIR_CONSOLE_MAIN_OPTIONS_OPTIONS XOS_CONSOLE_MAIN_OPTIONS_OPTIONS

namespace xos {

enum {
    MAIN_OPT_ARGUMENT_NONE     = XOS_CONSOLE_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = XOS_CONSOLE_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = XOS_CONSOLE_MAIN_OPT_ARGUMENT_OPTIONAL
};

namespace console {
namespace getopt {

typedef console::main::implements main_opt_baset_implements;
typedef console::main main_opt_baset_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_opt_baset
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = main_opt_baset_implements, class TExtends = main_opt_baset_extends>
class _EXPORT_CLASS main_opt_baset: virtual public TImplements,  public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file};

    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    static const char_t fs_path_colon_ = ((char_t)':');
    static const char_t fs_path_bslash_ = ((char_t)'\\');
    static const char_t fs_path_slash_ = ((char_t)'/');

protected:
    virtual int usage(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(this->did_usage())) {
            const char_t* arg = 0;
            const char_t** args = 0;
            const char_t* argstring = this->arguments(args);
            const struct option* longopts = 0;
            const char_t* optstring = options(longopts);
            const char_t* name = usage_name(argc, argv, env);

            this->outl
            ("Usage: ", (name)?(name):(""),(optstring)?(" [options]"):(""),
             (argstring)?(" "):(""), (argstring)?(argstring):(""), "\n", NULL);

            if ((optstring) && (longopts)) {
                this->out("\nOptions:\n");

                while ((longopts->name)) {
                    const char_t* optarg =
                    (MAIN_OPT_ARGUMENT_REQUIRED == longopts->has_arg)?(" arg"):
                    ((MAIN_OPT_ARGUMENT_OPTIONAL == longopts->has_arg)?(" [arg]"):(""));
                    const char_t* optusage = option_usage(optarg, longopts);
                    const char_t* optarg_separator = (optarg[0])?(" "):("");
                    const char_t* optusage_separator = "  ";
                    const char_t* optarg_name = longopts->name;
                    const char optarg_value[2] = {((char)(longopts->val)), 0};

                    this->outl
                    (" -", optarg_value, " --", optarg_name,
                     optarg_separator, optarg, optusage_separator, optusage, "\n", NULL);
                    longopts++;
                }
            }
            if ((argstring) && (args)) {
                this->out("\nArguments:\n");

                while ((arg = (*args))) {
                    this->outl(" ", arg, "\n", NULL);
                    args++;
                }
            }
            this->set_did_usage();
        }
        return err;
    }
    virtual const char_t* usage_name
    (int argc, char_t** argv, char_t** env) const {
        const char_t* arg0 = (0 < argc)?((argv)?(argv[0]):(0)):(0);
        if ((arg0)) {
            for (const char_t* i = arg0; *i; ++i) {
                char c = (char)(*i);
                if ((fs_path_slash_ == c)
                    || (fs_path_bslash_ == c)
                    || (fs_path_colon_ == c)) {
                    arg0 = i + 1;
                }
            }
        }
        return arg0;
    }

    virtual int get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        int longindex = 0;
        const struct option* longopts = 0;
        char_t optvaluename[2] = {0,0};
        const char_t* optname = optvaluename;
        const char_t* optstring = 0;
        int optvalue = 0;

        if ((optstring = options(longopts)) && (longopts)) {
            opterr = 0;
            optopt = 0;
            while (0 <= (optvalue = getopt_long(argc, argv, optstring, longopts, &longindex))) {
                optvaluename[0] = optvalue;
                optname = (longindex)?(longopts[longindex].name):(optvaluename);

                if (!(err = before_on_option(optvalue, optarg, optname, longindex, argc, argv, env))) {
                    int err2 = 0;
                    err = on_option(optvalue, optarg, optname, longindex, argc, argv, env);
                    if ((err2 = after_on_option(optvalue, optarg, optname, longindex, argc, argv, env))) {
                        if (!err) err = err2;
                    }
                }
                if (err) {
                    break;
                }
            }
        }
        return err;
    }
    virtual int before_get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_options(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    virtual int on_invalid_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 1;
        char_t optval_chars[2] = {((char_t)optval), 0};
        this->errl
        ("Invalid option -", optval_chars, " --", optname, "\n", NULL);
        return err;
    }
    virtual int on_invalid_option_arg
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 1;
        this->errl
        ("invalid argument \"", optarg,
         "\" for option \"", optname, "\"\n", NULL);
        return err;
    }
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        default:
            err = on_invalid_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual int before_on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_CONSOLE_MAIN_INVALID_OPTVAL_C:
            if (!opterr) {
                const char_t* arg = argv[optind+1];
                int optchar = (arg[1]!='-')?(arg[1]):(arg[2]);
                const char_t* optchars = (arg[1]!='-')?(arg+1):(arg+2);
                err = on_invalid_option
                (optchar, optarg, optchars, optind, argc, argv, env);
            }
        break;
        }
        return err;
    }
    virtual int after_on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        default:
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = 0;
        static struct option optstruct[]= {
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    
    virtual int get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (argc > (optind)) {
            for (int argind = optind; argind < argc; ++argind) {
                if ((err = this->on_argument(argv[argind], argind-optind, argc, argv, env))) {
                    break;
                }
            }
        }
        return err;
    }
    virtual int before_get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->before_get_options(argc, argv, env))) {
            int err2 = 0;
            err = this->get_options(argc, argv, env);
            if ((err2 = this->after_get_options(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    virtual int after_get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int missing_argument(const char_t* arg) {
        int err = 1;
        this->errl("missing argument \"", arg, "\"", NULL);
        return err;
    }
    virtual const char_t* arguments(const char_t**& args) {
        args = 0;
        return 0;
    }
};
typedef main_opt_baset<> main_opt_base;

typedef main_opt_base::implements main_optt_implements;
typedef main_opt_base main_optt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_optt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = main_optt_implements, class TExtends = main_optt_extends>
class _EXPORT_CLASS main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file};

    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    virtual int on_usage_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }
    virtual const char_t* usage_option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        chars = XOS_CONSOLE_MAIN_HELP_OPTUSE;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_CONSOLE_MAIN_HELP_OPTVAL_C:
            err = this->on_usage_option
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
        case XOS_CONSOLE_MAIN_HELP_OPTVAL_C:
            chars = this->usage_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = NADIR_CONSOLE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            NADIR_CONSOLE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    virtual const char_t* arguments(const char_t**& args) {
        args = 0;
        return 0;
    }
};
typedef main_optt<> main_opt;

} /// namespace getopt
} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_GETOPT_MAIN_OPT_HPP 
