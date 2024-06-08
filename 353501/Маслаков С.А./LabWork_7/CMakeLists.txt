cmake_minimum_required(VERSION 3.26)

project(lab7 VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_PREFIX_PATH "/Users/sagot/Qt/6.6.1/macos")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(Task1
  Task1/main.cpp Task1/mainwindow.cpp Task1/mainwindow.h Task1/mainwindow.ui
        Task1/Queue.h
)
qt_add_executable(Task2
        Task2/main.cpp Task2/mainwindow.cpp Task2/mainwindow.h Task2/mainwindow.ui
        Task2/BST.h
        Task2/BSTui.h)
qt_add_executable(Task3
        Task3/main.cpp Task3/mainwindow.cpp Task3/mainwindow.h Task3/mainwindow.ui
        Task3/HashMap.h
        Task3/HashMapUi.h)
qt_add_executable(Task4
        Task4/main.cpp Task4/mainwindow.cpp Task4/mainwindow.h Task4/mainwindow.ui
        Task4/HashMap.h
        Task4/HashMapUi.h
        Task4/HashMap.h
        Task4/HashMapUi.h)
qt_add_executable(Task5
        Task5/main.cpp Task5/mainwindow.cpp Task5/mainwindow.h Task5/mainwindow.ui
        Task5/deque.h
)
target_link_libraries(Task5 PRIVATE Qt6::Widgets)

set_target_properties(Task5 PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)
target_link_libraries(Task4 PRIVATE Qt6::Widgets)

set_target_properties(Task4 PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)
target_link_libraries(Task1 PRIVATE Qt6::Widgets)

set_target_properties(Task1 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
target_link_libraries(Task2 PRIVATE Qt6::Widgets)

set_target_properties(Task2 PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)
target_link_libraries(Task3 PRIVATE Qt6::Widgets)

set_target_properties(Task3 PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)