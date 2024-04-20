# Copyright 2018 The Min-DevKit Authors. All rights reserved.
# Use of this source code is governed by the MIT License found in the License.md file.

cmake_minimum_required(VERSION 3.0)

set(C74_MIN_API_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../min-api)
include(${C74_MIN_API_DIR}/script/min-pretarget.cmake)


#############################################################
# MAX EXTERNAL
#############################################################

set(CMAKE_XCODE_GENERATE_SCHEME TRUE)


include_directories( 
	"${C74_INCLUDES}"
)


set( SOURCE_FILES
    dsp/onepole.dsp.hpp
    ${PROJECT_NAME}.hpp
    ${PROJECT_NAME}.cpp
)


add_library( 
	${PROJECT_NAME} 
	MODULE
	${SOURCE_FILES}
)


target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set(${PROJECT_NAME}_MAXHELP "\"\${PROJECT_DIR}/help/${PROJECT_NAME}.maxhelp\"")
string(REPLACE "_tilde" "~" ${PROJECT_NAME}_MAXHELP ${${PROJECT_NAME}_MAXHELP})
set_target_properties(${PROJECT_NAME} PROPERTIES
    XCODE_SCHEME_EXECUTABLE "/Applications/Max.app"
    XCODE_SCHEME_ARGUMENTS "${${PROJECT_NAME}_MAXHELP}"
)


include(${C74_MIN_API_DIR}/script/min-posttarget.cmake)


#############################################################
# UNIT TEST
#############################################################

include(${C74_MIN_API_DIR}/test/min-object-unittest.cmake)
