cmake_minimum_required(VERSION 3.27)
project(QTProjects)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(QTProjects Sources/main.cpp
        Sources/Fire.cpp
        Headers/Fire.h
        Sources/MovingLine.cpp
        Headers/MovingLine.h
        Sources/Rocket.cpp
        Headers/Rocket.h
        Sources/Widget.cpp
        Headers/Widget.h
        Headers/inclusions.h)
target_link_libraries(QTProjects
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

