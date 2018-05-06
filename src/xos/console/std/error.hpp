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
///   File: error.hpp
///
/// Author: $author$
///   Date: 4/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_STD_ERROR_HPP
#define _XOS_CONSOLE_STD_ERROR_HPP

#include "xos/console/error.hpp"

namespace xos {
namespace console {
namespace std {

typedef console::error errort_implements;
///////////////////////////////////////////////////////////////////////
///  Class: errort
///////////////////////////////////////////////////////////////////////
template <class TImplements = errort_implements>
class _EXPORT_CLASS errort: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef typename implements::string_t string_t;
    typedef typename implements::file_t file_t;
    typedef typename implements::null_file_t null_file_t;
    enum { null_file = implements::null_file};

    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

protected:
    using implements::err;
    using implements::err_flush;
    virtual ssize_t err(file_t f, const char_t* out, size_t size, size_t length) const {
        ssize_t count = 0;
        if ((out) && (size) && (length) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (amount = ::fwrite(out, size, length, f))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t err_flush(file_t f) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file))) {
            int err = 0;
            if ((err = ::fflush(f))) {
                count = -1;
            }
        }
        return count;
    }
    virtual file_t std_err() const {
        return ::stderr;
    }
};

typedef errort<> error_implements;
class _EXPORT_CLASS error: virtual public error_implements {
protected:
    typedef error_implements implements;
    
    using implements::errfv;
    virtual ssize_t errfv(file_t f, const char_t* format, va_list va) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file)) && (format)) {
            count = ::vfprintf(f, format, va);
        }
        return count;
    }
};

} /// namespace std
} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_STD_ERROR_HPP 
        

