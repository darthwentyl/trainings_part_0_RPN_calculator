cmake_minimum_required(VERSION 3.16)
project(calculator_tests LANGUAGES CXX)

find_package(Qt6 COMPONENTS Test REQUIRED)
qt_standard_project_setup()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OUTPUT_NAME)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(GTest REQUIRED)

include_directories(calculator_tests
    ${CMAKE_CURRENT_SOURCE_DIR}/../calculator
    ${CMAKE_CURRENT_SOURCE_DIR}/../calculator/lib
    ${GTEST_INCLUDE_DIRS}
)

add_executable(calculator_tests
    main.cpp
    KeysWidgetTests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../calculator/keyswidget.cpp
    MainWindowTests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../calculator/mainwindow.cpp
    DisplayWidgetTests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../calculator/displaywidget.cpp
    TokenEmiterTests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../calculator/tokenemiter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../calculator/calculatordevice.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../calculator/errormessagebox.cpp
    MyHexTests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../calculator/myhex.cpp
    MyHexParserTests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../calculator/myhexparser.cpp
)

include(GNUInstallDirs)

if(CMAKE_BUILD_TYPE STREQUAL coverage)
    target_compile_options(calculator_tests PRIVATE -Wall -Wextra -Wpedantic --coverage)
    target_link_options(calculator_tests PRIVATE --coverage)
else()
    target_compile_options(calculator_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()


link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../calculator/lib)
target_link_libraries(calculator_tests PRIVATE
    Qt6::Test Qt6::Widgets
    ${CMAKE_CURRENT_SOURCE_DIR}/../calculator/lib/libcalculator_lib.so
    gtest
    gmock
    gtest_main
)

add_test(NAME calculator_tests COMMAND calculator_tests)