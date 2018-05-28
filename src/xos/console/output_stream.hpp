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
///   File: output_stream.hpp
///
/// Author: $author$
///   Date: 5/21/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_OUTPUT_STREAM_HPP
#define _XOS_CONSOLE_OUTPUT_STREAM_HPP

#include "xos/console/io.hpp"
#include "xos/io/stream.hpp"

namespace xos {
namespace console {

typedef xos::console::io output_streamt_io;
typedef xos::io::char_stream output_streamt_implements;
typedef base output_streamt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: output_streamt
///////////////////////////////////////////////////////////////////////
template 
<class TIo = output_streamt_io, 
 class TImplements = output_streamt_implements, class TExtends = output_streamt_extends>

class _EXPORT_CLASS output_streamt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TIo io_t;
    typedef implements stream_t;
    typedef typename stream_t::what_t what_t;
    typedef typename stream_t::sized_t sized_t;
    
    output_streamt(const output_streamt &copy): io_(copy.io_) {
    }
    output_streamt(io_t& io): io_(io) {
    }
    virtual ~output_streamt() {
    }

    virtual ssize_t write(const what_t* what, size_t size) {
        ssize_t count = 0;
        count = io_.out((const sized_t*)what, size);
        return count;
    }    

protected:
    io_t& io_;
};
typedef output_streamt<> output_stream;

} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_OUTPUT_STREAM_HPP 
