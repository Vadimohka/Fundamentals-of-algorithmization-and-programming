cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport)
qt_standard_project_setup()

# Task1
qt_add_executable(Task_1
    Task_1/main.cpp 
    Task_1/mainwindow.cpp  
    Task_1/mainwindow.ui
    Task_1/Dqueue.h
    
)


target_link_libraries(Task_1 PRIVATE Qt6::Widgets Qt6::PrintSupport)
set_target_properties(Task_1 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

#task_2
qt_add_executable(Task_2
    Task_2/main.cpp 
    Task_2/mainwindow.cpp  
    Task_2/mainwindow.ui
    Task_2/Searchtree.h 
    Task_2/VisualBST.cpp 
    
)


target_link_libraries(Task_2 PRIVATE Qt6::Widgets Qt6::PrintSupport)
set_target_properties(Task_2 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

#task 3 

qt_add_executable(Task_3
    Task_3/main.cpp 
    Task_3/mainwindow.cpp  
    Task_3/mainwindow.ui
    Task_3/HashTable.h
    Task_3/VisualHashMap.cpp
    
    
)


target_link_libraries(Task_3 PRIVATE Qt6::Widgets Qt6::PrintSupport)
set_target_properties(Task_3 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)






