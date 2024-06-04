#ifndef C2E5DC61_C560_47C2_9A32_A44B599C5C0D
#define C2E5DC61_C560_47C2_9A32_A44B599C5C0D
#include "FFTProcessor.h"
#include "Utils.h"

class Robotiser : public FFTProcessor{

    int units =  130;

    public:
    Robotiser();

protected:
    void processFftChunk(Utils::Frequencies& freqs) override;
    void updateProperties() override;

public:
    void setUpUi(QWidget*) override;

};

#endif /* C2E5DC61_C560_47C2_9A32_A44B599C5C0D */
    