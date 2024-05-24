cmake_minimum_required(VERSION 3.27)
project(LAB2_TASK1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(LAB2_TASK1 main.cpp
        widget.h
        widget.cpp
        widget.ui
        Date.h
        Date.cpp

)
target_link_libraries(LAB2_TASK1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
