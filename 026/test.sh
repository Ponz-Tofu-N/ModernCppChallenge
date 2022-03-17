#!/bin/sh
# for basic cmake build
# required CMake 3.15 or after
# set build directory

TST_DIR="test"
TST_BUILD_DIR="test/build"
TST_EXEC="main_tst"

cmake -S ${TST_DIR} -B ${TST_BUILD_DIR}
cmake --build ${TST_BUILD_DIR}
cmake --install ${TST_BUILD_DIR}

${TST_DIR}/main_tst