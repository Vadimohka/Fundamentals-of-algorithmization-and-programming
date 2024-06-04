//
// Created by artemious on 25.02.24.
//

#ifndef AEDIT_COREAUDIO_H
#define AEDIT_COREAUDIO_H

#include <cstdint>
#include <cstdlib>
#include "coretypes.h"
#include <portaudio.h>

// extern "C" int paCycleCallback( const void *inputBuffer, void *outputBuffer,
//                             unsigned long framesPerBuffer,
//                             const PaStreamCallbackTimeInfo* timeInfo,
//                             PaStreamCallbackFlags statusFlags,
//                             void *userData);

extern "C" int paUsualCallback( const void *inputBuffer, void *outputBuffer,
                                unsigned long framesPerBuffer,
                                const PaStreamCallbackTimeInfo* timeInfo,
                                PaStreamCallbackFlags statusFlags,
                                void *userData);

namespace ae {

class CoreAudio {
  static const int32_t TEST_BUF_SZ = 32000;
      

        static StereoAudioBuffer buffer;
        static PaStream * stream;
        static bool _isPlaying;

    public:
      static int32_t SamplingFrequency;
      static int32_t FramesPerCallback;
        
        static PaError init();
        static PaError terminate();

        static PaError play();
        static PaError stop();
        static PaError pause();

        static void setCurrentIndex(long ind);
        static void setBuffer(StereoAudioBuffer buffer);
        static StereoAudioBuffer getBuffer();
        static bool isPlaying();

        static void initializeTestStream();

        static void resizeStream(size_t new_sz);


    };

} // ae

#endif //AEDIT_COREAUDIO_H
