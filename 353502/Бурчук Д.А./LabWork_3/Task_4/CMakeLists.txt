cmake_minimum_required(VERSION 3.27)
project(Lab3Task4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab3Task4 main.cpp
        Sources/Widget.cpp
        Headers/Widget.h
        Sources/TowerOfHanoi/TowerOfHanoi.cpp
        Headers/TowerOfHanoi.h
        Sources/TowerOfHanoi/Ring.cpp
        Headers/Ring.h





)
target_link_libraries(Lab3Task4
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

