cmake_minimum_required(VERSION 3.16)

project(main CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(Test)

# テスト有効化
enable_testing()

add_executable(main main.cpp )

# TARGET_LINK_LIBRARIES( main LINK_PUBLIC ${Boost_LIBRARIES} )
install(TARGETS main DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})