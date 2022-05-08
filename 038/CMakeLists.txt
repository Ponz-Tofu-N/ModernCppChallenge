cmake_minimum_required(VERSION 3.16)

project(main CXX)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES main.cpp
logger.h) 

add_executable(main ${SOURCES})

target_link_libraries(
    main
${Boost_PROGRAM_OPTIONS_LIBRARY}
)

set_property(TARGET main PROPERTY CXX_STANDARD 20)
# target_compile_features(main PUBLIC cxx_std_20)

install(TARGETS main 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})