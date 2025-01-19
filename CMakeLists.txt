cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

include(MaxMinAPI.cmake)

parse_package_info(${CMAKE_SOURCE_DIR}/package-info.json)

project(${PACKAGE_NAME}
    VERSION ${PACKAGE_VERSION}
    DESCRIPTION ${PACKAGE_DESCRIPTION}
    HOMEPAGE_URL ${PACKAGE_WEBSITE}
    LANGUAGES CXX
)

add_external(onepole NAME mce.onepole~)
target_compile_features(onepole PRIVATE cxx_std_20)
target_compile_definitions(onepole PRIVATE DSP_NUMBER_TYPE=double)
target_sources(onepole PRIVATE 
    ${CMAKE_SOURCE_DIR}/source/dsp/onepole.dsp.hpp
    ${CMAKE_SOURCE_DIR}/source/mce.onepole_tilde.hpp
    ${CMAKE_SOURCE_DIR}/source/mce.onepole_tilde.cpp
)
target_link_libraries(onepole PRIVATE MinAPI::MinAPI)
