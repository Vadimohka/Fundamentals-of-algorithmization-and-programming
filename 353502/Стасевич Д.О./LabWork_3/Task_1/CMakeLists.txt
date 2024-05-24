cmake_minimum_required(VERSION 3.27)
project(task123)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task123 main.cpp
        mainwindow/mainwindow.cpp
        mainwindow/mainwindow.h
        mainwindow/mainwindow.ui
        Calculate.cpp
        Calculate.h)
target_link_libraries(task123
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

