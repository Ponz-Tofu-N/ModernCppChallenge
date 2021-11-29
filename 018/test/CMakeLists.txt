cmake_minimum_required(VERSION 3.16)

project(main_tst CXX)
find_package(GTest REQUIRED)

add_executable( main_tst tst_variadic.cpp ../variadic.h  )

target_link_libraries(main_tst PRIVATE GTest::GTest GTest::Main)

install(TARGETS main_tst 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})