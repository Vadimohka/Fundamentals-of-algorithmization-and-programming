#include "Pitch.h"
#include "BaseEffect.h"
#include "FFTProcessor.h"
#include "Utils.h"
#include <complex>
#include <qcheckbox.h>
#include <qspinbox.h>

Pitch::Pitch()
: FFTProcessor(1024, 128), lastSynthPhases(CHUNK_SIZE+1, 0.0), lastPhases(CHUNK_SIZE+1, 0.0),
     synthesis(CHUNK_SIZE/2 + 1, {0, 0}), analysis(CHUNK_SIZE/2 + 1, {0, 0}) {
      }


void Pitch::processFftChunk(Utils::Frequencies &freqs) {
  
  auto n = CHUNK_SIZE;
  auto n_h = CHUNK_SIZE / 2;
  auto hop = HOP_SIZE;

  Utils::Frequencies new_freqs(CHUNK_SIZE);

  // for(int i= 0; i < n_h; ++i){
  //   analysis[i] = {0.0, 0.0};
  // }

  double bin_freq_step = 2 * M_PI / (float)CHUNK_SIZE;
  double bin_freq = 0;

  // 1. ANALYSIS
  for (int i = 0; i <= n_h; ++i) {
    std::complex<double> cur = freqs[i];
    double magn = std::abs(cur);
    double phase = std::atan2(cur.imag(), cur.real());

    // actual change in phase since last chunk
    double act_dphase = phase - lastPhases[i];
    // expected change, as if it was a constant sinusoid
    double exp_dphase = bin_freq * hop;

    double freq_diverg = Utils::normalise(act_dphase - exp_dphase);
    // smth from calculus`
    double bin_diverg =
        freq_diverg * (double)CHUNK_SIZE / (2.0 * M_PI * hop);

    analysis[i].bin_freq = (double)i + bin_diverg;
    analysis[i].magn = magn;
    lastPhases[i] = phase;
    bin_freq += bin_freq_step;
  }
  CHECK_STOP

  // 2. MODIFYING

  for(int i = 0; i <= n_h; ++i){
    synthesis[i] = {0.0, (float)i};
  }

  float frac_bin = 0;
  for (int i = 0; i <= n_h; ++i) {
    int new_i = std::round((float)i * koef);

    if (new_i > n_h) {
      continue;; // we can break, further values only get greater
    }

    synthesis[new_i].magn += analysis[i].magn;
    synthesis[new_i].bin_freq = analysis[i].bin_freq * koef;
    frac_bin += koef;
  }

  CHECK_STOP

  // 3. SYNTHESYS`

  bin_freq = 0;
  for (int i = 0; i <= n_h; ++i) {
  
    auto bin_diverg = synthesis[i].bin_freq - (float)i;
    double dphase = bin_diverg * 2.0 * M_PI * (float)hop  / (float)CHUNK_SIZE;
    dphase += bin_freq * hop;

    double act_phase = Utils::normalise(lastSynthPhases[i] + dphase);

    new_freqs[i] = std::polar(synthesis[i].magn, act_phase);
    new_freqs[n - i] = std::conj(new_freqs[i]);  

    lastSynthPhases[i] = act_phase;
    // lastSynthPhases[n-i] = act_phase;
    bin_freq += bin_freq_step;
  }

  freqs = std::move(new_freqs);
}

void Pitch::updateProperties() { 
  koef = std::pow(2.0, (double)pitchShiftBox->value() / 1200); 
  ratioLbl->setText(QString::number(koef));
  // if(qualityBox->isChecked()){
  //   CHUNK_SIZE = 1024;
  //   HOP_SIZE = 256;
  // } else {
  //   CHUNK_SIZE = 4096;
  //   HOP_SIZE = 256;
  // }
}

void Pitch::setUpUi(QWidget *widget) {
  FFTProcessor::setUpUi(widget);

  pitchShiftBox = new QSpinBox();
  pitchShiftBox->setMinimum(-2400); 
  pitchShiftBox->setMaximum(2400);
  pitchShiftBox->setValue(400);
  layout->addRow("Pitch shift (cents)", pitchShiftBox);

  ratioLbl = new QLabel();
  layout->addRow("Ratio for time stretch:", ratioLbl);

  // qualityBox = new QCheckBox();
  // qualityBox->setChecked(false);
  // layout->addRow("Worse quality: ", qualityBox);
}


void Pitch::reset() {
  qDebug() << "reset";
  cnt = 0;
  for (int i = 0; i < CHUNK_SIZE / 2; ++i) {
    lastPhases[i] = 0;
    lastSynthPhases[i] = 0;
    synthesis[i] = {0.0, (float)i};
  }
}
