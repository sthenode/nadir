########################################################################
# Copyright (c) 1988-2018 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: libnadir.pri
#
# Author: $author$
#   Date: 4/1/2018
#
# QtCreator .pri file for nadir library libnadir
########################################################################

########################################################################
# libnadir

# libnadir TARGET
#
libnadir_TARGET = nadir
libnadir_TEMPLATE = lib
libnadir_CONFIG += staticlib

# libnadir INCLUDEPATH
#
libnadir_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

# libnadir DEFINES
#
libnadir_DEFINES += \
$${nadir_DEFINES} \

########################################################################
# libnadir OBJECTIVE_HEADERS
#
#libnadir_OBJECTIVE_HEADERS += \
#$${NADIR_SRC}/nadir/base/Base.hh \

# libnadir OBJECTIVE_SOURCES
#
#libnadir_OBJECTIVE_SOURCES += \
#$${NADIR_SRC}/nadir/base/Base.mm \

########################################################################
# libnadir HEADERS
#
libnadir_HEADERS += \
$${NADIR_SRC}/xos/base/base.hpp \
$${NADIR_SRC}/xos/base/to_char.hpp \
$${NADIR_SRC}/xos/base/chars.hpp \
$${NADIR_SRC}/xos/base/array.hpp \
$${NADIR_SRC}/xos/base/string_base.hpp \
$${NADIR_SRC}/xos/base/string.hpp \
$${NADIR_SRC}/xos/base/to_string.hpp \
$${NADIR_SRC}/xos/base/exception.hpp \
$${NADIR_SRC}/xos/base/attached.hpp \
$${NADIR_SRC}/xos/base/created.hpp \
$${NADIR_SRC}/xos/base/opened.hpp \
\
$${NADIR_SRC}/xos/logger/level.hpp \
$${NADIR_SRC}/xos/logger/function.hpp \
$${NADIR_SRC}/xos/logger/location.hpp \
$${NADIR_SRC}/xos/logger/format.hpp \
$${NADIR_SRC}/xos/logger/message.hpp \
$${NADIR_SRC}/xos/logger/output.hpp \
$${NADIR_SRC}/xos/logger/interface.hpp \
\
$${NADIR_SRC}/xos/io/sequence.hpp \
$${NADIR_SRC}/xos/io/seeker.hpp \
$${NADIR_SRC}/xos/io/reader.hpp \
$${NADIR_SRC}/xos/io/array/reader.hpp \
$${NADIR_SRC}/xos/io/string/reader.hpp \
$${NADIR_SRC}/xos/io/told.hpp \
$${NADIR_SRC}/xos/io/logger.hpp \
$${NADIR_SRC}/xos/lib/version.hpp \
$${NADIR_SRC}/xos/lib/nadir/version.hpp \

# libnadir SOURCES
#
libnadir_SOURCES += \
$${NADIR_SRC}/xos/base/base.cpp \
$${NADIR_SRC}/xos/base/to_char.cpp \
$${NADIR_SRC}/xos/base/chars.cpp \
$${NADIR_SRC}/xos/base/array.cpp \
$${NADIR_SRC}/xos/base/string_base.cpp \
$${NADIR_SRC}/xos/base/string.cpp \
$${NADIR_SRC}/xos/base/to_string.cpp \
$${NADIR_SRC}/xos/base/exception.cpp \
$${NADIR_SRC}/xos/base/attached.cpp \
$${NADIR_SRC}/xos/base/created.cpp \
$${NADIR_SRC}/xos/base/opened.cpp \
\
$${NADIR_SRC}/xos/io/sequence.cpp \
$${NADIR_SRC}/xos/io/seeker.cpp \
$${NADIR_SRC}/xos/io/array/reader.cpp \
$${NADIR_SRC}/xos/io/told.cpp \
\
$${NADIR_SRC}/xos/lib/nadir/version.cpp \

########################################################################



