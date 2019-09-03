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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 9/2/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_SIZED_READER_HPP
#define _XOS_IO_SIZED_READER_HPP

#include "xos/io/reader.hpp"
#include "xos/io/told.hpp"

namespace xos {
namespace io {
namespace sized {

///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template <class TImplements = io::reader, class TExtends = io::told>
class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef implements reader_t;
    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(reader_t &reader, size_t size): reader_(reader), size_(size) {
    }
    readert(const readert &copy): reader_(copy.reader_), size_(copy.size_) {
    }
    readert(reader_t &reader): reader_(reader), size_(0) {
    }
    virtual ~readert() {
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t read(what_t* what, size_t size) {
        sized_t* sized = 0;

        if ((sized = ((sized_t*)what)) && (size)) {
            size_t length = this->length();
            ssize_t count = 0;

            if (0 < (length)) {
                size_t tell = this->tell();
                if ((length > (tell))) {
                    if (length < (tell + size)) {
                        if (1 > (size = length - tell)) {
                            return 0;
                        }
                    }
                    if (0 < (count = reader_.read(what, size))) {
                        this->tell_ += count;
                        return count;
                    }
                }
            } else {
                if (0 < (count = reader_.read(what, size))) {
                    this->tell_ += count;
                    return count;
                }
            }
        }
        return 0;
    }    
    virtual ssize_t reset() {
        if (0 < (this->length())) {
            return extends::reset();
        }
        return this->tell();
    }
    virtual ssize_t seek(size_t to, int whence) {
        if (0 < (this->length())) {
            return extends::seek(to, whence);
        }
        return this->tell();
    }
    virtual size_t length() const {
        return size_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    reader_t &reader_;
    size_t size_;
}; /// class _EXPORT_CLASS readert

typedef readert<> reader;
typedef readert<io::char_reader, io::char_told> char_reader;

} /// namespace sized
} /// namespace io
} /// namespace xos

#endif /// _XOS_IO_SIZED_READER_HPP 
