# Sources and Headers
set(EXECUTABLE_SOURCE
        "pc-stm32-usb-program-windows.cpp"
)

set(EXECUTABLE_INCLUDES
        "./"
)

add_executable(${EXECUTABLE_NAME}
        ${EXECUTABLE_SOURCE}
        ${EXECUTABLE_INCLUDES}
)