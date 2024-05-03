#include "arrow.h"

Arrow::Arrow()
{

}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::NoBrush);
    painter->setPen(QPen(QColorConstants::Svg::pink, Figure::k));
    double r = sqrt(pow(Figure::startPoint.x() - Figure::endPoint.x(), 2) + pow(Figure::startPoint.y() - Figure::endPoint.y(), 2));
    QPolygonF polygon;

    // Определяем вершины песочных часов
    QPointF topPoint(Figure::startPoint.x(), Figure::startPoint.y() - r);
    QPointF bottomPoint(Figure::startPoint.x(), Figure::startPoint.y() + r);
    QPointF leftPoint(Figure::startPoint.x() - r, Figure::startPoint.y());
    QPointF rightPoint(Figure::startPoint.x() + r, Figure::startPoint.y());

    // Добавляем вершины песочных часов в полигон
    polygon << topPoint << rightPoint << bottomPoint << leftPoint;

    // Рисуем песочные часы
    painter->drawPolygon(polygon);
}
