cmake_minimum_required(VERSION 3.16)

project(main_tst CXX)

set(CMAKE_BUILD_TYPE Debug)

add_executable( main_tst tst_numberplate.cpp ../numberplate.h  )

find_package(GTest REQUIRED)
target_link_libraries(main_tst PRIVATE GTest::GTest GTest::Main)

install(TARGETS main_tst 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})