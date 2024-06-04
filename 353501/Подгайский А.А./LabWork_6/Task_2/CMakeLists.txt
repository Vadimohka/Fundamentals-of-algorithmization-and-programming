cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(helloapp
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
  CDM/IOService.cpp
  CDM/IOParagraph.cpp
  CDM/IOArray.cpp
  CDM/IOStruct.cpp
  CDM/IOParagraphAppend.cpp
  CDM/IOStructBin.cpp
  Footwear.cpp
)


include_directories(CDM)
include_directories(.)

target_link_libraries(helloapp PRIVATE Qt6::Widgets)
