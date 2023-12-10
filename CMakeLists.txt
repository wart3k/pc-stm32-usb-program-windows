cmake_minimum_required(VERSION 3.26)

project(
        pc-stm32-usb-program-windows
        VERSION 0.0.1
        LANGUAGES C CXX
)

# global cmake variables
set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CMAKE_C_STANDARD            17)
set(CMAKE_C_STANDARD_REQUIRED   ON)
set(CMAKE_C_EXTENSIONS          OFF)

# project and library names
set(EXECUTABLE_NAME             pc-stm32-usb-program-windows)
set(BASICS_LIB_NAME             basics-lib)

# check if git package is available
#include(FetchContent)
#
#FetchContent_Declare(
#        spdlog
#        GIT_REPOSITORY  https://github.com/gabime/spdlog
#        GIT_TAG         v1.12.0
#        GIT_SHALLOW     TRUE
#)
#FetchContent_MakeAvailable(spdlog)

# sub directories
add_subdirectory(basics)
add_subdirectory(app)