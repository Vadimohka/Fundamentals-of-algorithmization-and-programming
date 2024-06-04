//
// Created by artemious on 25.02.24.
//
#include "portaudio.h"
#include "coretypes.h"

// int paCycleCallback(const void *inputBuffer, void *outputBuffer,
//                     unsigned long framesPerBuffer,
//                     const PaStreamCallbackTimeInfo *timeInfo,
//                     PaStreamCallbackFlags statusFlags,
//                     void *userData) {
//     (void) inputBuffer;

//     MonoAudioBuffer *data = (MonoAudioBuffer *) userData;
//     Sample *output = (Sample *) outputBuffer;

//     unsigned long remainingInBuffer = data->bufferSize - data->current;
//     unsigned long remainingToRead = framesPerBuffer;
//     unsigned long toReadNow = (remainingInBuffer > remainingToRead) ? remainingToRead : remainingInBuffer;
//     unsigned long totalRead = 0;

//     unsigned long i = 0;

//     while (totalRead < framesPerBuffer) {
//         unsigned long lastRead = data->current + toReadNow;
//         for (; data->current < lastRead; ++data->current, ++i) {
//             output[i] = data->buffer[data->current];
//         }
//         remainingInBuffer -= toReadNow;
//         remainingToRead -= toReadNow;
//         totalRead += toReadNow;

//         if (remainingInBuffer == 0) {
//             data->current = 0;
//             remainingInBuffer = data->bufferSize;
//         }

//         toReadNow = (remainingInBuffer > remainingToRead) ? remainingToRead : remainingInBuffer;
//     }

//     return paContinue;
// }


    int paUsualCallback(const void *inputBuffer, void *outputBuffer,
                        unsigned long framesPerBuffer,
                        const PaStreamCallbackTimeInfo *timeInfo,
                        PaStreamCallbackFlags statusFlags, void *userData) {
        
        StereoAudioBuffer *data = (StereoAudioBuffer *) userData;
        Sample *out = (Sample *) outputBuffer;

        long remainingToRead = data->size - data->current;
        long readNow = remainingToRead > framesPerBuffer ? framesPerBuffer : remainingToRead;

        int j = data->current;
        for(int i = 0; i < readNow; ++i){
            *out++ = data->left[j];
            *out++ = data->right[j];
            ++j;
        }

        data->current += readNow;

        if(data->current == data->size){
            return paComplete;
        }
        return paContinue;
    }
