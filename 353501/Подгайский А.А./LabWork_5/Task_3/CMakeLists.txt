cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()
enable_testing()

include_directories(tests)
include_directories(bitset)




add_executable(bset_test tests/bitset_tests.cpp bitset/bitset.h)
target_link_libraries(bset_test PRIVATE gtest)
add_test(bitset_test bset_test)

qt_add_executable(helloapp
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
)
target_link_libraries(helloapp PRIVATE Qt6::Widgets)




