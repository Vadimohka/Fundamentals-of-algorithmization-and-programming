cmake_minimum_required(VERSION 3.27)
project(lab6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/acryoz/Qt/5.15.16/gcc_64/bin")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab6 main.cpp
        lib/smartphone.cpp
        include/smartphone.h
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui)
target_link_libraries(lab6
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

add_executable(task2 main2.cpp
        lib/smartphone.cpp
        include/smartphone.h
        src2/mainwindow.cpp
        src2/mainwindow.h
        src2/mainwindow2.ui)
target_link_libraries(task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
