cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O2")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

enable_testing()

qt_add_executable(helloapp
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
)

target_link_libraries(helloapp PRIVATE Qt6::Widgets)

add_executable(deq_test gtest.cpp)
target_link_libraries(deq_test PRIVATE gtest)
add_test(test deq_test)

# set_target_properties(helloapp PROPERTIES
#     WIN32_EXECUTABLE ON
#     MACOSX_BUNDLE ON
# )