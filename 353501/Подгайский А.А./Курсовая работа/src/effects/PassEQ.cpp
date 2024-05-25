#include "PassEQ.h"
#include "BaseEffect.h"
#include "CoreAudio.h"
#include "FFTProcessor.h"
#include "Utils.h"
#include <QSpinBox>
#include <algorithm>
#include <qcheckbox.h>
#include <qnamespace.h>
#include <qslider.h>
#include <qspinbox.h>
#include <qwidget.h>

void PassEQ::processFftChunk(Utils::Frequencies &freqs) {
  auto sf = ae::CoreAudio::SamplingFrequency;
  auto n = freqs.size();
  auto n_h = freqs.size() / 2;
  auto f_ind = passFreq * n / sf;

  auto k = 1.0;
  auto f_per_i = sf / n;

  auto decr_func = [=](double x) {
    return -(x - (passFreq - lastFreq)) * (x - (passFreq + lastFreq)) /
           (lastFreq * lastFreq);
  };

  if (isHighPass) {

    for (int i = 0; i < f_ind; ++i) {
      auto freq = f_per_i * i;
      freqs[i] *= std::max(0.0, decr_func(freq));
      freqs[n - i] = std::conj(freqs[i]);
    }
  } else {
    for (int i = f_ind; i < n_h; ++i) {
      auto freq = f_per_i * i;
      freqs[i] *= std::max(0.0, decr_func(freq));
      freqs[n - i] = std::conj(freqs[i]);
    }

  }
}

void PassEQ::setUpUi(QWidget *widget) {
  BaseEffect::setUpUi(widget);

  passSBox = new QSpinBox(widget);
  passSBox->setMinimum(20);
  passSBox->setMaximum(20'000);
  layout->addRow("Pass Frequency", passSBox);

  lastSBox = new QSpinBox(widget);
  lastSBox->setMinimum(1);
  lastSBox->setMaximum(2000);
  layout->addRow("Zeroing Frequency", lastSBox);

  chkBox = new QCheckBox(widget);
  chkBox->setCheckState(Qt::Checked);
  layout->addRow("High pass", chkBox);

  widget->show();
}

void PassEQ::updateProperties() {
  passFreq = (double)passSBox->value();
  lastFreq = passFreq + (double)lastSBox->value();
  isHighPass = chkBox->isChecked();
}
PassEQ::PassEQ() : FFTProcessor(4096, 1024) {
    
}
