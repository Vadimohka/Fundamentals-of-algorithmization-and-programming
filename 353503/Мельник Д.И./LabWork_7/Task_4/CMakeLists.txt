cmake_minimum_required(VERSION 3.16)

project(Lab_7_4 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "/home/dmitry/Qt/6.6.1/gcc_64/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(HashTable)

qt_standard_project_setup()

add_executable(Lab_7_4
  main-window/main.cpp main-window/mainwindow.cpp main-window/mainwindow.h main-window/mainwindow.ui main-window/PlotBuilder.cpp HashTable/CommonHash.cpp 
)

target_link_libraries(Lab_7_4 PUBLIC Qt6::Widgets PUBLIC Qt6::Core)
