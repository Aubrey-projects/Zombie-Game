# The purpose of this text file is to make it easier to build and compile the program.

# This is the minimum version of CMake that you need
cmake_minimum_required(VERSION 3.16)

# This is the project name (CXX means C++)
project(ZombieGame CXX)

# This uses C++17 or errors if the compiler can't do it
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This will gather all .cpp files under the src folder so that you don't need to manually list them
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# From the gathered files, this will make the game executable
add_executable(game ${SOURCES})

# This allows you to write #include "core.World.h" from anywhere under src, making life a lot easier
target_include_directories(game PRIVATE src)