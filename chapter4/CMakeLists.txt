cmake_minimum_required(VERSION 3.3)
project(chapter4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Stack.cpp Stack.h Global.cpp Global.h Matrix.cpp Matrix.h)
add_executable(chapter4 ${SOURCE_FILES})