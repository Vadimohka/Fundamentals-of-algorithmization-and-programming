cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Charts)
qt_standard_project_setup()




qt_add_executable(Task_1
Task_1/main.cpp 
Task_1/mainwindow.cpp 
Task_1/mainwindow.h 
Task_1/mainwindow.ui
Task_1/VisualBST.cpp
)

target_link_libraries(Task_1 PRIVATE Qt6::Widgets)

set_target_properties(Task_1 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)



add_library(Task_2_ArrayHeap STATIC Task_2/ArrayHeap.cpp)
add_library(Task_2_TreeHeap SHARED Task_2/TreeHeap.cpp)

qt_add_executable(Task_2
Task_2/main.cpp Task_2/mainwindow.cpp Task_2/mainwindow.h Task_2/mainwindow.ui
)

target_link_libraries(Task_2 PRIVATE Qt6::Widgets Task_2_ArrayHeap)

set_target_properties(Task_2 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)



