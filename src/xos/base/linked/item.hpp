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
///   File: item.hpp
///
/// Author: $author$
///   Date: 6/12/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_LINKED_ITEM_HPP
#define _XOS_BASE_LINKED_ITEM_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace linked {

///////////////////////////////////////////////////////////////////////
///  Class: itemt
///////////////////////////////////////////////////////////////////////
template
<class TDerives, class TImplements = implement_base, class TExtends = base>

class _EXPORT_CLASS itemt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef TDerives derives;

    itemt(derives* prev, derives* next) : prev_(prev), next_(next) {
    }
    itemt(const itemt& copy) : prev_(0), next_(0) {
    }
    itemt() : prev_(0), next_(0) {
    }
    virtual ~itemt() {
    }

    virtual derives* set_prev(derives* to) {
        prev_ = to;
        return prev_;
    }
    virtual derives* prev() const {
        return prev_;
    }
    virtual derives* set_next(derives* to) {
        next_ = to;
        return next_;
    }
    virtual derives* next() const {
        return next_;
    }

protected:
    derives *prev_, *next_;
};

} /// namespace linked
} /// namespace xos

#endif /// _XOS_BASE_LINKED_ITEM_HPP 
