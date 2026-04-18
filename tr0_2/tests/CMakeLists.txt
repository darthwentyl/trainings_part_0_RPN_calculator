file(GLOB SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/parsers/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/numbers/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/mocks/numbers/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/mocks/parsers/*.cpp"
)
add_executable(generic_calc_tests ${SOURCES})

if(CMAKE_BUILD_TYPE STREQUAL coverage)
    target_compile_options(generic_calc_tests PRIVATE -Wall -Wextra -Wpedantic --coverage)
    target_link_options(generic_calc_tests PRIVATE --coverage)
else()
    target_compile_options(generic_calc_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

include_directories(generic_calc
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
        ${CMAKE_CURRENT_SOURCE_DIR}/mocks
)

target_link_libraries(generic_calc_tests
    PRIVATE
        gtest
        gmock
        gtest_main
        generic_calc
)