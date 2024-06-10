cmake_minimum_required(VERSION 3.25)
project(Lab5Task1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab5Task1 main.cpp
        widget.cpp
        widget.h
        widget.ui
        display.cpp
        display.h
        display.ui
        keyboard.cpp
        keyboard.h
        keyboard.ui
        keyPress.cpp)
target_link_libraries(Lab5Task1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

