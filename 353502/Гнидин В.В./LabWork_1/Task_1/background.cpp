//
// Created by volodya-petarda on 3/3/24.
//

#include "background.h"
#include <QPainter>

QRectF background::boundingRect() const {
    return {};
}

void background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap background("../background.jpg");
    painter->drawPixmap(-1920/2, -1080/2, background);
}
