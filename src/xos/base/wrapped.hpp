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
///   File: wrapped.hpp
///
/// Author: $author$
///   Date: 10/25/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_WRAPPED_HPP
#define _XOS_BASE_WRAPPED_HPP

#include "xos/base/base.hpp"

namespace xos {

typedef implement wrappert_implements;
typedef extend wrappert_extends;
///////////////////////////////////////////////////////////////////////
///  Class: wrappert
///////////////////////////////////////////////////////////////////////
template 
<typename TWrapped, 
 class TImplements = wrappert_implements, class TExtends = wrappert_extends>

class _EXPORT_CLASS wrappert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef wrappert derives;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    wrappert(TWrapped& wrapped, TWrapped& wrapped_extends)
    : extends(wrapped_extends), wrapped_(wrapped) {
    }
    wrappert(const wrappert &copy): wrapped_(copy.wrapped_) {
    }
    wrappert(TWrapped& wrapped): wrapped_(wrapped) {
    }
    virtual ~wrappert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TWrapped& wrapped_;
}; /// class _EXPORT_CLASS wrappert

} /// namespace xos

#endif /// _XOS_BASE_WRAPPED_HPP 
