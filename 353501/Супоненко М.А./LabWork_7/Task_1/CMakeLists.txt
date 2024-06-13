cmake_minimum_required(VERSION 3.5)

project(QueueExample VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    queue.cpp
    queue.h
)

qt5_wrap_ui(UI_HEADERS mainwindow.ui)
qt5_wrap_cpp(MOC_SOURCES mainwindow.h)

add_executable(QueueExample
    ${PROJECT_SOURCES}
    ${UI_HEADERS}
    ${MOC_SOURCES}
)

target_link_libraries(QueueExample PRIVATE Qt5::Widgets)

set_target_properties(QueueExample PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS QueueExample
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
