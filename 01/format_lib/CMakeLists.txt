project(format_lib)

set(LIB_SOURCES excel_format.cpp)

add_library(format_lib STATIC ${LIB_SOURCES})

message(STATUS ${CMAKE_SOURCE_DIR} ${SOME_VAL})
message(STATUS ../src)
target_include_directories(format_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
