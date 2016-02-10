cmake_minimum_required(VERSION 3.3)
project(GraphDrawingTests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ConvertEquation.h)
add_executable(GraphDrawingTests ${SOURCE_FILES})

target_link_libraries(GraphDrawingTests symbolicc++)