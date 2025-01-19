include(FetchContent)
FetchContent_Declare(
  max_cmake_modules
  GIT_REPOSITORY https://github.com/ascii255/max-cmake-modules.git
  GIT_TAG        f0aed5865e074736315c83dd4da87b6337c5be6d
  SYSTEM
)
FetchContent_MakeAvailable(max_cmake_modules)

set(MaxCMakeModules_ROOT ${max_cmake_modules_SOURCE_DIR})

list(APPEND CMAKE_MODULE_PATH ${MaxCMakeModules_ROOT}/Modules)
include(Max/ParsePackageInfo)
include(Max/AddExternal)
include(Max/AddSigning)
include(Max/GeneratePackageDMG)

include(FindPackageHandleStandardArgs)
file(READ ${MaxCMakeModules_ROOT}/CMakeLists.txt MaxCMakeModules_CMAKE_LISTS_STRING)
string(REGEX REPLACE
  ".*MaxCMakeModules VERSION ([0-9]+)\.([0-9]+)\.([0-9]+).*"
  "\\1.\\2.\\3"
  MaxCMakeModules_VERSION
  ${MaxCMakeModules_CMAKE_LISTS_STRING}
)
unset(MaxCMakeModules_CMAKE_LISTS_STRING)
cmake_path(ABSOLUTE_PATH MaxCMakeModules_ROOT NORMALIZE OUTPUT_VARIABLE MaxCMakeModules_PATH)
cmake_path(RELATIVE_PATH MaxCMakeModules_PATH BASE_DIRECTORY ${CMAKE_SOURCE_DIR})
find_package_handle_standard_args(MaxCMakeModules
  REQUIRED_VARS MaxCMakeModules_PATH
  VERSION_VAR MaxCMakeModules_VERSION
)
unset(MaxCMakeModules_PATH)
