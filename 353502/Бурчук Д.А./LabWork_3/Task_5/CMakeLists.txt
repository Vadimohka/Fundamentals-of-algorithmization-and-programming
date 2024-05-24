cmake_minimum_required(VERSION 3.27)
project(Lab3Task5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab3Task5 main.cpp
        FileCounter.cpp
        FileCounter.h)
target_link_libraries(Lab3Task5
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

