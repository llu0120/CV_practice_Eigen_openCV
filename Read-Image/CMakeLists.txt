cmake_minimum_required(VERSION 3.5.1)  # CMake version check
project(read_image)               # Create project "simple_example"

# Include Libraries 
include_directories("/usr/local/Cellar/eigen/3.3.7/include/eigen3")
include_directories("/usr/local/Cellar/opencv/4.3.0_5/include/opencv4") 
 
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(read_image read_image.cpp)
 
SET(CMAKE_CXX_FLAGS "-std=c++0x")
