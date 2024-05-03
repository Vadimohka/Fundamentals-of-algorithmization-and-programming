cmake_minimum_required(VERSION 3.27)
project(Lab2Task1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab2Task1 main.cpp
        Sources/Widget.cpp
        Headers/Widget.h
        Sources/Date/Date.cpp
        Headers/Date.h
        Sources/Date/DateService.cpp
        Headers/DateService.h)
target_link_libraries(Lab2Task1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

