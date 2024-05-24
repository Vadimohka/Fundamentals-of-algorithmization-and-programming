//
// Created by darina on 4/10/24.
//

#include "TowersBase.h"


void TowersBase::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::darkGray);
    painter->setPen(Qt::black);
    painter->drawRect(-300, 100, 600, 40);
    painter->setBrush(Qt::gray);
    painter->drawRect(-200, 100, 20, -300);
    painter->drawRect(0, 100, 20, -300);
    painter->drawRect(200, 100, 20, -300);


}

QRectF TowersBase::boundingRect() const {
    return {0, 0, 0, 0};
}

TowersBase::TowersBase() {

}
