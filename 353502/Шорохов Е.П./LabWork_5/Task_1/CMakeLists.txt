cmake_minimum_required(VERSION 3.28)
project(LabWork_5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(LabWork_5 main.cpp
        MainWindow/MainWindow.cpp
        MainWindow/MainWindow.h
        Russian/Rus.cpp
        Russian/Rus.h
        string/string.cpp
        string/string.h
        )
add_executable(Task2
        Bitset.cpp)
target_link_libraries(LabWork_5
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
target_link_libraries(Task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
