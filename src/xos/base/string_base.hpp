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
///   File: string_base.hpp
///
/// Author: $author$
///   Date: 4/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_STRING_BASE_HPP
#define _XOS_BASE_STRING_BASE_HPP

#include "xos/base/base.hpp"

namespace xos {

typedef implement_base string_base_implementt_implements;
///////////////////////////////////////////////////////////////////////
///  Class: string_base_implementt
///////////////////////////////////////////////////////////////////////
template <class TImplements = string_base_implementt_implements>
class _EXPORT_CLASS string_base_implementt: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef string_base_implementt<> string_base_implement;

typedef string_base_implement string_baset_implements;
typedef base string_baset_extends;
///////////////////////////////////////////////////////////////////////
///  Class: string_baset
///////////////////////////////////////////////////////////////////////
template 
<typename TChar = char_t, size_t VDefaultSize = 128,
 typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TImplements = string_baset_implements, class TExtends = string_baset_extends>
class _EXPORT_CLASS string_baset: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { default_size = VDefaultSize };
    enum { end_char = VEndChar };

    string_baset(const char_t* chars, size_t length) {
        construct();
        append(chars, length);
    }
    string_baset(const char_t* chars) {
        construct();
        append(chars);
    }
    string_baset(const string_baset &copy) {
        construct();
        append(copy.c_str(), copy.length());
    }
    string_baset() {
        construct();
    }
    virtual ~string_baset() {
        destruct();
    }

    string_baset& assign(const char_t* chars, size_t length) {
        clear();
        return append(chars, length);
    }
    string_baset& assign(const char_t* chars) {
        clear();
        return append(chars);
    }
    string_baset& assign(const string_baset& copy) {
        clear();
        return append(copy.c_str(), copy.length());
    }

    string_baset& append(const char_t* chars, size_t length) {
        if ((chars) && (0 < length)) {
            size_t newSize = (tell_+length);
            if (size_ <= newSize) {
                if (fixed_size_)
                    length = size_-tell_;
                else
                if (!(_adjust_to_size(_new_size_of(newSize))))
                    length = 0;
            }
            if (length) {
                _copy_to(write_buffer_+tell_, chars, length);
                if ((tell_ += length) > length_)
                if ((length_ = tell_) < size_)
                    write_buffer_[tell_] = ((char_t)end_char);
            }
        }
        return *this;
    }
    string_baset& append(const char_t* chars) {
        return append(chars, _length_of(chars));
    }
    string_baset& append(const string_baset& copy) {
        return append(copy.c_str(), copy.length());
    }

    string_baset& clear() {
        if ((write_buffer_)) {
            if (size_ > (length_ = (tell_ = 0))) {
                write_buffer_[tell_] = ((char_t)end_char);
            }
        }
        return *this;
    }

    virtual int compare(const string_baset& to) const {
        return compare(to.c_str(), to.length());
    }
    virtual int compare(const char_t* toChars, size_t toLength) const {
        int unequal = 2;
        const char_t* thisChars = 0;
        char_t toChar = 0, thisChar = 0;
        size_t thisLength = 0;
        ssize_t lendiff = 0;

        if (!(thisChars = (c_str()))) {
            return (toChars)?(-1):(1);
        }

        if (0 < (lendiff = (toLength - (thisLength = length())))) {
            toLength = thisLength;
            unequal = -1;
        } else {
            if (lendiff) {
                unequal = 1;
            }
        }

        if (toLength > 0) {
            do {
                if ((thisChar = *(thisChars++)) > (toChar = *(toChars++))) {
                    return 1;
                } else {
                    if (thisChar < toChar) {
                        return -1;
                    }
                }
            } while (--toLength > 0);
        }
        return unequal;
    }
    virtual int compare(const char_t* toChars) const {
        return compare(toChars, _length_of(toChars));
    }

    virtual char_t* buffer() const {
        return str();
    }
    virtual const char_t* chars() const {
        return c_str();
    }

    virtual char_t* str() const {
        return write_buffer_;
    }
    virtual const char_t* c_str() const {
        return read_buffer_;
    }
    virtual size_t length() const {
        return length_;
    }

protected:
    virtual void construct() {
        free_buffer_ = fixed_size_ = false;
        size_ = default_size;
        length_ = tell_ = 0;
        read_buffer_ = write_buffer_ = default_buffer_;
    }
    virtual void destruct() {
        if ((write_buffer_ != default_buffer_)) {
            if ((write_buffer_) && (free_buffer_)) {
                _free_buffer(write_buffer_);
            }
        }
    }

    virtual size_t adjust_size(size_t newSize) {
        if (write_buffer_) {
            if (size_ < (newSize)) {
                if (!fixed_size_) {
                    if (0 < (_adjust_to_size(_new_size_of(newSize)))) {
                        return size_;
                    }
                }
            } else {
                return size_;
            }
        }
        return 0;
    }
    virtual size_t _adjust_to_size(size_t size) {
        if (write_buffer_) {
            if (size > size_) {
                bool freeBuffer = false;
                char_t* buffer = 0;

                if (!(freeBuffer = free_buffer_)) {
                    free_buffer_ = true;
                }
                if ((buffer = _alloc_buffer(size))) {
                    if (length_ > 0) {
                        _copy_to(buffer, write_buffer_, length_);
                    }
                    if ((write_buffer_ != default_buffer_) && (freeBuffer)) {
                        _free_buffer(write_buffer_);
                    }
                    read_buffer_ = write_buffer_ = buffer;
                    size_ = size;
                    return size_;
                } else {
                    free_buffer_ = freeBuffer;
                }
            } else {
                return size_;
            }
        }
        return 0;
    }
    virtual size_t _new_size_of(size_t size) const {
        ///
        /// Increase the buffer size by default buffer
        /// sized chunks. Note the desired new size is always
        /// needed size + 1. The size in chunks is calculated
        /// as (new size + (chunk size - 1)) / chunk size.
        /// since new size = needed size + 1 then we have
        /// chunks = (needed size + chunk size) / chunk size.
        /// Finally we need bytes which is chunks * chunk size
        /// which can be reduced to
        /// ((needed size / chunk size) + 1) * chunk size
        ///
        return ((size/default_size)+1)*default_size;
    }

    virtual size_t _copy_to(char_t* to, const char_t* from, size_t size) const {
        size_t length = 0;

        for (length = size; size; --size) {
            (*to++) = (*from++);
        }
        return length;
    }
    virtual size_t _length_of(const char_t* chars) const {
        const char_t endChar(((char_t)end_char));
        size_t length = 0;

        for (length = 0; ((*chars) != endChar); chars++) {
            length++;
        }
        return length;
    }

    virtual char_t* _alloc_buffer(size_t size) const {
        char_t* chars = new char_t[size];
        return chars;
    }
    virtual void _free_buffer(char_t* buffer) const {
        delete[] buffer;
    }

protected:
    bool free_buffer_, fixed_size_;
    size_t size_, length_, tell_;
    const char_t* read_buffer_;
    char_t* write_buffer_;
    char_t default_buffer_[default_size];
};

typedef string_baset<char> string_base, char_string_base;
typedef string_baset<tchar_t> tstring_base, tchar_string_base;
typedef string_baset<wchar_t> wstring_base, wchar_string_base;

typedef string_baset<byte_t> byte_string_base;
typedef string_baset<word_t> word_string_base;

} /// namespace xos

#endif /// _XOS_BASE_STRING_BASE_HPP 
