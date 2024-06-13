cmake_minimum_required(VERSION 3.28)
project(LabWork_8)

#shue pppsh
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(LabWork_8 main.cpp
        RedBlack/Node.h
        RedBlack/Node.cpp)
target_link_libraries(LabWork_8
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

add_executable(Heap heap.cpp
        Heap/Heap.h
        Heap/Heap.cpp)

target_link_libraries(Heap
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

