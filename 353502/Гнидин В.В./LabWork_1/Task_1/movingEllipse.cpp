//
// Created by volodya-petarda on 3/3/24.
//

#include "movingEllipse.h"
#include <QPainter>
#include <QPixmap>
#include <QFile>

void movingEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(this->brushColor);
    painter->setPen(this->penColor);
    painter->drawEllipse(xPos, yPos, w, h);
    update();
}

void movingEllipse::move(int x, int y) {
    xPos = x;
    yPos = y;
    update();
}

void movingEllipse::setW(int tw) {
    this->w = tw;
    update();
}

void movingEllipse::setH(int th) {
    this->h = th;
    update();
}

movingEllipse::movingEllipse() {
    xPos = 0;
    yPos = 0;
}

QRectF movingEllipse::boundingRect() const {
    return {0, 0, 0, 0};
}

void movingEllipse::moveUp() {
    move(xPos, yPos - 3);
}

void movingEllipse::moveDown() {
    move(xPos, yPos + 3);
}

void movingEllipse::moveLeft() {
    move(xPos - 3, yPos);
}

void movingEllipse::moveRight() {
    move(xPos + 3, yPos);
}

movingEllipse::movingEllipse(int x, int y, int w, int h) {
    this->xPos = x;
    this->yPos = y;
    this->w = w;
    this->h = h;
}

void movingEllipse::subW() {
    this->w -= 3;
    update();
}

void movingEllipse::addW() {
    this->w += 3;
    update();
}

void movingEllipse::subH() {
    this->h -= 3;
    update();
}

void movingEllipse::addH() {
    this->h += 3;
    update();
}

void movingEllipse::setPenColor(Qt::GlobalColor color) {
    this->penColor = color;
}

void movingEllipse::setBrushColor(Qt::GlobalColor color) {
    this->brushColor = color;
}

