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
///   File: main.hpp
///
/// Author: $author$
///   Date: 4/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_MAIN_HPP
#define _XOS_CONSOLE_MAIN_HPP

#include "xos/console/std/io.hpp"

namespace xos {
namespace console {

typedef std::io main_implementt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: main_implementt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = main_implementt_implements>
class _EXPORT_CLASS main_implementt: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file};

    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

protected:
};
typedef main_implementt<> main_implement;

typedef main_implement maint_implements;
typedef base maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template <class TImplements = maint_implements, class TExtends = maint_extends>
class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file};

    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    maint(): did_run_(false), did_usage_(false) {
        derives*& the_main = derives::the_main();
        if (!(the_main)) {
            the_main = this;
        }
    }
    virtual ~maint() {
        derives*& the_main = derives::the_main();
        if ((the_main) && (this == the_main)) {
            the_main = 0;
        }
    }
private:
    maint(const maint &copy): did_run_(false), did_usage_(false) {
    }

public:
    virtual ssize_t write_out(const char_t* chars, ssize_t size) {
        ssize_t count = 0, amount = 0;
        if (0 < (amount = this->out(chars, size))) {
            this->out_flush();
            count += amount;
        }
        return count;
    }

public:
    static int the_main(int argc, char_t** argv, char_t** env) {
        int err = 1;
        derives* the_main = 0;
        if ((the_main = derives::the_main())) {
            if (!(err = the_main->before(argc, argv, env))) {
                int err2 = 0;
                err = (*the_main)(argc, argv, env);
                if ((err2 = the_main->after(argc, argv, env))) {
                    if (!err) err = err2;
                }
            }
        }
        return err;
    }
protected:
    static derives*& the_main() {
        static derives* the_main = 0;
        return the_main;
    }
    
protected:
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual bool set_did_run(bool to = true) {
        did_run_ = to;
        return did_run_;
    }
    virtual bool did_run() const {
        return did_run_;
    }

    virtual int usage(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->set_did_usage();
        return err;
    }
    virtual bool set_did_usage(bool to = true) {
        did_run_ = did_usage_ = to;
        return did_usage_;
    }
    virtual bool did_usage() const {
        return did_usage_;
    }

    virtual int get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_arguments(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_argument
    (const char_t* arg, int argind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int missing_argument(const char_t* arg) {
        int err = 1;
        return err;
    }
    virtual const char_t* arguments(const char_t**& args) {
        args = 0;
        return 0;
    }
    
    virtual int operator()(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(this->did_run())) {
            if (!(err = this->before_run(argc, argv, env))) {
                int err2 = 0;
                err = this->run(argc, argv, env);
                if ((err2 = this->after_run(argc, argv, env))) {
                    if (!err) err = err2;
                }
            }
        }
        return err;
    }
    virtual int before(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->before_get_arguments(argc, argv, env))) {
            int err2 = 0;
            err = this->get_arguments(argc, argv, env);
            if ((err2 = this->after_get_arguments(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    virtual int after(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
protected:
    bool did_run_, did_usage_;
};
typedef maint<> main;

} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_MAIN_HPP 
