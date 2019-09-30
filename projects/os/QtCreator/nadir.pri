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
#   File: nadir.pri
#
# Author: $author$
#   Date: 4/1/2018
#
# Os QtCreator .pri file for nadir
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
NADIR_OS = macosx
} else {
NADIR_OS = linux
}

#CONFIG += c++11
#CONFIG += c++0x

########################################################################
# rostra
ROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${NADIR_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${NADIR_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${NADIR_OS}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${NADIR_LIB}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_NAME} \
-l$${ROSTRA_NAME} \

########################################################################
# nadir

# nadir INCLUDEPATH
#
nadir_INCLUDEPATH += \

# nadir DEFINES
#
nadir_DEFINES += \

# nadir LIBS
#
nadir_LIBS += \
$${rostra_LIBS} \
$${build_nadir_LIBS} \
-lpthread \
-ldl \

contains(NADIR_OS,linux) {
nadir_LIBS += \
-lrt
} else {
}

# nadir11 LIBS
#
nadir11_LIBS += \
$${rostra_LIBS} \
$${build_nadir_LIBS} \
-lpthread \
-ldl \

contains(NADIR_OS,linux) {
nadir11_LIBS += \
-lrt
} else {
}

