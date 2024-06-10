cmake_minimum_required(VERSION 3.28)
project(L8_T2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(L8_T2 main.cpp
        HeapArray.cpp
        HeapArray.h
        HeapList.cpp
        HeapList.h
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui)
target_link_libraries(L8_T2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

