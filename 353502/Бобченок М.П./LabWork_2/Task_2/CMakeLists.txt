cmake_minimum_required(VERSION 3.27)
project(task2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task2 main.cpp
        qt/main_window.h
        qt/main_window.cpp
        student/student.h
        student/student.cpp)
target_link_libraries(task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

