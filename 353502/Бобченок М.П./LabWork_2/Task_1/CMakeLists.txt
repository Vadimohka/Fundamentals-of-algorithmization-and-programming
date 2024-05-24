cmake_minimum_required(VERSION 3.27)
project(task1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task1 main.cpp
        qt/main_window.h
        qt/main_window.cpp
        Date/Date.cpp)
target_link_libraries(task1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

