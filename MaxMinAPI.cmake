include(MaxCMakeModules.cmake)

FetchContent_Declare(
  min_api
  GIT_REPOSITORY https://github.com/Cycling74/min-api.git
  GIT_TAG        663c117c4b1df804e7b254ba9d655b71bfb63e77
  SOURCE_SUBDIR  FALSE
)
FetchContent_MakeAvailable(min_api)

find_package(MinAPI MODULE REQUIRED)
