cmake_minimum_required(VERSION 3.28)
project(LabWork_6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(LabWork_6 main.cpp
        SportTeam/SportTeam.cpp
        SportTeam/SportTeam.h)
target_link_libraries(LabWork_6
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

add_executable(Task2 task2.cpp)
Target_link_libraries(Task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
