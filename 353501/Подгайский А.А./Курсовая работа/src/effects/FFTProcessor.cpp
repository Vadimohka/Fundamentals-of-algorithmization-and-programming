#include "FFTProcessor.h"
#include "BaseEffect.h"
#include "Utils.h"
#include "coretypes.h"
#include <algorithm>
#include <cassert>
#include <qdatetime.h>
#include <qlabel.h>
#include <qstringtokenizer.h>
#include <qtimer.h>

void FFTProcessor::setUpUi(QWidget *widget) {
  BaseEffect::setUpUi(widget);
  // processingChannelLbl = new QLabel;
  // estTimeLbl = new QLabel;
  // estTimeLbl->setText("--:--");
  // layout->addRow("Processing channel: ", estTimeLbl->loadAcquire());
  // layout->addRow("Estimated time:", estTimeLbl->lo);
}

void FFTProcessor::_process(Sample *buf, int size, int max_range, short) {
  updateProcessingChannel();
  // total_chunks = size / HOP_SIZE;

  Sample *inBuf = new Sample[CHUNK_SIZE];
  Sample *outBuf = new Sample[CHUNK_SIZE];
  Sample *resBuf = new Sample[size + CHUNK_SIZE + HOP_SIZE * 2];
  for (int i = 0; i < size + CHUNK_SIZE; ++i) {
    resBuf[i] = 0;
  }

  double output_koef = (double)HOP_SIZE * 4 / CHUNK_SIZE;


  Utils::Frequencies freqs;

  auto hop = HOP_SIZE;
  auto win = Utils::cosSumWindow(CHUNK_SIZE - 1, CHUNK_SIZE);

  // chunckTimer->start();

  for (int i = 0; i < size; i += hop) {
    auto curChunkSize = std::min(CHUNK_SIZE, max_range - i);

    for (int inb_i = 0, b_i = i; inb_i < curChunkSize; inb_i++, b_i++) {
      inBuf[inb_i] = buf[b_i] * win[inb_i];
    }
    for (int inb_i = curChunkSize; inb_i < CHUNK_SIZE; ++inb_i) {
      inBuf[inb_i] = 0;
    }

    CHECK_STOP

    freqs = Utils::fft(inBuf, CHUNK_SIZE);
    processFftChunk(freqs);
    Utils::ifft(freqs, outBuf, CHUNK_SIZE);

    CHECK_STOP

    for (int res_i = i, out_i = 0; out_i < curChunkSize; ++res_i, ++out_i) {
      resBuf[res_i] +=
          output_koef * outBuf[out_i] * win[out_i] / (float)CHUNK_SIZE;
    }

    // updateEstimatedTime();
    // chunckTimer->restart();
    // --total_chunks;
  }

  for (int i = 0; i < size; ++i) {
    buf[i] = resBuf[i];
  }

  // chunckTimer->invalidate();

  delete[] resBuf;
  delete[] outBuf;
  delete[] inBuf;
  // ++processing_channel;
}

FFTProcessor::FFTProcessor(int chunk, int hop)
    : CHUNK_SIZE(chunk), HOP_SIZE(hop) {
  // chunckTimer = new QElapsedTimer;
}

FFTProcessor::~FFTProcessor() {}

void FFTProcessor::updateEstimatedTime() {
  // qreal dur = (double)chunckTimer->nsecsElapsed() / 1'000'000;
  // estTimeLbl->setText(QTime(0,0,0).addMSecs(dur * total_chunks).toString());
}

void FFTProcessor::updateProcessingChannel(){
  //processingChannelLbl->setText(QString::number(processing_channel));
}


void FFTProcessor::reset() {
  // processing_channel = 0;
}