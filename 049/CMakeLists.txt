cmake_minimum_required(VERSION 3.16)

project(main CXX)

set(CMAKE_BUILD_TYPE Debug)

# set(CMAKE_CXX_COMPILER /usr/bin/clang++-10)
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++" CACHE STRING "clang++ compiler" FORCE)
# file(GLOB HEADERS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.h")
# file(GLOB SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.cpp")
set(Boost_NO_BOOST_CMAKE OFF)
set(THREADS_PREFER_PTHREAD_FLAG ON)

# find_package(Threads REQUIRED)

# message( ${Boost_INCLUDE_DIR})
# FIND_PACKAGE( Boost 1.71 COMPONENTS circular_buffer REQUIRED )
# INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
add_executable(main most_frequent.h main.cpp)

# target_link_libraries(main PUBLIC "-pthread")

set_property(TARGET main PROPERTY CXX_STANDARD 17)
# TARGET_LINK_LIBRARIES( main LINK_PUBLIC ${Boost_LIBRARIES} )
install(TARGETS main DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})