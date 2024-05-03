cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(helloapp
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
  shape.h shape.cpp
  circle.cpp circle.h 
  triangle.cpp triangle.h
  rectangle.cpp rectangle.h 
  square.cpp square.h 
  star.cpp star.h 
  rhombus.cpp rhombus.h 
  hexagon.cpp hexagon.h 
  customShape.cpp customShape.h 
  customScene.cpp customScene.h  

)

target_link_libraries(helloapp PRIVATE Qt6::Widgets)

set_target_properties(helloapp PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)