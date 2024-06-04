cmake_minimum_required(VERSION 3.27)
project(task2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task2 main.cpp
        mainwindow/mainwindow.cpp
        mainwindow/mainwindow.h
        mainwindow/mainwindow.ui
        objects/Firm.cpp
        objects/Firm.h
        objects/Candidate.cpp
        objects/Candidate.h)
target_link_libraries(task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

