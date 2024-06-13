cmake_minimum_required(VERSION 3.28)
project(lab8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/acryoz/Qt/5.15.17/gcc_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab8 rbt/main.cpp
        rbt/rbtree.h
        rbt/graphview.cpp
        rbt/graphview.h
        rbt/mainwindow.ui
        rbt/mainwindow.h
        rbt/mainwindow.cpp)

target_link_libraries(lab8
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

add_executable(task2 binheap/main.cpp
        binheap/bin_heap_vec.h
        binheap/bin_heap_list.h)
add_executable(task1 search_tree/main.cpp
        search_tree/mainwindow.ui
        search_tree/mainwindow.h
        search_tree/mainwindow.cpp
        search_tree/graphview.h
        search_tree/graphview.cpp)
target_link_libraries(task1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)