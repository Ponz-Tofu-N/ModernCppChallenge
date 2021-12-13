cmake_minimum_required(VERSION 3.16)

project(main CXX)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES main.cpp 
            hexutils.h) 

add_executable(main ${SOURCES})

install(TARGETS main 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})