#ifndef DB7C6F59_C2CB_4E81_AFBC_DCC2C5F8D54A
#define DB7C6F59_C2CB_4E81_AFBC_DCC2C5F8D54A

#include "FFTProcessor.h"
#include "Utils.h"
#include <qcheckbox.h>
#include <qspinbox.h>
#include <qwidget.h>
#include <QCheckBox>
#include <QSpinBox>

struct ae_signal {
  double magn;
  double bin_freq;
};

class Pitch : public FFTProcessor{

    double koef = 1.4;
    int cnt = 0;
    std::vector<double> lastPhases;
    std::vector<double> lastSynthPhases;
    std::vector<ae_signal> analysis;
    std::vector<ae_signal> synthesis;
    bool first_time = true;

    QSpinBox* pitchShiftBox;
    QLabel* ratioLbl;
    void processFftChunk(Utils::Frequencies& freqs) override;
    void updateProperties() override;
    //void _process(Sample*, int, int) override;

public:
    void setUpUi(QWidget*) override;
    Pitch();
    virtual void reset() override;

};


#endif /* DB7C6F59_C2CB_4E81_AFBC_DCC2C5F8D54A */
