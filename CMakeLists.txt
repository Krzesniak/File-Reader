# cmake_minimum_required(VERSION <specify CMake version here>)
project(file_reader)

set(CMAKE_CXX_STANDARD 14)

add_executable(file_reader main.cpp FileReader.cpp FileReader.h)