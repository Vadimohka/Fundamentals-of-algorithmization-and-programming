cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport)
qt_standard_project_setup()

qt_add_executable(Task_1
Task_1/main.cpp Task_1/mainwindow.cpp  Task_1/mainwindow.ui Task_1/Buisenessman.cpp
)

target_link_libraries(Task_1 PRIVATE Qt6::Widgets Qt6::PrintSupport)

set_target_properties(Task_1 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


qt_add_executable(Task_2
Task_2/main.cpp Task_2/mainwindow.cpp  Task_2/mainwindow.ui
Task_2/sub1/SubFirst.cpp Task_2/sub1/SubFirst.ui
Task_2/sub2/SubSecond.cpp Task_2/sub2/SubSecond.ui
Task_2/sub3/SubThird.cpp Task_2/sub3/SubThird.ui Task_2/sub3/Buisenessman.cpp
Task_2/sub4/SubFour.cpp
Task_2/sub5/SubFive.cpp Task_2/sub5/SubFive.ui
)

target_link_libraries(Task_2 PRIVATE Qt6::Widgets)

set_target_properties(Task_2 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)