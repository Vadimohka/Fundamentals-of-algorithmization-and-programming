#include "movement.h"
movement::movement(){}
movement::movement(QPointF start_pos, QSizeF start_size) {
    setR(QRectF(start_pos, start_size));
}
void movement::setR(QRectF new_pos) {
    rect = new_pos;
}
QRectF& movement::getR() {
    return rect;
}
void movement::step(QPointF p) {
    rect.moveTo(rect.topLeft() + p);
}
void movement::my_animation(QPointF p, qreal delta) {
    if (!was_animation) {
        was_animation = true;
        QTimer *deley = new QTimer;
        QTimer *time_end = new QTimer;
        QObject::connect(deley, &QTimer::timeout, [=](){
            step(25*p / delta);
        });
        QObject::connect(time_end, &QTimer::timeout, [=](){
            step(25*p / delta);
            deley->stop();
            time_end->stop();
            was_animation = false;
        });
        deley->start(25);
        time_end->start(delta);
    }
}
