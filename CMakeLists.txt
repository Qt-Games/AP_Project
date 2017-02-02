cmake_minimum_required(VERSION 3.5)
project(AP_Project)

include(QtCommon.cmake)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.3.1\\5.3\\mingw482_32")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE GEN_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp" "Source/*.c" "Source/*.cpp" "/Source/*.cc" "/Source/*.cxx")
file(GLOB_RECURSE GEN_HEADER_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.h" "Source/*.hpp")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#list(APPEND CMAKE_CXX_FLAGS "-pthread -std=c++11 ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

set(SOURCE_FILES
        ${GEN_HEADER_FILES}
        ${GEN_SOURCE_FILES})

add_executable(AP_Project ${SOURCE_FILES})

find_package(Qt5Widgets REQUIRED)

qt5_use_modules(${PROJECT_NAME} Widgets)