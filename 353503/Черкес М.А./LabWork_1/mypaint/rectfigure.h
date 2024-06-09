#ifndef RECTFIGURE_H
#define RECTFIGURE_H

#include <QGraphicsItem>
#include <QObject>
#include "QPainter"
#include "abstractfigure.h"

class RectFigure : public abstractFigure {
  Q_OBJECT
 public:
  explicit RectFigure(QPointF point, QObject* parent = 0);
  QRectF boundingRect() const override;
  // void drawFigure(QPainter *painter) override;
 private:
  void Дpaint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget);
};

#endif  // RECTFIGURE_H
