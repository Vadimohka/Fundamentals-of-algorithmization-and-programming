cmake_minimum_required(VERSION 3.28)
project(L7_T3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(L7_T3 main.cpp
        HashTable.cpp
        HashTable.h
        Stek.cpp
        Stek.h
        StekNode.cpp
        StekNode.h
        Widget.cpp
        Widget.h
        Widget.ui
)
target_link_libraries(L7_T3
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

