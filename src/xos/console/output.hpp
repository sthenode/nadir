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
///   File: output.hpp
///
/// Author: $author$
///   Date: 4/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_OUTPUT_HPP
#define _XOS_CONSOLE_OUTPUT_HPP

#include "xos/base/locked.hpp"

namespace xos {
namespace console {

typedef unlocked output_baset_implements;
///////////////////////////////////////////////////////////////////////
///  Class: output_baset
///////////////////////////////////////////////////////////////////////
template 
<typename TChar = char, typename TEndChar = TChar, TEndChar VEndChar = 0,
 typename TFile = FILE*, typename TNullFile = int, TNullFile VNullFile = 0,
 class TString = char_stringt<TChar, TEndChar, VEndChar>,
 class TImplements = output_baset_implements>
class _EXPORT_CLASS output_baset: virtual public TImplements {
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
    virtual ssize_t outlv(file_t f, const char_t* out, va_list va) const {
        ssize_t count = 0;
        ssize_t amount = 0;
        for (count = 0; out; count += amount) {
            if (0 > (amount = this->out(f, out))) {
                return amount;
            }
            out = va_arg(va, const char_t*);
        }
        return count;
    }
    virtual ssize_t outln(file_t f, const char_t* out, ssize_t length) const {
        ssize_t count = 0;
        ssize_t amount;
        if (0 <= (amount = this->out(f, out, length))) {
            count += amount;
            if (0 <= (amount = this->outln(f))) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t outln(file_t f, const char_t* out) const {
        ssize_t count = this->outln(f, out, -1);
        return count;
    }
    virtual ssize_t outln(file_t f) const {
        const char_t ln = ((char_t)'\n');
        ssize_t count = this->out(f, &ln, 1);
        return count;
    }
    virtual ssize_t out(file_t f, const char_t* out, ssize_t length) const {
        ssize_t count = 0;
        if ((out) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 <= (length)) {
                if (0 < (amount = this->out(f, out, sizeof(char_t), length))) {
                    count += amount;
                }
            } else {
                for (; *out; ++out) {
                    if (0 < (amount = this->out(f, out, sizeof(char_t), 1))) {
                        count += amount;
                        continue;
                    }
                    break;
                }
            }
        }
        return count;
    }
    virtual ssize_t out(file_t f, const char_t* out) const {
        ssize_t count = this->out(f, out, -1);
        return count;
    }
    virtual ssize_t out(file_t f, const char_t* out, size_t size, size_t length) const {
        ssize_t count = 0;
        if ((out) && (size) && (length) && (f != ((file_t)null_file))) {
            ssize_t amount = 0;
            if (0 < (amount /*= ::fwrite(out, sizeof(char_t), length, f)*/)) {
                count += amount;
            }
        }
        return count;
    }
    virtual ssize_t outfv(file_t f, const char_t* format, va_list va) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file)) && (format)) {
            /*count = ::vfprintf(f, format, va);*/
        }
        return count;
    }
    virtual ssize_t out_flush(file_t f) const {
        ssize_t count = 0;
        if ((f != ((file_t)null_file))) {
            int err = 0;
            if ((err /*= ::fflush(f)*/)) {
                count = -1;
            }
        }
        return count;
    }
};
typedef output_baset<> output_base;

typedef output_base::implements outputt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: outputt
///////////////////////////////////////////////////////////////////////
template 
<typename TChar = char, typename TEndChar = TChar, TEndChar VEndChar = 0,
 typename TFile = FILE*, typename TNullFile = int, TNullFile VNullFile = 0,
 class TString = char_stringt<TChar, TEndChar, VEndChar>,
 class TImplement = outputt_implements,
 class TImplements = output_baset
 <TChar, TEndChar, VEndChar, TFile, TNullFile, VNullFile, TString, TImplement> >
class _EXPORT_CLASS outputt: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef TString string_t;
    typedef TFile file_t;
    typedef TNullFile null_file_t;
    enum { null_file = VNullFile };
    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };

    virtual ssize_t outf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        if ((format)) {
            va_start(va, format);
            count = this->outfv(format, va);
            va_end(va);
        }
        return count;
    }
    virtual ssize_t outl(const char_t* out, ...) {
        ssize_t count = 0;
        va_list va;
        if ((out)) {
            va_start(va, out);
            count = outlv(out, va);
            va_end(va);
        }
        return count;
    }
    virtual ssize_t outlln(const char_t* out, ...) {
        ssize_t count = 0, amount = 0;
        va_list va;
        if ((out)) {
            va_start(va, out);
            count = this->outlv(out, va);
            va_end(va);
        }
        if (0 <= (count)) {
            if (0 <= (amount = this->outln())) {
                count += amount;
            } else {
                count = amount;
            }
        }
        return count;
    }

    using implements::outfv;
    using implements::outlv;
    using implements::outln;
    using implements::out;
    using implements::out_flush;
    virtual ssize_t outfv(const char_t* format, va_list va) {
        ssize_t count = this->outfv(this->out_std_out(), format, va);
        return count;
    }
    virtual ssize_t outlv(const char_t* out, va_list va) {
        ssize_t count = this->outlv(this->out_std_out(), out, va);
        return count;
    }
    virtual ssize_t outln(const char_t* out, ssize_t length) {
        ssize_t count = this->outln(this->out_std_out(), out, length);
        return count;
    }
    virtual ssize_t outln(const char_t* out) {
        ssize_t count = this->outln(this->out_std_out(), out, -1);
        return count;
    }
    virtual ssize_t outln() {
        ssize_t count = this->outln(this->out_std_out());
        return count;
    }
    virtual ssize_t out(const char_t* out, ssize_t length) {
        ssize_t count = this->out(this->out_std_out(), out, length);
        return count;
    }
    virtual ssize_t out(const char_t* out) {
        ssize_t count = this->out(this->out_std_out(), out, -1);
        return count;
    }
    virtual ssize_t out_flush() {
        ssize_t count = this->out_flush(this->out_std_out());
        return count;
    }

protected:
    virtual file_t out_std_out() {
        return this->std_out();
    }
    virtual file_t std_out() const {
        return ((file_t)null_file);/*::stdout;*/
    }
};
typedef outputt<char> output;

} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_OUTPUT_HPP 
