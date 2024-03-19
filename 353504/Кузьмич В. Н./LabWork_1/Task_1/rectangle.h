#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsObject>

#include <QPainter>

class rectangle : public QGraphicsObject
{
public:
    QRectF boundingRect() const;
    int per_x = 0;
    long double grad = 0;
    void per_left();
    void per_right();
    bool is_left();
    bool is_right();

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // RECTANGLE_H
