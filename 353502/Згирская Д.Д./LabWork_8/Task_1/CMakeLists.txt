cmake_minimum_required(VERSION 3.26)
project(L8_T1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(L8_T1 main.cpp
        AVLTree.cpp
        AVLTree.h
        Node.cpp
        Node.h
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        Widget.cpp
        Widget.h
        Widget.ui
)
target_link_libraries(L8_T1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

