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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 7/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_CRT_FILE_READER_HPP
#define _XOS_IO_CRT_FILE_READER_HPP

#include "xos/base/opened.hpp"
#include "xos/io/reader.hpp"

#define XOS_IO_CRT_FILE_MODE_READ "r"
#define XOS_IO_CRT_FILE_MODE_BINARY "b"
#define XOS_IO_CRT_FILE_MODE_READ_BINARY \
    XOS_IO_CRT_FILE_MODE_READ \
    XOS_IO_CRT_FILE_MODE_BINARY

namespace xos {
namespace io {
namespace crt {
namespace file {

///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template 
<class TImplement = io::reader, class TExtend = base,
 typename TAttached = FILE*, typename TUnattached = int, TUnattached VUnattached = 0,
 class TOpener = openert<TImplement>,
 class TImplements = attachert<TAttached, TUnattached, VUnattached, TOpener>, 
 class TAttachedt = attachedt<TAttached, TUnattached, VUnattached, TImplements, TExtend>,
 class TExtends = openedt<TAttached, TUnattached, VUnattached, TImplements, TAttachedt> >

class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;
    enum { endof = implements::endof };
    
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };
    
    enum mode_t { mode_binary, mode_text };
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    readert(attached_t attached, bool is_open): extends(attached, is_open) {
    }
    readert(attached_t attached): extends(attached) {
    }
    readert(const readert &copy): extends(copy.attached_to()) {
    }
    readert() {
    }
    virtual ~readert() {
        if (!(this->closed())) {
            const open_exception e(close_failed);
            LOG_ERROR("...failed on this->closeed() throw (e = close_failed)...");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open(const char* name, mode_t mode = mode_binary) {
        if ((this->closed())) {
            attached_t detached = 0;
            if ((detached = open_attached(name, mode))) {
                this->attach_opened(detached);
                return true;
            }
        }
        return false;
    }
    virtual attached_t open_attached(const char* name, mode_t mode = mode_binary) {
        attached_t detached = 0;
        if ((detached = open_detached(name, mode))) {
            this->attach(detached);
        }
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t open_detached(const char* name, mode_t mode = mode_binary) const {
        const char* read_mode = (mode != mode_binary)?(mode_read()):(mode_read_binary());
        if ((name) && (name[0]) && (read_mode) && (read_mode[0])) {
            attached_t detached = 0;
            if (!(detached = ::fopen(name, read_mode))) {
                LOG_ERROR("...failed errno = " << errno << " on ::fopen(\"" << name << "\", \"" << read_mode << "\")")
            }
            return detached;
        }
        return 0;
    }
    virtual bool close_detached(attached_t detached) const {
        if ((detached)) {
            int err = 0;
            if (!(err = ::fclose(detached))) {
                return true;
            } else {
                LOG_ERROR("...failed errno = " << errno << " on ::fclose(detached)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t readfv(const char* format, va_list va) {
        attached_t detached = 0;
        if ((format) && (detached = this->attached_to())) {
            ssize_t count = 0;
            if (0 > (count = ::vfscanf(detached, format, va))) {
                LOG_ERROR("...failed errno = " << errno << " on ::vfscanf(detached, format, va)");
            }
            return count;
        }
        return 0;
    }
    virtual ssize_t read(what_t* what, size_t size) {
        attached_t detached = 0;
        if ((what) && (size) && (detached = this->attached_to())) {
            ssize_t count = 0;
            if (0 > (count = ::fread(what, sizeof(sized_t), size, detached))) {
                LOG_ERROR("...failed errno = " << errno << " on ::fread(what, sizeof(sized_t), size, detached)");
            }
            return count;
        }
        return 0;
    }
    virtual ssize_t eof() {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            int end = 0;
            if (0 <= (end = ::feof(detached))) {
                return end;
            } else {
                LOG_ERROR("...failed errno = " << errno << " on ::feof(detached)");
            }
        }
        return -1;
    }
    virtual ssize_t fill() {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t seek(ssize_t offset, int whence) {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            int err = 0;
            if (!(err = fseek(detached, offset, whence))) {
                ssize_t told = 0;
                if (0 <= (told = ftell(detached))) {
                    return told;
                } else {
                    LOG_ERROR("...failed errno = " << errno << " on ftell(detached)");
                }
            } else {
                LOG_ERROR("...failed errno = " << errno << " on fseek(detached, offset, whence)");
            }
        }
        return -1;
    }
    virtual ssize_t tell() {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            ssize_t told = 0;
            if (0 <= (told = ::ftell(detached))) {
                return told;
            } else {
                LOG_ERROR("...failed errno = " << errno << " on ::ftell(detached)");
            }
        }
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* mode_read() const {
        return XOS_IO_CRT_FILE_MODE_READ;
    }
    virtual const char* mode_read_binary() const {
        return XOS_IO_CRT_FILE_MODE_READ_BINARY;
    }
    virtual mode_t binary_mode() const {
        return mode_binary;
    }
    virtual mode_t text_mode() const {
        return mode_text;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef readert<io::reader> reader;

typedef readert<io::char_reader> char_reader;
typedef readert<io::tchar_reader> tchar_reader;
typedef readert<io::wchar_reader> wchar_reader;

typedef readert<io::byte_reader> byte_reader;
typedef readert<io::word_reader> word_reader;

} /// namespace file
} /// namespace crt
} /// namespace io
} /// namespace xos

#endif /// _XOS_IO_CRT_FILE_READER_HPP 
