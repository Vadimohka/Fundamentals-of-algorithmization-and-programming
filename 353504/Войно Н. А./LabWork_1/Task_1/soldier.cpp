#include "soldier.h"

soldier::soldier(QWidget *parent): Move_rec(parent){
    setFixedSize(200, 450);
}

void soldier::paintEvent(QPaintEvent *){
    QPainter painter(this);

    QRect Rectungle(0, 100, 250, 450);
    painter.fillRect(Rectungle, Qt::darkGreen);

    painter.setBrush(Qt::black);
    painter.drawEllipse(50, 0, 100, 100);
}


