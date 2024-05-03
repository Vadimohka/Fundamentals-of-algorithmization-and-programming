#include "upperhand.h"

upperhand::upperhand(QWidget *parent): Move_rec(parent) {
    setFixedSize(50,200);
}
void upperhand::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, 100, 300);
}

void upperhand::salute(){
    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(1000);
    animation->setEndValue(QPointF(x(), y() - 100));
    animation->setEasingCurve(QEasingCurve::InOutQuad);

    animation->start(QAbstractAnimation::DeleteWhenStopped);

    //usleep(3000000);
    //QTimer::singleShot(2000, this, &upperhand::returnSalute);


}

void upperhand::returnSalute(){
    //usleep(3000000);
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "pos");
    animation1->setDuration(1000);
    animation1->setEndValue(QPointF(x(), y() + 100));
    animation1->start(QAbstractAnimation::DeleteWhenStopped);
    animation1->setEasingCurve(QEasingCurve::InOutQuad);
    animation1->start(QAbstractAnimation::DeleteWhenStopped);
}

void upperhand::timer(){
    QTimer * timer = new QTimer();
    timer -> start(1000);
}
