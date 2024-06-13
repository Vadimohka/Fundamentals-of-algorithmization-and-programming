cmake_minimum_required(VERSION 3.5)

project(RedBlackTreeVisualizer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)

add_executable(RedBlackTreeVisualizer
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    redblacktree.cpp
    redblacktree.h
    treeviewwidget.cpp
    treeviewwidget.h
)

target_link_libraries(RedBlackTreeVisualizer Qt5::Widgets)
