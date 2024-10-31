cmake_minimum_required (VERSION 3.30)

project (GnomeUtils VERSION 1.0 LANGUAGES CXX)

set (GNOMEUTILS_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_library (gnomeutils STATIC src/core.cpp)

target_link_libraries (gnomeutils PRIVATE ${GNOMEUTILS_LIBRARIES})
target_include_directories (gnomeutils PRIVATE ${GNOMEUTILS_INCLUDE_DIR})
