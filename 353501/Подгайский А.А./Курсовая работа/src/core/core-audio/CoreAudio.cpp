//
// Created by artemious on 25.02.24.
//

#include "CoreAudio.h"
#include "Utils.h"
#include "coretypes.h"
#include "portaudio.h"
#include <cmath>
#include <cstdint>
#include <iostream>
#include <qnamespace.h>

namespace ae {

int32_t CoreAudio::SamplingFrequency = 48000;
int32_t CoreAudio::FramesPerCallback = 128;
bool CoreAudio::_isPlaying = false;

PaStream *CoreAudio::stream = nullptr;
StereoAudioBuffer CoreAudio::buffer = {nullptr, nullptr, 0, 0};

PaError CoreAudio::init() {
  auto err = Pa_Initialize();
  if (err != paNoError) {
    return err;
  }

  err = Pa_OpenDefaultStream(&stream, 0, 2, paFloat32, SamplingFrequency,
                             FramesPerCallback, &paUsualCallback, &buffer);

  if (err != paNoError) {
    std::cerr << Pa_GetErrorText(err);
  }
  return err;
}

PaError CoreAudio::terminate() {
  if (stream) {
    Pa_CloseStream(stream);
  }

  auto err = Pa_Terminate();
  if (buffer.left)
    delete[] buffer.left;
  if (buffer.right)
    delete[] buffer.right;
  return err;
}

PaError CoreAudio::play() {

  auto err = Pa_StartStream(stream);
  if (err == paStreamIsNotStopped) {
    err = Pa_StopStream(stream);
    err = Pa_StartStream(stream);
  }
  return err;
  
}

PaError CoreAudio::stop() {
  buffer.current = 0;
  //_isPlaying = false;
  return Pa_StopStream(stream);
}

PaError CoreAudio::pause() {
  //_isPlaying = false;
  return Pa_StopStream(stream);
}

void CoreAudio::initializeTestStream() {
  CoreAudio::buffer.left = new Sample[TEST_BUF_SZ];
  CoreAudio::buffer.right = new Sample[TEST_BUF_SZ];
  double arg = 0.0;
  double step = 1.0 / SamplingFrequency;
  double angFreq = 2 * M_PI * 700;
  double ampl = 1.0f;

  for (int i = 0; i < TEST_BUF_SZ; ++i) {
    buffer.left[i] = ampl * sin(angFreq * arg);
    buffer.right[i] = ampl * sin(angFreq * arg);
    // std::cerr << stereoStream.buffer[i] << '\n';
    arg += step;
  }
  CoreAudio::buffer.size = TEST_BUF_SZ;
  CoreAudio::buffer.current = 0;
}

} // namespace ae
void ae::CoreAudio::setBuffer(StereoAudioBuffer buffer_) {
  stop();
  if (buffer.left && buffer_.left != buffer.left)
    delete[] buffer.left;
  if (buffer.right && buffer_.right != buffer.right)
    delete[] buffer.right;
  buffer = buffer_;
  buffer.current = 0;
}

StereoAudioBuffer ae::CoreAudio::getBuffer() { return buffer; }

void ae::CoreAudio::setCurrentIndex(long ind) {
  buffer.current = std::max(0L, std::min((long)buffer.size, ind) );
}

bool ae::CoreAudio::isPlaying() {
  // std::cerr << "isplaying? : " << _isPlaying << '\n';
  // std::cerr << "is active: " << Pa_IsStreamActive(stream) << '\n';
  return Pa_IsStreamActive(stream);
}

void ae::CoreAudio::resizeStream(size_t new_sz) {
    if(new_sz == buffer.size){
        return;
    }

    StereoAudioBuffer new_buf;
    new_buf.left = new Sample[new_sz];
    new_buf.right = new Sample[new_sz];
    new_buf.size = new_sz;
    new_buf.isStereo = buffer.isStereo;
    new_buf.current = std::min ( std::max(buffer.current, 0LL) , (long long)new_sz );

    for(int i = 0; i < std::min((long long)new_sz, buffer.size); ++i ){
        new_buf.left[i] = buffer.left[i];
        new_buf.right[i] = buffer.right[i];
    }
    for(int i = buffer.size; i < new_sz; ++i){
        new_buf.left[i] = 0;
        new_buf.right[i] = 0;
    }

    setBuffer(new_buf);
}
