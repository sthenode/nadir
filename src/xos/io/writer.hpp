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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 5/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_WRITER_HPP
#define _XOS_IO_WRITER_HPP

#include "xos/io/sequence.hpp"

namespace xos {
namespace io {

///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = sequence>

class _EXPORT_CLASS writert: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;
    typedef typename implements::endof_t endof_t;
    static const endof_t endof = implements::endof;

    virtual ssize_t write(const what_t* what, size_t size) {
        ssize_t count = 0;
        return count;
    }    
    virtual ssize_t write(const what_t* what) {
        const sized_t* sized = 0;
        ssize_t count = 0;
        if ((sized = ((const sized_t*)what))) {
            ssize_t amount = 0;
            do {
                const sized_t& c = *sized;
                if (c != endof) {
                    if (0 < (amount = write(sized, 1))) {
                        count += amount;
                        ++sized;
                        continue;
                    } else {
                        if (0 > (amount)) {
                            count = amount;
                        }
                    }
                }
                break;
            } while (sized);
        }
        return count;
    }    
    virtual ssize_t writel(const what_t* what, ...) {
        ssize_t count = 0;
        va_list va;
        va_start(va, what);
        count = writev(what, va);
        va_end(va);
        return count;
    }    
    virtual ssize_t writev(const what_t* what, va_list va) {
        typedef const sized_t* const_sized_pointer;
        ssize_t count = 0, amount = 0;
        for (count = 0; what; count += amount) {
            if (0 > (amount = write(what))) {
                return count;
            }
            what = va_arg(va, const_sized_pointer);
        }
        return count;
    }    
    virtual ssize_t flush() {
        ssize_t count = 0;
        return count;
    }    
};
typedef writert<sequence> writer;

typedef writert<char_sequence> char_writer;
typedef writert<tchar_sequence> tchar_writer;
typedef writert<wchar_sequence> wchar_writer;

typedef writert<byte_sequence> byte_writer;
typedef writert<word_sequence> word_writer;

} /// namespace io
} /// namespace xos

#endif /// _XOS_IO_WRITER_HPP 
