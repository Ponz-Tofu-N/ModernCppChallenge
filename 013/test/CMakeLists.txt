cmake_minimum_required(VERSION 3.16)

project(pi_tst CXX)
find_package(GTest REQUIRED)

add_executable( pi_tst tst_pi.cpp ../pi.cpp )

target_link_libraries(pi_tst PRIVATE GTest::GTest GTest::Main)

install(TARGETS pi_tst 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})