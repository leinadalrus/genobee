cmake_minimum_required(VERSION 3.15)
project(genobee)
set(CMAKE_CXX_STANDARD 14)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES ./genobee.cxx)

find_package(ZLIB REQUIRED)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(genobee ${SOURCE_FILES})