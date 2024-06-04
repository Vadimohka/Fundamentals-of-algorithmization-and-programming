cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(Task_1
  Task_1/main.cpp Task_1/mainwindow.cpp  Task_1/mainwindow.ui
  Task_1/VisVector.cpp Task_1/Sorter.cpp Task_1/Search.cpp
)

target_link_libraries(Task_1 PRIVATE Qt6::Widgets)


qt_add_executable(Task_2
  Task_2/main.cpp Task_2/mainwindow.cpp  Task_2/mainwindow.ui
  Task_2/VisVector.cpp Task_2/Sorter.cpp Task_2/Search.cpp
)

target_link_libraries(Task_2 PRIVATE Qt6::Widgets)


qt_add_executable(Task_3
  Task_3/main.cpp Task_3/mainwindow.cpp Task_3/mainwindow.ui
)

target_link_libraries(Task_3 PRIVATE Qt6::Widgets)


add_executable( Task_4 Task_4/test_Vector.cpp )
target_link_libraries(Task_4 gtest gtest_main)
add_test( Task_4 Task_4 )

qt_add_executable(Task_5 
  Task_5/main.cpp Task_5/mainwindow.cpp Task_5/mainwindow.ui
)

target_link_libraries(Task_5 PRIVATE Qt6::Widgets)
