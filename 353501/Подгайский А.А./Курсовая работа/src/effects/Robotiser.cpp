#include "Robotiser.h"
#include "BaseEffect.h"
#include "FFTProcessor.h"
#include <cmath>


Robotiser::Robotiser() : FFTProcessor(512,  128) {
}

void Robotiser::processFftChunk(Utils::Frequencies& freqs) {
    
    for(int i = 0; i < freqs.size(); ++i){
        auto ampl = std::abs(freqs[i]);
        freqs[i] = std::polar(ampl, 0.f);
    }

}
void Robotiser::updateProperties(){
}

void Robotiser::setUpUi(QWidget* w) {
    BaseEffect::setUpUi(w);    
}
