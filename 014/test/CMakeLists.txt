cmake_minimum_required(VERSION 3.16)

project(isbn_tst CXX)
find_package(GTest REQUIRED)

add_executable( isbn_tst tst_isbn.cpp ../isbn.cpp  )

target_link_libraries(isbn_tst PRIVATE GTest::GTest GTest::Main)

install(TARGETS isbn_tst 
DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})