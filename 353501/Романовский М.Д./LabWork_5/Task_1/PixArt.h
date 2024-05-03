#pragma once

#include <QGraphicsObject>
#include <qgraphicsitem.h>

class PixArt : public QGraphicsObject {
  Q_OBJECT

public:
  PixArt(const char *art, int pixSize, QGraphicsItem *parent = nullptr);

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

  QRectF boundingRect() const override;

  void updateColormap(char from, QBrush to);
private:
  QMap<char, QBrush> colorMap;
  const char *art;
  int pixSize;
};