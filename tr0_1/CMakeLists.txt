cmake_minimum_required(VERSION 3.28.3)

project(complex_calc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")

enable_testing()
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/test")