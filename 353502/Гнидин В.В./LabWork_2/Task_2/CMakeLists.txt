cmake_minimum_required(VERSION 3.28)
project(lab2_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab2_2 main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Person.cpp
        Person.h)
target_link_libraries(lab2_2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

