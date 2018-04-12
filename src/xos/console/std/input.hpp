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
///   File: input.hpp
///
/// Author: $author$
///   Date: 4/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_STD_INPUT_HPP
#define _XOS_CONSOLE_STD_INPUT_HPP

#include "xos/console/input.hpp"

namespace xos {
namespace console {
namespace std {

typedef console::input inputt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: inputt
///////////////////////////////////////////////////////////////////////
template <class TImplements = inputt_implements>
class _EXPORT_CLASS inputt: virtual public TImplements {
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
    using implements::in;
    using implements::in_fill;
    virtual ssize_t in(file_t f, char_t* in, size_t size, size_t space) const {
        ssize_t count = 0;
        if ((in) && (size) && (space) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (amount = ::fread(in, size, space, f))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t in_fill(file_t f) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file))) {
            int err = 0;
            if ((err)) {
                count = -1;
            }
        }
        return count;
    }
    virtual file_t std_in() const {
        return ::stdin;
    }
};

typedef inputt<> input_implements;
class _EXPORT_CLASS input: virtual public input_implements {
protected:
    typedef input_implements implements;
    using implements::infv;
    virtual ssize_t infv(file_t f, const char_t* format, va_list va) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file)) && (format)) {
            count = ::vfscanf(f, format, va);
        }
        return count;
    }
};

} /// namespace std
} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_STD_INPUT_HPP 
        

