cmake_minimum_required(VERSION 3.16)

project(main CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# add_subdirectory(Test)

include(FetchContent)
FetchContent_Declare(
  pugixml
  GIT_REPOSITORY https://github.com/zeux/pugixml.git
  GIT_TAG v1.13)
FetchContent_MakeAvailable(pugixml)

# テスト有効化
enable_testing()

add_executable(main main.cpp)

target_link_libraries(main PRIVATE pugixml)
target_include_directories(main PUBLIC ${pugixml_SOURCE_DIR}/src)

# TARGET_LINK_LIBRARIES( main LINK_PUBLIC ${Boost_LIBRARIES} )
install(TARGETS main DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})