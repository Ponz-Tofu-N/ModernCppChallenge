cmake_minimum_required(VERSION 3.16)

project(main CXX)

set(SOURCES main.cpp 
            array2d.h) 

add_executable(main ${SOURCES})

install(TARGETS main 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})