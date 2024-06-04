cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "-O2")


find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

enable_testing()


add_executable(helloapp
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui Map.h
)
target_link_libraries(helloapp PRIVATE Qt6::Widgets Qt6::Core)

add_executable(bst_test bst_test.cpp)
target_link_libraries(bst_test PRIVATE gtest)
add_test(test bst_test)