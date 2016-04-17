cmake_minimum_required(VERSION 3.3)
project(GraphDrawingTests)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ConvertEquation.h ReadEquation.h MainWindow.cpp MainWindow.h GraphGraphicsScene.cpp GraphGraphicsScene.h)
add_executable(GraphDrawingTests ${SOURCE_FILES})

find_package(Qt5Core REQUIRED)
find_package(Qt5widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Sql REQUIRED)

qt5_use_modules( GraphDrawingTests Core Widgets Gui Sql )
target_link_libraries( GraphDrawingTests )