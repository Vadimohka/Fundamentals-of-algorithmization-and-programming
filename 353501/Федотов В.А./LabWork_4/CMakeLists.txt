cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

# Task1
qt_add_executable(Task_1
    Task_1/main.cpp Task_1/mainwindow.cpp  Task_1/mainwindow.ui
    Task_1/sorter.cpp
)

target_link_libraries(Task_1 PRIVATE Qt6::Widgets)

# Task2
qt_add_executable(Task_2
    Task_2/main.cpp Task_2/mainwindow.cpp  Task_2/mainwindow.ui
    Task_2/sorter.cpp
)

target_link_libraries(Task_2 PRIVATE Qt6::Widgets)

# Task3
qt_add_executable(Task_3
    Task_3/main.cpp Task_3/mainwindow.cpp  Task_3/mainwindow.ui

)

target_link_libraries(Task_3 PRIVATE Qt6::Widgets)

# Task4
qt_add_executable(Task_4
    Task_4/main.cpp 
    Task_4/vector.h
    Task_4/pair.h
)

# Task5
qt_add_executable(Task_5
    Task_5/main.cpp Task_5/mainwindow.cpp  Task_5/mainwindow.ui
    Task_5/pair.h
    Task_4/vector.h

)

target_link_libraries(Task_5 PRIVATE Qt6::Widgets)
