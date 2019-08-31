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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 8/29/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_MAIN_OUT_WRITER_HPP
#define _XOS_IO_MAIN_OUT_WRITER_HPP

#include "xos/console/main.hpp"
#include "xos/io/writer.hpp"

namespace xos {
namespace io {
namespace main {
namespace out {

///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template 
<class TWriter = io::char_writer, class TMain = console::main,
 class TImplements = TWriter, class TExtends = base>

class _EXPORT_CLASS writert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TMain main_t;
    typedef TWriter writer_t;
    typedef typename writer_t::what_t what_t;
    typedef typename writer_t::sized_t sized_t;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    writert(const writert &copy): main_(copy.main_) {
    }
    writert(main_t& main): main_(main) {
    }
    virtual ~writert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const what_t* what, size_t size) {
        const sized_t* chars = 0;
        if ((chars = ((const sized_t*)what))) {
            return main_.write_out(chars, size);
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    main_t& main_;
}; /// class _EXPORT_CLASS writert
typedef writert<> writer;

} /// namespace out
} /// namespace main
} /// namespace io
} /// namespace xos

#endif /// _XOS_IO_MAIN_OUT_WRITER_HPP 
