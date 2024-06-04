cmake_minimum_required(VERSION 3.27)
project(lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab main.cpp
        mainwindow/mainwindow.cpp
        mainwindow/mainwindow.h
        mainwindow/mainwindow.ui
        background/background.cpp
        background/background.h
        movingEllipse/movingEllipse.cpp
        movingEllipse/movingEllipse.h
        baloon/baloon.cpp
        baloon/baloon.h
)
target_link_libraries(lab
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

