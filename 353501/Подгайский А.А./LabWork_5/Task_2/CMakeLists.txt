cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GoogleTest)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(GTest REQUIRED)
enable_testing()
qt_standard_project_setup()

include_directories(mystring)


add_library(mycstring SHARED mystring/mycstring.c)

add_library(String SHARED mystring/String.cpp)


qt_add_executable(helloapp
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
)

target_link_libraries(helloapp PRIVATE Qt6::Widgets mycstring)


add_executable(cstring_test tests/cstring_test.cpp )
target_link_libraries(cstring_test PRIVATE gtest mycstring)

add_executable(string_test tests/string_test.cpp)
target_link_libraries(string_test PRIVATE gtest String)


gtest_discover_tests(string_test)
gtest_discover_tests(cstring_test)


