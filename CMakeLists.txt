cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/source/cmake ${CMAKE_SOURCE_DIR}/source/cmake/Max/FindModules)

include(Max/ParsePackageInfo)
parse_package_info(${CMAKE_SOURCE_DIR}/package-info.json)

project(${PACKAGE_NAME}
    VERSION ${PACKAGE_VERSION}
    DESCRIPTION ${PACKAGE_DESCRIPTION}
    HOMEPAGE_URL ${PACKAGE_WEBSITE}
    LANGUAGES CXX
)

find_package(MinAPI REQUIRED)

include(Max/AddExternal)
add_external(onepole mce.onepole~)
target_compile_features(onepole PRIVATE cxx_std_20)
target_sources(onepole PRIVATE 
    ${CMAKE_SOURCE_DIR}/source/dsp/onepole.dsp.hpp
    ${CMAKE_SOURCE_DIR}/source/mce.onepole_tilde.hpp
    ${CMAKE_SOURCE_DIR}/source/mce.onepole_tilde.cpp
)
target_link_libraries(onepole PRIVATE MinAPI::MinAPI)

set(CMAKE_XCODE_GENERATE_SCHEME TRUE)
set_target_properties(onepole PROPERTIES
    XCODE_SCHEME_EXECUTABLE "/Applications/Max.app"
    XCODE_SCHEME_ARGUMENTS "\"\${PROJECT_DIR}/help/mce.onepole~.maxhelp\""
)
