# Copyright 2015 CNRS-LAAS
#
# Author: Joseph Mirabel
#
# This file is part of hpp-wholebody-setp
# hpp-model-urdf is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# hpp-wholebody-setp is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Lesser Public License for more details.
# You should have received a copy of the GNU Lesser General Public License
# along with hpp-wholebody-setp  If not, see <http://www.gnu.org/licenses/>.

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

ADD_OPTIONAL_DEPENDENCY("hrp2_14_description")
ADD_OPTIONAL_DEPENDENCY("hpp-model")
ADD_OPTIONAL_DEPENDENCY("hpp-model-urdf")

# Make Boost.Test generates the main function in test cases.
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN)

# ADD_TESTCASE(NAME)
# ------------------------
#
# Define a test named `NAME'.
#
# This macro will create a binary from `NAME.cc', link it against
# Boost and add it to the test suite.
#
MACRO(ADD_TESTCASE NAME GENERATED)
  IF (${GENERATED} STREQUAL TRUE)
    ADD_EXECUTABLE(${NAME} ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.cc)
  ELSE()
    ADD_EXECUTABLE(${NAME} ${NAME}.cc)
  ENDIF()
  ADD_TEST(${NAME} ${RUNTIME_OUTPUT_DIRECTORY}/${NAME})

  PKG_CONFIG_USE_DEPENDENCY(${NAME} hpp-core)
  PKG_CONFIG_USE_DEPENDENCY(${NAME} hpp-constraints)

  # Link against Boost and project library.
  TARGET_LINK_LIBRARIES(${NAME}
    ${Boost_LIBRARIES}
    ${PROJECT_NAME}
    )

ENDMACRO(ADD_TESTCASE)

IF (HRP2_14_DESCRIPTION_FOUND AND HPP_MODEL_FOUND AND HPP_MODEL_URDF_FOUND)
  ADD_TESTCASE (hrp2 FALSE)
  PKG_CONFIG_USE_DEPENDENCY(hrp2 hpp-model)
  PKG_CONFIG_USE_DEPENDENCY(hrp2 hpp-model-urdf)
ENDIF (HRP2_14_DESCRIPTION_FOUND AND HPP_MODEL_FOUND AND HPP_MODEL_URDF_FOUND)
