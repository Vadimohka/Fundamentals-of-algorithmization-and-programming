#include "lowwerhand.h"

lowwerhand::lowwerhand(QWidget *parent): upperhand(parent) {}

void lowwerhand::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::green);

    painter.drawRect(0, 0, 50, 20);
}
void lowwerhand::salute(){
    QPropertyAnimation * animation = new QPropertyAnimation(this, "pos");
    animation -> setDuration(1000);
    animation -> setEndValue(QPointF(x() + 20, y() - 320));
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void lowwerhand::returnSalute(){
    QPropertyAnimation * animation2 = new QPropertyAnimation(this, "pos");
    animation2 -> setDuration(1000);
    animation2 -> setEndValue(QPointF(x() - 20, y() + 320));
    animation2 -> setEasingCurve(QEasingCurve::InOutQuad);
    animation2 -> start(QAbstractAnimation::DeleteWhenStopped);
}
