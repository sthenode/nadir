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
///   File: base.hpp
///
/// Author: $author$
///   Date: 4/1/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_BASE_HPP
#define _XOS_BASE_BASE_HPP

#include "xos/platform/platform.hpp"

namespace xos {

///////////////////////////////////////////////////////////////////////
/// Enum error_t
///////////////////////////////////////////////////////////////////////
typedef int error_t;
enum {
    error_none = 0,
    error_failed = 1
};

///////////////////////////////////////////////////////////////////////
///  Class: implement_baset
///////////////////////////////////////////////////////////////////////
template <typename TError = error_t>
class _EXPORT_CLASS implement_baset {
public:
    virtual ~implement_baset() {
    }
};
typedef implement_baset<> implement_base;

typedef implement_base baset_implements;
///////////////////////////////////////////////////////////////////////
///  Class: baset
///////////////////////////////////////////////////////////////////////
template <class TImplements = baset_implements>
class _EXPORT_CLASS baset: virtual public TImplements {
public:
    typedef TImplements implements;
    baset() {
    }
    baset(const baset &copy) {
    }
    virtual ~baset() {
    }
};
typedef baset<> base;

///
/// mseconds_ seconds / mseconds / useconds / nseconds
/// 
inline seconds_t mseconds_seconds
(mseconds_t mseconds) { return mseconds / 1000; }

inline mseconds_t mseconds_mseconds
(mseconds_t mseconds) { return mseconds % 1000; }

inline useconds_t mseconds_useconds
(mseconds_t mseconds) { return mseconds_mseconds(mseconds) * 1000; }

inline nseconds_t mseconds_nseconds
(mseconds_t mseconds) { return mseconds_useconds(mseconds) * 1000; }

///
/// to_ pointer / unsigned / signed / wchar / tchar / char / bool
/// 
inline const pointer_t& to_pointer(const pointer_t& v) { return v; }
inline const unsigned& to_unsigned(const unsigned& v) { return v; }
inline const signed& to_signed(const signed& v) { return v; }
inline const wchar_t& to_wchar(const wchar_t& v) { return v; }
inline const tchar_t& to_tchar(const tchar_t& v) { return v; }
inline const char& to_char(const char& v) { return v; }
inline const word_t& to_word(const word_t& v) { return v; }
inline const byte_t& to_byte(const byte_t& v) { return v; }
inline const bool& to_bool(const bool& v) { return v; }

} /// namespace xos

#endif /// _XOS_BASE_BASE_HPP 
