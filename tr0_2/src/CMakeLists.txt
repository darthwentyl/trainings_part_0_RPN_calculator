file(GLOB SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/parsers/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/numbers/*.cpp"
)
add_library(generic_calc ${SOURCES})

if(CMAKE_BUILD_TYPE STREQUAL coverage)
    target_compile_options(generic_calc PRIVATE -Wall -Wextra -Wpedantic --coverage)
    target_link_options(generic_calc PRIVATE --coverage)
else()
    target_compile_options(generic_calc PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_include_directories(generic_calc
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
