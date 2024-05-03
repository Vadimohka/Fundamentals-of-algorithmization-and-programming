cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "-O2")

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

include_directories(visual)
include_directories(core)

qt_add_executable(helloapp
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
   visual/SortVisualiser.cpp visual/SVector.cpp core/Binpow.cpp

   core/Sorter.cpp core/Search.cpp
   
)

target_link_libraries(helloapp PRIVATE Qt6::Widgets)