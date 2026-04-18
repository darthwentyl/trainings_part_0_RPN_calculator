cmake_minimum_required(VERSION 3.28.3)

project(calculator_lib VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES Calculator.cpp)

add_library(calculator_lib SHARED ${SOURCES})

target_include_directories(calculator_lib PUBLIC .)

set_target_properties(calculator_lib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)