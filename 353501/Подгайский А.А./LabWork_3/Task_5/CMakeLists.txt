cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Concurrent)
qt_standard_project_setup()

qt_add_executable(t5
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui DirCounter.cpp FileSystemModel.cpp
)

target_link_libraries(t5 PRIVATE Qt6::Widgets Qt6::Concurrent)  

set_target_properties(t5 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)