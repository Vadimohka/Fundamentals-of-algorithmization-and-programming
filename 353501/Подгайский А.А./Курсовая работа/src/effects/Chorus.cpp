#include "Chorus.h"
#include "BaseEffect.h"
#include "FFTProcessor.h"
#include "Utils.h"
#include <cmath>
#include <complex>
#include <random>


Chorus::Chorus() : FFTProcessor(){
    //CHUNK_SIZE = 256;    
}

void Chorus::processFftChunk(Utils::Frequencies& freqs) {
    static float arg = 0.0f;
    std::random_device dev;
    std::mt19937 gen(dev());
    std::uniform_real_distribution<> rnd(0.7,  1.0);

    for(int i = 0; i < freqs.size(); ++i){
        auto ph =  std::atan2(freqs[i].imag(), freqs[i].real());
        auto ampl =  (float)std::abs(freqs[i]);
        auto c = std::polar(ampl, ph);
        freqs[i] = c;
    }
    arg += 0.4;

    // for(int i = 0; i < freqs.size(); ++i){
    //     auto phi = std::atan2(freqs[i].imag(), freqs[i].real());
    //     auto ampl = std::abs(freqs[i]);
    //     freqs[i] = std::polar(ampl, phi * 1.2f);
    // }

}
void Chorus::updateProperties(){
}

void Chorus::setUpUi(QWidget* w) {
    BaseEffect::setUpUi(w);    
}