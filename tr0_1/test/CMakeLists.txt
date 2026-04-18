file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
add_executable(complex_calc_tests ${SOURCES})


# if(CMAKE_BUILD_TYPE STREQUAL Coverage)
#     set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
#     set(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
# endif()

if(CMAKE_BUILD_TYPE STREQUAL coverage)
    target_compile_options(complex_calc_tests PRIVATE -Wall -Wextra -Wpedantic --coverage)
    target_link_options(complex_calc_tests PRIVATE --coverage)
else()
    target_compile_options(complex_calc_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

include_directories(complex_calc
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

target_link_libraries(complex_calc_tests
    PRIVATE
        gtest
        gtest_main
        complex_calc
)