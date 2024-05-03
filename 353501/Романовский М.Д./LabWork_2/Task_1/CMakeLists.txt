cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()


add_executable( dateTest Task_1/Date.cpp Task_1/test/DateTest.cpp )
target_link_libraries(dateTest Qt6::Core gtest gtest_main)
add_test( dateTest dateTest )


qt_add_executable(Task_1
  Task_1/main.cpp Task_1/mainwindow.cpp Task_1/mainwindow.h Task_1/mainwindow.ui
  Task_1/Date.cpp
)

target_link_libraries(Task_1 PRIVATE Qt6::Widgets)

set_target_properties(Task_1 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

qt_add_executable(Task_2
  Task_2/main.cpp Task_2/mainwindow.cpp  Task_2/mainwindow.ui
  Task_2/Car.cpp Task_2/Database.cpp Task_2/CarDialog.cpp
  Task_2/RangeFilter.cpp Task_2/SelectFilter.cpp
)

target_link_libraries(Task_2 PRIVATE Qt6::Widgets)

set_target_properties(Task_2 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


add_executable( Task_3 Task_3/test.cpp Task_3/BinaryOperation.cpp Task_3/Number.cpp Task_3/Expression.cpp)
target_link_libraries(Task_3 gtest gtest_main)
add_test( Task_3 Task_3 )
