cmake_minimum_required(VERSION 3.5)

project(calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# without this option I had error "no such file or directory" in ui_mainwindow.h
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(INCLUDE_DIR lib)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(calculator
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        keyswidget.h keyswidget.cpp keyswidget.ui
        displaywidget.h displaywidget.cpp displaywidget.ui

        tokenemiter.h tokenemiter.cpp
        icalculatordevice.h
        myhex.h myhex.cpp
        lib/Calculator.h lib/libcalculator_lib.so.1.0 lib/libcalculator_lib.so.1.0 lib/libcalculator_lib.so.1.0
        calculatordevice.h calculatordevice.cpp
        myhexparser.h myhexparser.cpp
        errormessagebox.h errormessagebox.cpp
        ierrormessage.h

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET calculator APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(calculator SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(calculator
            ${PROJECT_SOURCES}
        )
    endif()
endif()

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(calculator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${CMAKE_CURRENT_SOURCE_DIR}/lib/libcalculator_lib.so)
target_include_directories(calculator PRIVATE ${INCLUDE_DIR})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.calculator)
endif()
set_target_properties(calculator PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS calculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(calculator)
endif()
