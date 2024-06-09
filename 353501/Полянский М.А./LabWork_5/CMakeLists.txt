cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

# Task1
qt_add_executable(Task_1
    Task_1/main.cpp 
    Task_1/mainwindow.cpp  
    Task_1/mainwindow.ui
    Task_1/InputLineEdit.cpp
    Task_1/OutputTextEdit.cpp
    Task_1/KeyObject.cpp
    Task_1/Keyboard.cpp
    Task_1/Underline.cpp
)

target_include_directories(Task_1 PRIVATE Task_1/)
target_link_libraries(Task_1 PRIVATE Qt6::Widgets)


add_library(cstring SHARED Task_2/customString.cpp Task_2/stringFun.cpp)

qt_add_executable(Task_2
    Task_2/main.cpp Task_2/mainwindow.cpp Task_2/mainwindow.ui
)

target_link_libraries(Task_2 PRIVATE Qt6::Widgets cstring)

qt_add_executable(Task_3
    Task_3/main.cpp Task_3/mainwindow.cpp Task_3/mainwindow.ui
    Task_3/Bitset.h 
)

target_link_libraries(Task_3 PRIVATE Qt6::Widgets)