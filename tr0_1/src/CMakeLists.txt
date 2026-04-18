file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
add_library(complex_calc ${SOURCES})

if(CMAKE_BUILD_TYPE STREQUAL coverage)
    target_compile_options(complex_calc PRIVATE -Wall -Wextra -Wpedantic --coverage)
    target_link_options(complex_calc PRIVATE --coverage)
else()
    target_compile_options(complex_calc PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_include_directories(complex_calc
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
