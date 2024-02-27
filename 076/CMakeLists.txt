cmake_minimum_required(VERSION 3.16)

project(main CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# add_subdirectory(Test)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

# テスト有効化
enable_testing()

add_executable(main main.cc movie.h movie_json.h)

target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json )

target_include_directories(main PUBLIC ${json_SOURCE_DIR}/src/single_include)

# TARGET_LINK_LIBRARIES( main LINK_PUBLIC ${Boost_LIBRARIES} )
install(TARGETS main DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})