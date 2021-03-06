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
///   File: stream.hpp
///
/// Author: $author$
///   Date: 5/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_STREAM_HPP
#define _XOS_IO_STREAM_HPP

#include "xos/io/reader.hpp"
#include "xos/io/writer.hpp"

namespace xos {
namespace io {

///////////////////////////////////////////////////////////////////////
///  Class: streamt
///////////////////////////////////////////////////////////////////////
template 
<class TReaderImplements = reader, class TWriterImplements = writer>

class _EXPORT_CLASS streamt
: virtual public TReaderImplements, virtual public TWriterImplements {
public:
    typedef TWriterImplements implements;

    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;
    typedef typename implements::endof_t endof_t;
    static const endof_t endof = implements::endof;

};
typedef streamt<reader, writer> stream;

typedef streamt<char_reader, char_writer> char_stream;
typedef streamt<tchar_reader, tchar_writer> tchar_stream;
typedef streamt<wchar_reader, wchar_writer> wchar_stream;

typedef streamt<byte_reader, byte_writer> byte_stream;
typedef streamt<word_reader, word_writer> word_stream;

} /// namespace io
} /// namespace xos

#endif /// _XOS_IO_STREAM_HPP 
