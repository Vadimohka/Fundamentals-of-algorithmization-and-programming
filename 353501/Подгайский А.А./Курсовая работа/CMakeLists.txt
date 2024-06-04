cmake_minimum_required(VERSION 3.26.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#************************************

project(aedit)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        Concurrent
        REQUIRED)

add_subdirectory(lib/portaudio bin EXCLUDE_FROM_ALL)

include_directories(src/core/core-audio)
include_directories(src/app)
include_directories(src/app/timeline)
include_directories(src/effects)


add_executable(aedit src/main.cpp
        src/app/mainwindow.cpp
        src/app/mainwindow.h
        src/app/MainWindow.ui
        src/app/timeline/TimelineScene.cpp
        src/app/timeline/AudioPixmap.cpp
        src/app/timeline/EffectSelection.cpp
        src/app/exporter.cpp

        src/core/core-audio/CoreInfo.cpp
        src/core/core-audio/CoreAudio.cpp
        src/core/core-audio/CoreAudio.h
        src/core/core-audio/pa_callback.c

        src/effects/Gain.cpp
        src/effects/Constructor.cpp
        src/effects/BaseEffect.cpp
        src/effects/FFTProcessor.cpp
        src/effects/Robotiser.cpp
        src/effects/PassEQ.cpp
        src/effects/Pitch.cpp
        src/effects/Chorus.cpp
        src/effects/TimePitch.cpp
        src/effects/Reverb.cpp

        src/app/loader.cpp

        src/resources.qrc
        # portaudio_static
)


target_link_libraries(aedit
        portaudio_static
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
        Qt::Concurrent
)


