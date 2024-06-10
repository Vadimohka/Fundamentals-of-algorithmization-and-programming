#include "abstractfigure.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

abstractFigure::abstractFigure(QPointF point, QObject* parent)
    : QObject(parent), QGraphicsItem() {
  this->setStartPoint(mapFromScene(point));
  this->setEndPoint(mapFromScene(point));
  connect(this, &abstractFigure::pointChanged, this,
          &abstractFigure::updateFigure);
}

QRectF abstractFigure::boundingRect() const {
  return {
      (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) -
          5,
      (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) -
          5,
      qAbs(endPoint().x() - startPoint().x()) + 10,
      qAbs(endPoint().y() - startPoint().y()) + 10};
}

void abstractFigure::updateFigure() {
  this->update(
      (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) -
          5,
      (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) -
          5,
      qAbs(endPoint().x() - startPoint().x()) + 10,
      qAbs(endPoint().y() - startPoint().y()) + 10);
}

void abstractFigure::setStartPoint(const QPointF point) {
  MstartPoint = mapFromScene(point);
  emit pointChanged();
}

void abstractFigure::setEndPoint(const QPointF point) {
  MendPoint = mapFromScene(point);
  emit pointChanged();
}

auto abstractFigure::startPoint() const -> QPointF {
  return MstartPoint;
}

auto abstractFigure::endPoint() const -> QPointF {
  return MendPoint;
}

/*
void abstractFigure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
      Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
/*  this->setPos(mapToScene(event->pos()));
}
void abstractFigure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
      При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
/* this->setCursor(QCursor(Qt::ClosedHandCursor));
     Q_UNUSED(event);
}*/
/*
void abstractFigure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
     При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
/*  this->setCursor(QCursor(Qt::ArrowCursor));
     Q_UNUSED(event);
}
*/
