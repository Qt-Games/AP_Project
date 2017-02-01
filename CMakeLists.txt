cmake_minimum_required(VERSION 3.5)
project(AP_Project)

include(QtCommon.cmake)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.3.1\\5.3\\mingw482_32")
set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        playerplane.cpp
        playerplane.h)

add_executable(AP_Project ${SOURCE_FILES})

find_package(Qt5Widgets REQUIRED)

qt5_use_modules(${PROJECT_NAME} Widgets)