#include "AudioPixmap.h"
#include <QPainter>
#include <cmath>
#include <qbrush.h>
#include <qimage.h>
#include <qpixmap.h>

AudioPixmap::AudioPixmap(const Sample *sample, int sz, int width, int height,
                         QBrush brush_)
    : QPixmap(width, height), bufferSize(sz), brush(brush_) {
      buffer = sample;
      qDebug() << "buffer is set to " << buffer;
  drawWaveform(0, sz);
  }

void AudioPixmap::drawWaveform(int beg, int end) {

    fill(Qt::transparent);
    auto scale = height();
    auto step = (end-beg)/width();
    auto middle = height()/2;

    QPainter painter(this);
    painter.setPen(QPen(brush, 1, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));
    for (int x = 0, i = beg; x < width(); i += step, ++x) {
      auto higher_bound = std::min(bufferSize, i + step);
      auto average = getAverage(i, i + step);
      auto ampl = (float)average * scale;
      painter.drawLine(x, middle - ampl/2, x, middle + ampl/2);
    }  
}


float AudioPixmap::getAverage(int beg, int end) {
  auto len = end - beg;
  double sqared_sum = 0.;
  for(int i = beg; i < end; ++i){
    sqared_sum += buffer[i]*buffer[i];
  }
  auto mean = sqared_sum / len;
  return std::sqrt(mean); 
}
