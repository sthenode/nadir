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
///   Date: 9/9/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_CRT_FILE_WRITER_HPP
#define _XOS_IO_CRT_FILE_WRITER_HPP

#include "xos/base/array.hpp"
#include "xos/base/opened.hpp"
#include "xos/io/writer.hpp"

#define XOS_IO_CRT_FILE_MODE_BINARY "b"

#define XOS_IO_CRT_FILE_MODE_READ "r"
#define XOS_IO_CRT_FILE_MODE_READ_BINARY \
    XOS_IO_CRT_FILE_MODE_READ \
    XOS_IO_CRT_FILE_MODE_BINARY

#define XOS_IO_CRT_FILE_MODE_WRITE "w"
#define XOS_IO_CRT_FILE_MODE_WRITE_BINARY \
    XOS_IO_CRT_FILE_MODE_WRITE \
    XOS_IO_CRT_FILE_MODE_BINARY

namespace xos {
namespace io {
namespace crt {
namespace file {

typedef implement writert_implements;
typedef extend writert_extends;
///////////////////////////////////////////////////////////////////////
///  Class: writert
///////////////////////////////////////////////////////////////////////
template 
<class TImplement = io::writer, class TExtend = base,
 typename TAttached = FILE*, typename TUnattached = int, TUnattached VUnattached = 0,
 class TOpener = openert<TImplement>,
 class TImplements = attachert<TAttached, TUnattached, VUnattached, TOpener>, 
 class TAttachedt = attachedt<TAttached, TUnattached, VUnattached, TImplements, TExtend>,
 class TExtends = openedt<TAttached, TUnattached, VUnattached, TImplements, TAttachedt> >

class _EXPORT_CLASS writert: virtual public TImplements, public TExtends {
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
    writert(attached_t attached, bool is_open): extends(attached, is_open) {
    }
    writert(attached_t attached): extends(attached) {
    }
    writert(const writert &copy): extends(copy.attached_to()) {
    }
    writert() {
    }
    virtual ~writert() {
        if (!(this->closed())) {
            const open_exception e(close_failed);
            LOG_ERROR("...failed on this->closeed() throw (e = close_failed)...");
            throw (e);
        }
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool open_safe(const char* name, const sized_t* pattern, mode_t mode = mode_binary) {
        if ((this->closed())) {
            attached_t detached = 0;
            if ((detached = open_safe_attached(name, pattern, mode))) {
                this->attach_opened(detached);
                return true;
            }
        }
        return false;
    }
    virtual attached_t open_safe_attached(const char* name, const sized_t* pattern, mode_t mode = mode_binary) {
        attached_t detached = 0;
        if ((detached = open_safe_detached(name, pattern, mode))) {
            this->attach(detached);
        }
        return detached;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using implements::write;
    virtual ssize_t write(const what_t* what, size_t size) {
        attached_t detached = 0;
        if ((what) && (size) && (detached = this->attached_to())) {
            ssize_t count = 0;
            if (0 > (count = ::fwrite(what, sizeof(sized_t), size, detached))) {
                LOG_ERROR("...failed errno = " << errno << " on ::fwrite(what, sizeof(sized_t), size, detached)");
            }
            return count;
        }
        return 0;
    }    
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual attached_t open_safe_detached(const char* name, const sized_t* pattern, mode_t mode = mode_binary) const {
        const char *read_mode = (mode != mode_binary)?(mode_read()):(mode_read_binary()),
                   *write_mode = (mode != mode_binary)?(mode_write()):(mode_write_binary());

        if ((name) && (name[0]) && (pattern) && (pattern[0]) && (read_mode) && (read_mode[0])) {
            attached_t detached = 0;
            bool safe = false;

            if ((safe = !(detached = ::fopen(name, read_mode)))) {
                LOG_DEBUG("...failed errno = " << errno << " on ::fopen(\"" << name << "\", \"" << read_mode << "\")");
            } else {
                stringt<sized_t> match(pattern);
                size_t length = 0;

                if (0 < (length = match.length())) {
                    arrayt<sized_t> array(length);
                    sized_t* sized = 0;
                    size_t size = 0;

                    if (((sized = array.elements())) && (length <= (size = array.size()))) {
                        ssize_t count = 0;

                        if (0 > (count = ::fread(sized, sizeof(sized_t), length, detached))) {
                            LOG_ERROR("...failed errno = " << errno << " on ::fread(sized, sizeof(sized_t), length, detached)");
                        } else {
                            if (length > (count)) {
                                if (0 == (count)) {
                                    safe = true;
                                }
                            } else {
                                stringt<sized_t> compare(sized, length);
                                
                                if (0 == (match.compare(compare))) {
                                    safe = true;
                                }
                            }
                        }
                    }
                }
                close_detached(detached);
                detached = 0;
            }
            if ((safe) && (write_mode) && (write_mode[0])) {
                if (!(detached = ::fopen(name, write_mode))) {
                    LOG_ERROR("...failed errno = " << errno << " on ::fopen(\"" << name << "\", \"" << write_mode << "\")");
                }
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
    virtual const char* mode_read() const {
        return XOS_IO_CRT_FILE_MODE_READ;
    }
    virtual const char* mode_read_binary() const {
        return XOS_IO_CRT_FILE_MODE_READ_BINARY;
    }
    virtual const char* mode_write() const {
        return XOS_IO_CRT_FILE_MODE_WRITE;
    }
    virtual const char* mode_write_binary() const {
        return XOS_IO_CRT_FILE_MODE_WRITE_BINARY;
    }
    virtual mode_t binary_mode() const {
        return mode_binary;
    }
    virtual mode_t text_mode() const {
        return mode_text;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS writert

typedef writert<io::writer> writer;

typedef writert<io::char_writer> char_writer;
typedef writert<io::wchar_writer> wchar_writer;
typedef writert<io::tchar_writer> tchar_writer;

typedef writert<io::byte_writer> byte_writer;
typedef writert<io::word_writer> word_writer;

} /// namespace file
} /// namespace crt
} /// namespace io
} /// namespace xos

#endif /// _XOS_IO_CRT_FILE_WRITER_HPP 
