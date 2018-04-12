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
#   File: libnadir.pro
#
# Author: $author$
#   Date: 4/1/2018
#
# QtCreator .pro file for nadir library libnadir
########################################################################
include(../../../../../build/QtCreator/nadir.pri)
include(../../../../QtCreator/nadir.pri)
include(../../nadir.pri)
include(../../../../QtCreator/lib/libnadir/libnadir.pri)

TARGET = $${libnadir_TARGET}
TEMPLATE = $${libnadir_TEMPLATE}
CONFIG += $${libnadir_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libnadir_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libnadir_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libnadir_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
SOURCES += \
$${libnadir_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libnadir_HEADERS} \

# SOURCES
#
SOURCES += \
$${libnadir_SOURCES} \
$${OBJECTIVE_SOURCES} \

########################################################################


