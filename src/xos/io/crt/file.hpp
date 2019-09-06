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
///   File: file.hpp
///
/// Author: $author$
///   Date: 5/22/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_CRT_FILE_HPP
#define _XOS_IO_CRT_FILE_HPP

#include "xos/base/opened.hpp"
#include "xos/io/stream.hpp"

#define XOS_IO_CRT_FILE_MODE_READ "r"
#define XOS_IO_CRT_FILE_MODE_WRITE "w"
#define XOS_IO_CRT_FILE_MODE_APPEND "+"
#define XOS_IO_CRT_FILE_MODE_BINARY "b"

#define XOS_IO_CRT_FILE_MODE_READ_APPEND \
    XOS_IO_CRT_FILE_MODE_READ \
    XOS_IO_CRT_FILE_MODE_APPEND

#define XOS_IO_CRT_FILE_MODE_WRITE_APPEND \
    XOS_IO_CRT_FILE_MODE_WRITE \
    XOS_IO_CRT_FILE_MODE_APPEND

#define XOS_IO_CRT_FILE_MODE_READ_BINARY \
    XOS_IO_CRT_FILE_MODE_READ \
    XOS_IO_CRT_FILE_MODE_BINARY

#define XOS_IO_CRT_FILE_MODE_WRITE_BINARY \
    XOS_IO_CRT_FILE_MODE_WRITE \
    XOS_IO_CRT_FILE_MODE_BINARY

#define XOS_IO_CRT_FILE_MODE_READ_BINARY_APPEND \
    XOS_IO_CRT_FILE_MODE_READ \
    XOS_IO_CRT_FILE_MODE_BINARY \
    XOS_IO_CRT_FILE_MODE_APPEND

#define XOS_IO_CRT_FILE_MODE_WRITE_BINARY_APPEND \
    XOS_IO_CRT_FILE_MODE_WRITE \
    XOS_IO_CRT_FILE_MODE_BINARY \
    XOS_IO_CRT_FILE_MODE_APPEND

namespace xos {
namespace io {
namespace crt {

typedef stream filet_implements;
typedef base filet_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filet
///////////////////////////////////////////////////////////////////////
template 
<class TImplement = filet_implements, class TExtend = filet_extends,
 typename TAttached = FILE*, typename TUnattached = int, TUnattached VUnattached = 0,
 class TOpener = openert<TImplement>,
 class TImplements = attachert<TAttached, TUnattached, VUnattached, TOpener>, 
 class TAttachedt = attachedt<TAttached, TUnattached, VUnattached, TImplements, TExtend>,
 class TExtends = openedt<TAttached, TUnattached, VUnattached, TImplements, TAttachedt> >

class _EXPORT_CLASS filet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;
    enum { endof = implements::endof };
    
    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };
    
    filet(attached_t attached, bool is_open): extends(attached, is_open) {
    }
    filet(attached_t attached): extends(attached) {
    }
    filet(const filet &copy): extends(copy.attached_to()) {
    }
    filet() {
    }
    virtual ~filet() {
        if (!(this->closed())) {
            const open_exception e(close_failed);
            LOG_ERROR("...failed on this->closeed() throw (e = close_failed)...");
            throw (e);
        }
    }

    virtual bool open(const char* name) {
        const char* mode = 0;
        if ((mode = mode_read_binary())) {
            if ((open(name, mode))) {
                return true;
            }
        }
        return false;
    }
    virtual bool open(const char* name, const char* mode) {
        if ((this->closed())) {
            attached_t detached = 0;
            if ((detached = open_attached(name, mode))) {
                this->attach_opened(detached);
                return true;
            }
        }
        return false;
    }
    virtual bool close() {
        attached_t detached = 0;
        if ((detached = this->detach())) {
            if ((close_detached(detached))) {
                return true;
            }
        }
        return false;
    }

    virtual attached_t open_attached(const char* name, const char* mode) {
        attached_t detached = 0;
        if ((detached = open_detached(name, mode))) {
            this->attach(detached);
        }
        return detached;
    }
    virtual attached_t open_detached(const char* name, const char* mode) const {
        if ((name) && (name[0]) && (mode) && (mode[0])) {
            attached_t detached = 0;
            if (!(detached = ::fopen(name, mode))) {
                LOG_ERROR("...failed errno = " << errno << " on ::fopen(\"" << name << "\", \"" << mode << "\")")
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
    virtual ssize_t writefv(const char* format, va_list va) {
        attached_t detached = 0;
        if ((format) && (detached = this->attached_to())) {
            ssize_t count = 0;
            if (0 > (count = ::vfprintf(detached, format, va))) {
                LOG_ERROR("...failed errno = " << errno << " on ::vfprintf(detached, format, va)");
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
    virtual ssize_t write(const what_t* what, size_t size) {
        attached_t detached = 0;
        if ((what) && (size) && (detached = this->attached_to())) {
            ssize_t count = 0;
            if (size != (count = ::fwrite(what, sizeof(sized_t), size, detached))) {
                LOG_ERROR("...failed errno = " << errno << " on ::fwrite(what, sizeof(sized_t), size, detached)");
            }
            return count;
        }
        return 0;
    }

    virtual ssize_t fill() {
        return 0;
    }
    virtual ssize_t flush() {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            int err = 0;
            if ((err = ::fflush(detached))) {
                LOG_ERROR("...failed errno = " << errno << " on ::fflush(detached)");
                return -1;
            }
        }
        return 0;
    }

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

    virtual bool set_mode_is_binary(bool mode_is_binary = true) {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
#if defined(WINDOWS)
            int fd = -1;
            if (0 <= (fd = _fileno(detached))) {
                int mode = (mode_is_binary)?(_O_BINARY):(_O_TEXT);
                int err = 0;
                if (0 > (err = ::_setmode(fd, mode))) {
                    LOG_ERROR("...failed errno = " << errno << " on ::_setmode(fd = " << fd << ", mode = " << mode << ")");
                } else {
                    return true;
                }
            }
#else // defined(WINDOWS)
            return mode_is_binary;
#endif // defined(WINDOWS)
        }
        return false;
    }

    virtual const char* mode_read() const {
        return XOS_IO_CRT_FILE_MODE_READ;
    }
    virtual const char* mode_write() const {
        return XOS_IO_CRT_FILE_MODE_WRITE;
    }
    virtual const char* mode_append() const {
        return XOS_IO_CRT_FILE_MODE_WRITE_APPEND;
    }

    virtual const char_t* mode_read_binary() const {
        return XOS_IO_CRT_FILE_MODE_READ_BINARY;
    }
    virtual const char_t* mode_write_binary() const {
        return XOS_IO_CRT_FILE_MODE_WRITE_BINARY;
    }
    virtual const char_t* mode_append_binary() const {
        return XOS_IO_CRT_FILE_MODE_WRITE_BINARY_APPEND;
    }
};
typedef filet<stream> _file;

typedef filet<char_stream> char_file;
typedef filet<tchar_stream> tchar_file;
typedef filet<wchar_stream> wchar_file;

typedef filet<byte_stream> byte_file;
typedef filet<word_stream> word_file;

} /// namespace crt
} /// namespace io
} /// namespace xos

#endif /// _XOS_IO_CRT_FILE_HPP 
