#include "Ellipse.h"
#include <QPainter>
#include <qgraphicsitem.h>
#include <qobject.h>

Ellipse::Ellipse() {}
QRectF
Ellipse::boundingRect() const { // размеры и координаты прямоугольной области
                                // для понимания, где будет отображаться объект
  return QRectF(0, 0, 10, 10);
}

void moveEyes() {}
void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget) {
  painter->setBrush(Qt::blue);
  painter->drawEllipse(-50, 120, 200, 300);

  painter->setBrush(Qt::yellow); //(QColor(231, 204, 138))
  painter->drawEllipse(-50, -120, 200, 300);
}
