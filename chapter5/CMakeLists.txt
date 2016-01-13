cmake_minimum_required(VERSION 3.3)
project(chapter5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Stack.cpp Stack.h LIFO_Stack.cpp LIFO_Stack.h)
add_executable(chapter5 ${SOURCE_FILES})