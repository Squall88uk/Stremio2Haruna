cmake_minimum_required(VERSION 3.16)
project(Stremio2Haruna VERSION 1.1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui DBus)

set(PROJECT_SOURCES
    main.cpp
    stremio2haruna.cpp
    stremio2haruna.h
    configdialog.cpp
    configdialog.h
)

qt_add_executable(stremio2haruna
    ${PROJECT_SOURCES}
    resources.qrc
)

target_link_libraries(stremio2haruna PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
    Qt6::DBus
)

install(TARGETS stremio2haruna
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
