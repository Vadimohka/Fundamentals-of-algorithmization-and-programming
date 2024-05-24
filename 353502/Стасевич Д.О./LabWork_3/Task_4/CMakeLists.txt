cmake_minimum_required(VERSION 3.27)
project(task4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task4 main.cpp
        mainwindow/mainwindow.cpp
        mainwindow/mainwindow.h
        mainwindow/mainwindow.ui
        hanoi/Hanoi.cpp
        hanoi/Hanoi.h
        animation/MovingRectangle.cpp
        animation/MovingRectangle.h
        animation/TowersBase.cpp
        animation/TowersBase.h)
target_link_libraries(task4
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

