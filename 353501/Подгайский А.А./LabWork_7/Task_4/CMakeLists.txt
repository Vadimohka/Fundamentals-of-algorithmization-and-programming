cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O0")

find_package(Qt6 REQUIRED COMPONENTS Widgets Charts)

include_directories(HashTable)

qt_standard_project_setup()

add_executable(helloapp
  main-window/main.cpp main-window/mainwindow.cpp main-window/mainwindow.h main-window/mainwindow.ui main-window/PlotBuilder.cpp HashTable/CommonHash.cpp 
)

add_executable(hashtest test/hash_test.cpp HashTable/CommonHash.cpp)

target_link_libraries(helloapp PRIVATE Qt6::Widgets Qt::Charts)

target_link_libraries(hashtest gtest)

add_test(test hash_test)

# set_target_properties(helloapp PROPERTIES
#     WIN32_EXECUTABLE ON
#     MACOSX_BUNDLE ON
# )