#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include <figure.h>

class Rectangle : public Figure
{
    Q_OBJECT
public:
    explicit Rectangle(QPointF point, QObject *parent = nullptr);
    QColor myColor = randomColor();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QVector<QPointF> points;
};

#endif // RECTANGLE_H
