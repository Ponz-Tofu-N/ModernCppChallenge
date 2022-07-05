cmake_minimum_required(VERSION 3.16)

project(main_tst CXX)

set(CMAKE_BUILD_TYPE Debug)

add_executable(main_tst tst_double_buffer.cpp ../double_buffer.h)

find_package(GTest REQUIRED)
target_link_libraries(main_tst PRIVATE GTest::GTest GTest::Main)
target_compile_features(main_tst PUBLIC cxx_std_17)

install(TARGETS main_tst
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})