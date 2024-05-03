cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(Task_1
  Task_1/main.cpp Task_1/mainwindow.cpp Task_1/mainwindow.ui
  Task_1/CatchyLineEdit.cpp Task_1/PixArt.cpp
  Task_1/LetterBox.cpp Task_1/Keyboard.cpp
)
target_include_directories(Task_1 PRIVATE Task_1/)
target_link_libraries(Task_1 PRIVATE Qt6::Widgets)

add_library(string SHARED Task_2/String.cpp Task_2/String_errnos.cpp)

add_executable( Task_2_strtest Task_2/String_test.cpp )
target_link_libraries(Task_2_strtest gtest gtest_main string)
add_test( Task_2_strtest Task_2_strtest )


qt_add_executable(Task_2
  Task_2/main.cpp Task_2/mainwindow.cpp Task_2/mainwindow.ui
)
target_link_libraries(Task_2 PRIVATE Qt6::Widgets string)


add_executable( Task_3_bittest Task_3/Bitset_test.cpp )
target_link_libraries(Task_3_bittest gtest gtest_main)
add_test( Task_3_bittest Task_3_bittest )

qt_add_executable(Task_3
  Task_3/main.cpp Task_3/mainwindow.cpp Task_3/mainwindow.ui
)
target_link_libraries(Task_3 PRIVATE Qt6::Widgets)

