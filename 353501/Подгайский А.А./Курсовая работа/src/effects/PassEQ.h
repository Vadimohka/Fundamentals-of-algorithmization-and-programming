#ifndef A0510986_E29A_4435_9AF5_B170EB7D014D
#define A0510986_E29A_4435_9AF5_B170EB7D014D

#include "BaseEffect.h"
#include "FFTProcessor.h"
#include "Utils.h"
#include <qwidget.h>
#include <QCheckBox>
#include <QSpinBox>

class PassEQ : public FFTProcessor {

    bool isHighPass = false;
    int passFreq = 96;
    int lastFreq = 100;

    double koef = 0.8;

    QSpinBox* passSBox;
    QSpinBox* lastSBox;
    QCheckBox* chkBox;

    void processFftChunk(Utils::Frequencies& freqs) override;
    void updateProperties() override;
    //void _process(Sample*, int, int) override;

public:
    void setUpUi(QWidget*) override;
    PassEQ();

};

#endif /* A0510986_E29A_4435_9AF5_B170EB7D014D */
