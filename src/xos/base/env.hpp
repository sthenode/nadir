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
///   File: env.hpp
///
/// Author: $author$
///   Date: 9/30/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_ENV_HPP
#define _XOS_BASE_ENV_HPP

#include "xos/base/argv.hpp"

extern "C" {
extern char **environ;
} /// extern "C"

namespace xos {

///////////////////////////////////////////////////////////////////////
///  Class: envt
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, size_t VDefaultSize = 128,
 class TExtends = argvt<TChar, VDefaultSize>,
 class TImplements = typename TExtends::implements>

class _EXPORT_CLASS envt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef envt derives;

    typedef typename extends::strings_t strings_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::chars_t chars_t;
    typedef typename extends::char_t char_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    envt(const char_t** elements, const size_t& length, bool is_end = false)
    : extends(elements, length, is_end) {
    }
    envt(const char_t* element, va_list va, bool is_end = false)
    : extends(element, va, is_end) {
    }
    envt(const char_t* element, ...) {
        if ((element) && (element[0])) {
            va_list va;
            va_start(va, element);
            this->appendv(element, va);
            va_end(va);
        }
        this->append_end();
    }
    envt(bool is_end = false): extends(is_end) {
    }
    virtual ~envt() {
    }
private:
    envt(const envt &copy) {
        throw exception(exception_unexpected);
    }
    
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_t** get(size_t& length, char_t** env) {
        return get<char_t>(length, env);
    }
    virtual char_t** get(char_t** env) {
        size_t length = 0;
        return get<char_t>(length, env);
    }
    virtual char_t** get(size_t& length) {
        return get<char>(length, ::environ);
    }
    virtual char_t** get() {
        size_t length = 0;
        return get(length);
    }
    
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    template <typename TCharT>
    char_t** get(size_t& length, TCharT** elements) {
        this->clear();
        if (elements) {
            for (TCharT* element = *elements; element; element = *(++elements)) {
                if (element[0]) {
                    this->append(element);
                }
            }
            this->append_end();
            return this->elements(length);
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS envt

typedef envt<char> env;
typedef envt<tchar_t> tenv;
typedef envt<wchar_t> wenv;

} /// namespace xos

#endif /// _XOS_BASE_ENV_HPP 
