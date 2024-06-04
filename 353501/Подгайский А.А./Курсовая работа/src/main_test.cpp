//
// Created by Артем Подгайский on 23.02.24.
//

#include "AudioSynthBuffer.h"
#include <Qt>
#include <iostream>

using AudioSample = qint16;

using namespace ae;
int main(){
  ae::AudioSynthBuffer abuf{};
  abuf.open(AudioSynthBuffer::ReadOnly);
  AudioSample* samples = new AudioSample [64001];
  AudioSample* cur = samples;
  for(int i = 0; i < 16; ++i){
    cur += abuf.read(reinterpret_cast<char*>(cur), 4000) / sizeof (AudioSample );
  }

  for(int i = 0; i < 64001; ++i){
    std::cout << samples[i] << '\n';
  }
}