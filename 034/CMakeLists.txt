cmake_minimum_required(VERSION 3.16)

project(main CXX)

set(CMAKE_BUILD_TYPE Debug)


set(SOURCES main.cpp
remove_blank_line.h) 

add_executable(main ${SOURCES})

target_compile_features(main PUBLIC cxx_std_17)

install(TARGETS main 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})