cmake_minimum_required (VERSION 3.30)

project (GnomeUtils VERSION 1.0 LANGUAGES CXX)

set (GNOMEUTILS_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE FILEPATH "GnomeUtils include directory")
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_library (GnomeUtils STATIC vtable.cpp sharedobject.cpp functions.cpp)

target_include_directories (GnomeUtils PRIVATE $CACHE{GNOMEUTILS_INCLUDE_DIR})
