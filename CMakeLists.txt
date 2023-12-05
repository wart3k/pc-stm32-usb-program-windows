cmake_minimum_required(VERSION 3.26)

project(
        pc-stm32-usb-program-windows
        VERSION 0.0.1
        LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD          23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CMAKE_C_STANDARD            23)
set(CMAKE_C_STANDARD_REQUIRED   ON)
set(CMAKE_C_EXTENSIONS          OFF)

set(EXECUTABLE_NAME             "pc-stm32-usb-program-windows")

add_subdirectory(app)