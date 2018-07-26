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
#   File: Makefile
#
# Author: $author$
#   Date: 7/23/2018
#
# build Gcc Makefile for nadir
########################################################################


########################################################################
# rostra
#
# pkg-config --cflags --libs rostra
#

ifndef USE_HOME_BUILD_rostra
USE_HOME_BUILD_rostra = no
endif

ifeq ($(USE_HOME_BUILD_rostra),yes)
#
# home build rostra
#
build_rostra_USRDEFINES += \

build_rostra_USRINCLUDES += \
-I$(HOME)/build/rostra/include \

build_rostra_USRCXXFLAGS += \

build_rostra_USRLIBDIRS += \
-L$(HOME)/build/rostra/lib \

build_rostra_LIBS += \
-lrostra \

build_rostra_FRAMEWORKS += \

else
#
# build rostra
#
build_rostra_USRDEFINES += \

build_rostra_USRINCLUDES += \

build_rostra_USRCXXFLAGS += \

build_rostra_USRLIBDIRS += \

build_rostra_LIBS += \

build_rostra_FRAMEWORKS += \

endif

########################################################################
# nadir

# build nadir USRDEFINES
#
build_nadir_USRDEFINES += \
${build_rostra_USRDEFINES} \


# build nadir USRINCLUDES
#
build_nadir_USRINCLUDES += \
${build_rostra_USRINCLUDES} \


# build nadir USRCXXFLAGS
#
build_nadir_USRCXXFLAGS += \
${build_rostra_USRCXXFLAGS} \


# build nadir USRLIBDIRS
#
build_nadir_USRLIBDIRS += \
${build_rostra_USRLIBDIRS} \


# build nadir FRAMEWORKS
#
build_nadir_FRAMEWORKS += \
${build_rostra_FRAMEWORKS} \


# build nadir LIBS
#
build_nadir_LIBS += \
${build_rostra_LIBS} \
${build_nadir_FRAMEWORKS}


