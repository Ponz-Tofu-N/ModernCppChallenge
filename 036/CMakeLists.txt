cmake_minimum_required(VERSION 3.16)

project(main CXX)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES main.cpp
directory.h) 

add_executable(main ${SOURCES})

set_property(TARGET main PROPERTY CXX_STANDARD 20)
# target_compile_features(main PUBLIC cxx_std_20)

install(TARGETS main 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})