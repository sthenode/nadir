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
#ifndef _XOS_CONSOLE_INPUT_HPP
#define _XOS_CONSOLE_INPUT_HPP

#include "xos/base/locked.hpp"

namespace xos {
namespace console {

typedef unlocked input_baset_implements;
///////////////////////////////////////////////////////////////////////
///  Class: input_baset
///////////////////////////////////////////////////////////////////////
template 
<typename TChar = char, typename TEndChar = TChar, TEndChar VEndChar = 0,
 typename TFile = FILE*, typename TNullFile = int, TNullFile VNullFile = 0,
 class TString = char_stringt<TChar, TEndChar, VEndChar>,
 class TImplements = input_baset_implements>
class _EXPORT_CLASS input_baset: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef TString string_t;
    typedef TFile file_t;
    typedef TNullFile null_file_t;
    enum { null_file = VNullFile };
    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };

protected:
    virtual ssize_t inln(file_t f, char_t* in, size_t size) const {
        const char_t eol = ((char_t)'\n');
        ssize_t count = this->inln(f, in, size, eol);
        return count;
    }
    virtual ssize_t inln(file_t f, char_t* in, size_t size, const char_t& eol) const {
        ssize_t count = 0;
        if ((in) && (size) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            for (size_t length = size; length; --length, ++in) {
                if (0 < (amount = this->in(f, in, 1))) {
                    if (eol != *in) {
                        count += amount;
                        continue;
                    }
                }
                break;
            }
        }
        return count;
    }
    virtual ssize_t inln(file_t f) const {
        const char_t eol = ((char_t)'\n');
        ssize_t count = this->inln(f, eol);
        return count;
    }
    virtual ssize_t inln(file_t f, const char_t& eol) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file))) {
            char_t in = 0;
            ssize_t amount = 0;
            while (0 < (amount = this->in(f, &in, 1))) {
                if (eol != in) {
                    count += amount;
                    continue;
                }
                break;
            }
        }
        return count;
    }
    virtual ssize_t in(file_t f, char_t* in, size_t size) const {
        ssize_t count = 0;
        if ((in) && (size) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (amount = this->in(f, in, sizeof(char_t), size))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t infv(file_t f, const char_t* format, va_list va) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file)) && (format)) {
            /*count = ::vfscanf(f, format, va);*/
        }
        return count;
    }
    virtual ssize_t in(file_t f, char_t* in, size_t size, size_t space) const {
        ssize_t count = 0;
        if ((in) && (size) && (space) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (amount /*= ::fread(in, size, space, f)*/)) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t in_fill(file_t f) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file))) {
            int err = 0;
            if ((err /*= ::ffill(f)*/)) {
                count = -1;
            }
        }
        return count;
    }
};
typedef input_baset<> input_base;

typedef input_base::implements inputt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: inputt
///////////////////////////////////////////////////////////////////////
template 
<typename TChar = char, typename TEndChar = TChar, TEndChar VEndChar = 0,
 typename TFile = FILE*, typename TNullFile = int, TNullFile VNullFile = 0,
 class TString = char_stringt<TChar, TEndChar, VEndChar>,
 class TImplement = inputt_implements,
 class TImplements = input_baset
 <TChar, TEndChar, VEndChar, TFile, TNullFile, VNullFile, TString, TImplement> >
class _EXPORT_CLASS inputt: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef TString string_t;
    typedef TFile file_t;
    typedef TNullFile null_file_t;
    enum { null_file = VNullFile };
    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };

    virtual ssize_t inf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        if ((format)) {
            va_start(va, format);
            count = this->infv(format, va);
            va_end(va);
        }
        return count;
    }

protected:
    using implements::infv;
    using implements::inln;
    using implements::in;
    using implements::in_fill;
    virtual ssize_t infv(const char_t* format, va_list va) {
        ssize_t count = infv(this->in_std_in(), format, va);
        return count;
    }
    virtual ssize_t inln(char_t* in, size_t size, const char_t& eol) {
        ssize_t count = this->inln(this->in_std_in(), in, size, eol);
        return count;
    }
    virtual ssize_t inln(char_t* in, size_t size) {
        ssize_t count = this->inln(this->in_std_in(), in, size);
        return count;
    }
    virtual ssize_t inln(const char_t& eol) {
        ssize_t count = this->inln(this->in_std_in(), eol);
        return count;
    }
    virtual ssize_t inln() {
        ssize_t count = this->inln(this->in_std_in());
        return count;
    }
    virtual ssize_t in(char_t* in, size_t size) {
        ssize_t count = this->in(this->in_std_in(), in, size);
        return count;
    }
    virtual ssize_t in_fill() {
        ssize_t count = this->in_fill(this->in_std_in());
        return count;
    }

    virtual file_t in_std_in() {
        return this->std_in();
    }
    virtual file_t std_in() const {
        return ((file_t)null_file);/*::stdin;*/
    }
};
typedef inputt<char> input;

} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_INPUT_HPP 
