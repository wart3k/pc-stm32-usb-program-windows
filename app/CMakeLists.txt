# Sources and Headers
set(APP_SOURCES
        "pc-stm32-usb-program-windows.cpp"
)

set(APP_HEADERS
        "pc-stm32-usb-program-windows.h"
)

add_executable(${EXECUTABLE_NAME}
        ${APP_SOURCES}
        ${APP_HEADERS}
)

target_link_libraries(${EXECUTABLE_NAME} PUBLIC
        ${TERMINAL_LOGGER_NAME}
)
