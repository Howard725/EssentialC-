cmake_minimum_required(VERSION 3.3)
project(chapter3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(chapter3 ${SOURCE_FILES})