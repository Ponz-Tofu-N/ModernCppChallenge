cmake_minimum_required(VERSION 3.16)

project(tst_roman CXX)
find_package(GTest REQUIRED)

add_executable(tst_roman tst_roman.cpp)

target_link_libraries(tst_roman PRIVATE GTest::GTest GTest::Main)

install(TARGETS tst_roman 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})