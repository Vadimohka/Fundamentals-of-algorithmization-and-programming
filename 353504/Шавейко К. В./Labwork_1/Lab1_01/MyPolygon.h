#ifndef MYPOLYGON_H
#define MYPOLYGON_H

#include <QGraphicsObject>
#include <QPainter>

class MyPolygon : public QGraphicsObject
{
    Q_OBJECT
public:
    MyPolygon();
    ~MyPolygon() override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPolygonF m_polygon;
};

#endif // MYPOLYGON_H
