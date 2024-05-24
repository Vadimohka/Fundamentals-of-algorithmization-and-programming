cmake_minimum_required(VERSION 3.27)
project(galava)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(galava main.cpp
        main_window/main_window.cpp
        main_window/main_window.h
        main_window/main_window.ui
        movingEllipse.cpp
        movingEllipse.h
        background.cpp
        background.h
        face.cpp
        face.h
)
target_link_libraries(galava
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

