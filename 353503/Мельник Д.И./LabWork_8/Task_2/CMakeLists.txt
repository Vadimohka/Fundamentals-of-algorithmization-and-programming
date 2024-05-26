cmake_minimum_required(VERSION 3.16)

project(Lab_8_2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/home/dmitry/Qt/6.6.1/gcc_64/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(PriorityQueue)
qt_standard_project_setup()


add_executable(Lab_8_2
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui PriorityQueue/PriorityTree.cpp
)

target_link_libraries(Lab_8_2 PRIVATE Qt6::Widgets)
