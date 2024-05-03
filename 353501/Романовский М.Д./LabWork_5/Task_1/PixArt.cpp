#include "PixArt.h"
#include <QPainter>
#include <qgraphicsitem.h>
#include <qnamespace.h>
#include <qobject.h>

QMap<char, QBrush> defaultColormap = {
    {'b', Qt::black},
    {'r', Qt::red},
    {'w', Qt::white},
    {'c', Qt::magenta},
    {'l', Qt::blue}
};

PixArt::PixArt(const char *art, int pixSize, QGraphicsItem *parent)
    : QGraphicsObject(parent), art(art), pixSize(pixSize) {
  colorMap = defaultColormap;
}

void PixArt::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget) {
  painter->setPen(Qt::NoPen);

  for (int y = 0; y < 16; y++) {
    float ypos = (y - 8) * pixSize;
    for (int x = 0; x < 16; x++) {
      float xpos = (x - 8) * pixSize;
      char color = art[y * 16 + x];
      if (color == '_')
        continue;

      painter->setBrush(colorMap.contains(color) ? colorMap[color] : Qt::white);
      painter->drawRect(xpos, ypos, pixSize, pixSize);
    }
  }
}

QRectF PixArt::boundingRect() const {
  return QRectF(-pixSize * 8, -pixSize * 8, pixSize * 16, pixSize * 16);
}

void PixArt::updateColormap(char from, QBrush to) {
  colorMap[from] = to;
  update();
}