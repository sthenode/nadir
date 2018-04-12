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
#ifndef _XOS_CONSOLE_ERROR_HPP
#define _XOS_CONSOLE_ERROR_HPP

#include "xos/console/output.hpp"

namespace xos {
namespace console {

typedef output_base::implements errort_implements;
///////////////////////////////////////////////////////////////////////
///  Class: errort
///////////////////////////////////////////////////////////////////////
template 
<typename TChar = char, typename TEndChar = TChar, TEndChar VEndChar = 0,
 typename TFile = FILE*, typename TNullFile = int, TNullFile VNullFile = 0,
 class TString = char_stringt<TChar, TEndChar, VEndChar>,
 class TImplement = errort_implements,
 class TImplements = output_baset
 <TChar, TEndChar, VEndChar, TFile, TNullFile, VNullFile, TString, TImplement> >
class _EXPORT_CLASS errort: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef TString string_t;
    typedef TFile file_t;
    typedef TNullFile null_file_t;
    enum { null_file = VNullFile };
    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };

    virtual ssize_t errf(const char_t* format, ...) {
        ssize_t count = 0;
        va_list va;
        if ((format)) {
            va_start(va, format);
            count = this->errfv(format, va);
            va_end(va);
        }
        return count;
    }
    virtual ssize_t errl(const char_t* out, ...) {
        ssize_t count = 0;
        va_list va;
        if ((out)) {
            va_start(va, out);
            count = errlv(out, va);
            va_end(va);
        }
        return count;
    }
    virtual ssize_t errlln(const char_t* out, ...) {
        ssize_t count = 0, amount = 0;
        va_list va;
        if ((out)) {
            va_start(va, out);
            count = this->errlv(out, va);
            va_end(va);
        }
        if (0 <= (count)) {
            if (0 <= (amount = this->errln())) {
                count += amount;
            } else {
                count = amount;
            }
        }
        return count;
    }

    virtual ssize_t errfv(const char_t* format, va_list va) {
        ssize_t count = this->outfv(this->out_std_err(), format, va);
        return count;
    }
    virtual ssize_t errlv(const char_t* out, va_list va) {
        ssize_t count = this->outlv(this->out_std_err(), out, va);
        return count;
    }
    virtual ssize_t errln(const char_t* out, ssize_t length) {
        ssize_t count = this->outln(this->out_std_err(), out, length);
        return count;
    }
    virtual ssize_t errln(const char_t* out) {
        ssize_t count = this->outln(this->out_std_err(), out, -1);
        return count;
    }
    virtual ssize_t errln() {
        ssize_t count = this->outln(this->out_std_err());
        return count;
    }
    virtual ssize_t err(const char_t* out, ssize_t length) {
        ssize_t count = this->out(this->out_std_err(), out, length);
        return count;
    }
    virtual ssize_t err(const char_t* out) {
        ssize_t count = this->out(this->out_std_err(), out);
        return count;
    }
    virtual ssize_t err_flush() {
        ssize_t count = this->out_flush(this->out_std_err());
        return count;
    }

protected:
    virtual file_t out_std_err() {
        return this->std_err();
    }
    virtual file_t std_err() const {
        return ((file_t)null_file);/*::stderr;*/
    }
};
typedef errort<char> error;

} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_ERROR_HPP 
