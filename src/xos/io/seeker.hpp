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
///   File: seeker.hpp
///
/// Author: $author$
///   Date: 3/31/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_SEEKER_HPP
#define _XOS_IO_SEEKER_HPP

#include "xos/io/sequence.hpp"

namespace xos {
namespace io {

///////////////////////////////////////////////////////////////////////
///  Enum: from_t
///////////////////////////////////////////////////////////////////////
typedef int from_t;
enum {
    from_begining,
    from_end,
    from_current
};

typedef sequence seekert_implements;
///////////////////////////////////////////////////////////////////////
///  Class: seekert
///////////////////////////////////////////////////////////////////////
template <class TImplements = seekert_implements>
class _EXPORT_CLASS seekert: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;
    typedef typename implements::endof_t endof_t;
    static const endof_t endof = implements::endof;

    virtual ssize_t reset() {
        return 0;
    }
    virtual ssize_t seek(size_t to, int whence) {
        return 0;
    }
    virtual ssize_t tell() const {
        return 0;
    }
}; /// class _EXPORT_CLASS seekert

typedef seekert<sequence> seeker;

typedef seekert<char_sequence> char_seeker;
typedef seekert<tchar_sequence> tchar_seeker;
typedef seekert<wchar_sequence> wchar_seeker;

typedef seekert<byte_sequence> byte_seeker;
typedef seekert<word_sequence> word_seeker;

} /// namespace io
} /// namespace xos

#endif /// _XOS_IO_SEEKER_HPP 
