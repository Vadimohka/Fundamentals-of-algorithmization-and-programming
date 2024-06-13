#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QBrush>


class Rectangle : public QGraphicsRectItem, public QObject
{
public:
    Rectangle(qreal, qreal, qreal, qreal, QGraphicsItem* parent = nullptr);

    qreal x,y;
    qreal width, height;

    QPointF Pos();

    void SetPos(QPointF);
    void SetX(qreal);

    void SetColor(QColor);
    qreal GetX();
    qreal GetY();
    qreal GetWidth();
    qreal GetHeight();




};

#endif // RECTANGLE_H
