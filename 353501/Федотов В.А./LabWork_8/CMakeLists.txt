cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(Task_1
    Task_1/main.cpp Task_1/mainwindow.cpp Task_1/mainwindow.h Task_1/mainwindow.ui
    Task_1/AvlTree.h
    Task_1/solver.h
)

target_link_libraries(Task_1 PRIVATE Qt6::Widgets)

set_target_properties(Task_1 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

add_library(Task_2_ArrayMaxHeap STATIC Task_2/Array/ArrayMaxHeap.h)

qt_add_executable(Task_2_Array
    Task_2/Array/main.cpp Task_2/Array/mainwindow.cpp Task_2/Array/mainwindow.h Task_2/Array/mainwindow.ui
)

target_link_libraries(Task_2_Array PRIVATE Qt6::Widgets Task_2_ArrayMaxHeap)

set_target_properties(Task_2_Array PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

add_library(Task_2_TreeMaxHeap SHARED Task_2/Tree/TreeMaxHeap.h)
# add_library(Task_2_TreeMaxHeap SHARED bebra2.h)

qt_add_executable(Task_2_Tree
    Task_2/Tree/main.cpp Task_2/Tree/mainwindow.cpp Task_2/Tree/mainwindow.h Task_2/Tree/mainwindow.ui
)

target_link_libraries(Task_2_Tree PRIVATE Qt6::Widgets Task_2_TreeMaxHeap)

set_target_properties(Task_2_Tree PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
