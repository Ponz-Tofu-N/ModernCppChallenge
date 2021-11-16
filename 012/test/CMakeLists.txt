cmake_minimum_required(VERSION 3.16)

project(collatz_tst CXX)
find_package(GTest REQUIRED)

add_executable( collatz_tst tst_collatz.cpp ../collatz.cpp )

target_link_libraries(collatz_tst PRIVATE GTest::GTest GTest::Main)

install(TARGETS collatz_tst 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})