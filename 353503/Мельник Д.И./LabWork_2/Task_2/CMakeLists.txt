cmake_minimum_required(VERSION 3.27)
project(lab2_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/dmitry/Qt/6.6.1/gcc_64/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab2_2
        main.cpp
        mainwindow.cpp
        mainwindow.h
        table.cpp
        table.h
        book.cpp
        book.h
        mainwindow.ui
)

target_link_libraries(lab2_2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

