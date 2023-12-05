# sources and headers
set(TERMINAL_LOGGER_SOURCES
        "InformationProcessing.cpp"
        "TerminalLogger.inl"
)

set(TERMINAL_LOGGER_HEADERS
        "./"
)

# terminal Library
add_library(${TERMINAL_LOGGER_NAME} STATIC
        ${TERMINAL_LOGGER_SOURCES}
)

target_include_directories(${TERMINAL_LOGGER_NAME} PUBLIC
        ${TERMINAL_LOGGER_HEADERS}
)