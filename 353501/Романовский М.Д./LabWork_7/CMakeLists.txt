cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Charts)
qt_standard_project_setup()


qt_add_executable(Task_1
    Task_1/main.cpp Task_1/mainwindow.cpp Task_1/mainwindow.h Task_1/mainwindow.ui
)

target_link_libraries(Task_1 PRIVATE Qt6::Widgets)

set_target_properties(Task_1 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

qt_add_executable(Task_2
Task_2/main.cpp Task_2/mainwindow.cpp Task_2/mainwindow.h Task_2/mainwindow.ui
Task_2/Solver.cpp
)


target_link_libraries(Task_2 PRIVATE Qt6::Widgets)

set_target_properties(Task_2 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

add_executable( Task_2_SearchTree Task_2/SearchTree_test.cpp )
target_link_libraries(Task_2_SearchTree gtest gtest_main)
add_test( Task_2_SearchTree Task_2_SearchTree )

qt_add_executable(Task_3
Task_3/main.cpp Task_3/mainwindow.cpp Task_3/mainwindow.h Task_3/mainwindow.ui
Task_3/Solver.cpp
)

target_link_libraries(Task_3 PRIVATE Qt6::Widgets Qt6::Charts)

set_target_properties(Task_3 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

add_executable( Task_3_HashMap Task_3/HashMap_test.cpp )
target_link_libraries(Task_3_HashMap gtest gtest_main)
add_test( Task_3_HashMap Task_3_HashMap )


qt_add_executable(Task_4
Task_4/main.cpp Task_4/mainwindow.cpp Task_4/mainwindow.h Task_4/mainwindow.ui
)

target_link_libraries(Task_4 PRIVATE Qt6::Widgets Qt6::Charts)

set_target_properties(Task_4 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

add_executable( Task_4_HashMap Task_4/HashMap_test.cpp )
target_link_libraries(Task_4_HashMap gtest gtest_main)
add_test( Task_4_HashMap Task_4_HashMap )

qt_add_executable(Task_5
  Task_5/main.cpp Task_5/mainwindow.cpp Task_5/mainwindow.h Task_5/mainwindow.ui
)

target_link_libraries(Task_5 PRIVATE Qt6::Widgets)

set_target_properties(Task_5 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

add_executable( Task_5_Deque Task_5/Deque_test.cpp )
target_link_libraries(Task_5_Deque gtest gtest_main)
add_test( Task_5_Deque Task_5_Deque )