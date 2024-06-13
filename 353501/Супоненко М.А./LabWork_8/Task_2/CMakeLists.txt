cmake_minimum_required(VERSION 3.5)

project(Task2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCES
    main.cpp
    mainwindow.cpp
    array_heap.cpp
    list_heap.cpp
)

set(HEADERS
    mainwindow.h
    array_heap.h
    list_heap.h
)

set(UIS
    mainwindow.ui
)

qt5_wrap_ui(UI_HEADERS ${UIS})
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

add_executable(Task2
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
    ${MOC_SOURCES}
)

target_link_libraries(Task2 Qt5::Widgets)
