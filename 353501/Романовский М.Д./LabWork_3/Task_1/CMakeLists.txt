cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Concurrent)
qt_standard_project_setup()


qt_add_executable(task1
  task1/main.cpp task1/mainwindow.cpp task1/mainwindow.h task1/mainwindow.ui task1/ToBin.cpp
)

target_link_libraries(task1 PRIVATE Qt6::Widgets)

set_target_properties(task1 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


qt_add_executable(task2
  task2/main.cpp task2/mainwindow.cpp task2/mainwindow.ui task2/Ackermann.cpp
)

target_link_libraries(task2 PRIVATE Qt6::Widgets)

set_target_properties(task2 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


qt_add_executable(task3
  task3/main.cpp task3/mainwindow.cpp task3/mainwindow.ui task3/Reverse.cpp
)

target_link_libraries(task3 PRIVATE Qt6::Widgets)

set_target_properties(task3 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)



qt_add_executable(task4
  task4/main.cpp task4/mainwindow.cpp task4/mainwindow.ui task4/Hanoi.cpp task4/Vis.cpp
)

target_link_libraries(task4 PRIVATE Qt6::Widgets)

set_target_properties(task4 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


qt_add_executable(task5
  task5/main.cpp task5/mainwindow.cpp task5/mainwindow.ui task5/FolderCounter.cpp
)

target_link_libraries(task5 PRIVATE Qt6::Widgets Qt6::Concurrent)

set_target_properties(task5 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)