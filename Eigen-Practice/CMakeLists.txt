cmake_minimum_required(VERSION 3.5.1)  # CMake version check
project(eigen_practice)               # Create project "simple_example"

# Include Libraries 
include_directories("/usr/local/Cellar/eigen/3.3.7/include/eigen3")
 
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(eigen_practice eigen_practice.cpp)
 
SET(CMAKE_CXX_FLAGS "-std=c++0x")
