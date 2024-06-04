#include "coretypes.h"
#include <qbrush.h>
#include <qgraphicsitem.h>
#include <qpixmap.h>

class AudioPixmap : public QPixmap{
private:
  const Sample* buffer;
  int bufferSize;

  void drawWaveform(int beg, int end);
  float getAverage(int beg, int end);
  QBrush brush;

public:
  AudioPixmap(const Sample *sample, int sz, int width, int height, QBrush brush);
  void scale(int width, int height, int start, int end);

};