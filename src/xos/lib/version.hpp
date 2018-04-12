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
///   File: version.hpp
///
/// Author: $author$
///   Date: 4/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LIB_VERSION_HPP
#define _XOS_LIB_VERSION_HPP

#include "xos/base/string.hpp"

namespace xos {
namespace lib {

typedef implement_base versiont_implements;
///////////////////////////////////////////////////////////////////////
///  Class: versiont
///////////////////////////////////////////////////////////////////////
template 
<class TChar = char, 
 class TString = char_stringt<TChar>,
 class TImplements = versiont_implements>
class _EXPORT_CLASS versiont: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef TString string_t;
    
    virtual string_t to_string() const {
        string_t to(this->name());
        to.append(this->name_separator());
        to.append_unsigned(this->major());
        to.append(this->major_separator());
        to.append_unsigned(this->minor());
        to.append(this->minor_separator());
        to.append_unsigned(this->release());
        return to;
    }

    virtual const char_t* name() const {
        return "version";
    }
    virtual const char_t* name_separator() const {
        return "-";
    }
    virtual const char_t* major_separator() const {
        return ".";
    }
    virtual const char_t* minor_separator() const {
        return ".";
    }

    virtual unsigned major() const {
        return 0;
    }
    virtual unsigned minor() const {
        return 0;
    }
    virtual unsigned release() const {
        return 0;
    }
};
typedef versiont<> version;

} /// namespace lib
} /// namespace xos

#endif /// _XOS_LIB_VERSION_HPP 
