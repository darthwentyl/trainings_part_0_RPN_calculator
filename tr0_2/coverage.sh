#!/bin/bash

BUILD_DIR="build_coverage"
OUTPUT_STAT="coverage"
if [ -d ${BUILD_DIR} ]; then
    rm -rf ${BUILD_DIR}
fi
mkdir -p ${BUILD_DIR}
cd ${BUILD_DIR}
cmake -DCMAKE_BUILD_TYPE=coverage ..
make -j8
./tests/generic_calc_tests
find . -name '*.gcda' | xargs gcov -d
lcov --ignore mismatch --directory . --capture --output-file coverage.info
genhtml -o ${OUTPUT_STAT} coverage.info
firefox ${OUTPUT_STAT}/index.html &> /dev/null &