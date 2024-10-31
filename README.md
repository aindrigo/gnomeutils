# GnomeUtils
My utility library, intended for cross-platform usage.

# Building
## Requirements
* CMake
* g++
* gcc
* make/mingw32-make
* conan(.io)

First, from the main directory run `conan install . -sbuild_Type=(Debug/Release)`.
After that, run `conan build .` to build. Output files are in "build/(Debug/Release)"
