cmake_minimum_required(VERSION 3.27)
project(paintDegrodated)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(paintDegrodated main.cpp
        main_window/main_window.cpp
        main_window/main_window.h
        main_window/main_window.ui
        main_window/src/figures/star.cpp
        main_window/src/figures/star.h
        main_window/src/paintScene.cpp
        main_window/src/paintScene.h
)
target_link_libraries(paintDegrodated
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

