#!/bin/sh
# for basic cmake build
# required CMake 3.15 or after
# set build directory
BUILD_DIR="build"

cmake -S . -B ${BUILD_DIR}
cmake --build ${BUILD_DIR}
cmake --install ${BUILD_DIR}