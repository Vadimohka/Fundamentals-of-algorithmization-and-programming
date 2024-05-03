cmake_minimum_required(VERSION 3.16)

project(lab1 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(task2
  task2/main.cpp task2/mainwindow.cpp task2/mainwindow.ui 
  task2/shape/base.cpp task2/shape/circle.cpp task2/shape/polygon.cpp 
  task2/shape/rect.cpp task2/shape/triangle.cpp
  task2/shape/rhombus.cpp task2/shape/square.cpp
  task2/shape/hexagon.cpp task2/shape/star.cpp
  task2/shape/shield.cpp
  task2/animTrans.cpp task2/drawView.cpp
  task2/shape/custom.cpp
)

target_link_libraries(task2 PRIVATE Qt6::Widgets)

set_target_properties(task2 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

qt_add_executable(task1
  task1/main.cpp 
  task1/MainWindow.cpp task1/MainWindow.ui
  task1/MovingRectangle.cpp
  task1/Car.cpp
)

target_link_libraries(task1 PRIVATE Qt6::Widgets)

set_target_properties(task1 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)