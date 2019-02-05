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
///   File: main.hpp
///
/// Author: $author$
///   Date: 4/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_NADIR_MAIN_HPP
#define _XOS_APP_CONSOLE_NADIR_MAIN_HPP

#include "xos/console/lib/version/main.hpp"
#include "xos/lib/nadir/version.hpp"

namespace xos {
namespace app {
namespace console {
namespace nadir {

typedef xos::console::lib::version::maint<xos::lib::nadir::version> main;

} /// namespace nadir
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_NADIR_MAIN_HPP 
