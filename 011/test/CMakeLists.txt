cmake_minimum_required(VERSION 3.16)

project(roman_tst CXX)
find_package(GTest REQUIRED)

add_executable(roman_tst tst_roman.cpp)

target_link_libraries(roman_tst PRIVATE GTest::GTest GTest::Main)

install(TARGETS roman_tst 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})