cmake_minimum_required(VERSION 3.16)

project(Lab_8_1 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)


set(CMAKE_PREFIX_PATH "/home/dmitry/Qt/6.6.1/gcc_64/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

qt_standard_project_setup()

add_executable(Lab_8_1
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui BSTWithDepth.h BSTGui.h
)
target_link_libraries(Lab_8_1 PRIVATE Qt6::Widgets Qt6::Core)
