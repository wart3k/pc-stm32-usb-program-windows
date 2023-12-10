# sources and headers
set(BASICS_LIB_SOURCES
        "InformationProcessing.cpp"
        "Log.cpp"
)

set(BASICS_LIB_HEADERS
        "./"
)

# terminal Library
add_library(${BASICS_LIB_NAME} STATIC
        ${BASICS_LIB_SOURCES}
)

target_include_directories(${BASICS_LIB_NAME} PUBLIC
        ${BASICS_LIB_HEADERS}
)

#target_link_directories(${BASICS_LIB_NAME} PUBLIC
#        spdlog::spdlog
#)