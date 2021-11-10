cmake_minimum_required(VERSION 3.16)

project(main CXX)

add_executable(main 
            main.cpp 
            # abundant.cpp
            )

install(TARGETS main 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})