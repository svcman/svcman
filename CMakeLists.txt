cmake_minimum_required(VERSION 3.5)

project(svcman VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(sdbus-c++ REQUIRED)

#pkg_check_modules(
#    SYSTEMD REQUIRED libsystemd
#)

include_directories(${SYSTEMD_INCLUDE_DIRS})

set(PROJECT_SOURCES
        src/main.cpp
        src/svcviewer.cpp
        src/svcviewer.h
        src/svcviewer.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(svcman
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/sd_handler.h src/sd_handler.cpp

    )
else()
    add_executable(svcman
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(svcman
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    PRIVATE SDBusCpp::sdbus-c++
)

include(GNUInstallDirs)
install(TARGETS svcman
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(svcman)
endif()
