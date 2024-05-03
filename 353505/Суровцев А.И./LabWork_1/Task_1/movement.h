#ifndef movement_H
#define movement_H

#include <QMainWindow>
#include <QPointF>
#include <QSizeF>
#include <QTimer>
#include <QPainter>
#include <QDebug>

class movement
{
public:
    movement();
    movement(QPointF start_pos, QSizeF start_size);
    void setR(QRectF);
    QRectF& getR();
    void step(QPointF p);
    void my_animation(QPointF p, qreal delta);
private:
    QRectF rect;
    bool was_animation = false;
};

#endif // movement_H
