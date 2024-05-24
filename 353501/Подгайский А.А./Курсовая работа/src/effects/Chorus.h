#ifndef D4A4D7FC_E348_4D64_AE6D_411E41E95A9A
#define D4A4D7FC_E348_4D64_AE6D_411E41E95A9A

#include "FFTProcessor.h"

class Chorus : public FFTProcessor{

    int units =  130;

    public:
        Chorus();

protected:
    void processFftChunk(Utils::Frequencies& freqs) override;
    void updateProperties() override;

public:
    void setUpUi(QWidget*) override;

};

#endif /* D4A4D7FC_E348_4D64_AE6D_411E41E95A9A */
