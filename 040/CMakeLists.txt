cmake_minimum_required(VERSION 3.16)

project(main CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_COMPILER /usr/bin/g++-11)

file(GLOB HEADERS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.h") 
file(GLOB SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.cpp") 

add_executable(main ${HEADERS} ${SOURCES})

target_link_libraries(main ${Boost_PROGRAM_OPTIONS_LIBRARY})

set_property(TARGET main PROPERTY CXX_STANDARD 20)

install(TARGETS main DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})