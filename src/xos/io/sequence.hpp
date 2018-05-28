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
///   File: sequence.hpp
///
/// Author: $author$
///   Date: 5/19/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_SEQUENCE_HPP
#define _XOS_IO_SEQUENCE_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace io {

///////////////////////////////////////////////////////////////////////
///  Class: sequencet
///////////////////////////////////////////////////////////////////////
template 
<typename TWhat = char, typename TSized = TWhat,
 typename TEndof = TSized, TEndof VEndof = 0,
 class TImplements = implement_base>

class _EXPORT_CLASS sequencet: virtual public TImplements {
public:
    typedef TImplements implements;
    
    typedef TWhat what_t;
    typedef TSized sized_t;
    typedef TEndof endof_t;
    static const endof_t endof = VEndof;
    
};
typedef sequencet<void, char> sequence;

typedef sequencet<char, char> char_sequence;
typedef sequencet<tchar_t, tchar_t> tchar_sequence;
typedef sequencet<wchar_t, wchar_t> wchar_sequence;

typedef sequencet<byte_t, byte_t> byte_sequence;
typedef sequencet<word_t, word_t> word_sequence;

} /// namespace io
} /// namespace xos

#endif /// _XOS_IO_SEQUENCE_HPP 
