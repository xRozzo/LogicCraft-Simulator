cmake_minimum_required(VERSION 3.20)
project(nanotekspice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the header files from the include directory
include_directories(include)

# Automatically find all .cpp files in the sources directory and its subdirectories
file(GLOB_RECURSE SOURCES "sources/*.cpp")

# Create an executable based on the found source files
add_executable(nanotekspice ${SOURCES})
