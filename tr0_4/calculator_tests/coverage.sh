#!/bin/bash

BUILD_DIR="build_coverage"
OUTPUT_STAT="coverage"
NUMBER_OF_CPUS="$(nproc --all)"
if [ -d ${BUILD_DIR} ]; then
    rm -rf ${BUILD_DIR}
fi
mkdir -p ${BUILD_DIR}
cd ${BUILD_DIR}
cmake -DCMAKE_BUILD_TYPE=coverage ..
make -j${NUMBER_OF_CPUS}
./calculator_tests
find . -name '*.gcda' | xargs gcov -d
lcov --ignore mismatch --directory . --capture --output-file coverage.info
lcov --extract coverage.info '*/calculator/*' --output-file coverage.src-all.info
lcov --remove coverage.src-all.info '*/lib/*' --output-file coverage.src-only.info
genhtml -o ${OUTPUT_STAT} coverage.src-only.info
firefox ${OUTPUT_STAT}/index.html &> /dev/null &
