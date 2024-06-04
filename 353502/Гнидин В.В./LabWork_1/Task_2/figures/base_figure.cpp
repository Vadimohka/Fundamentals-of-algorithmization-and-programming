//
// Created by volodya-petarda on 3/10/24.
//

#include "base_figure.h"
#include <QPainter>
#include <QDebug>
#include <cmath>

qreal dist(qreal x1, qreal y1, qreal x2, qreal y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void base_figure::setScaled(qreal x, qreal y) {
    this->scaled_x = x;
    this->scaled_y = y;
    update();
}

QRectF base_figure::boundingRect() const {
    return {0, 0, 0, 0};
}

void base_figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    for (int i = 0; i < num - 1; i++) {
        qreal x1 = n_verts[i].first * scaled_x + x_pos;
        qreal y1 = n_verts[i].second * scaled_y + y_pos;
        qreal x2 = n_verts[i + 1].first * scaled_x + x_pos;
        qreal y2 = n_verts[i + 1].second * scaled_y + y_pos;
        painter->drawLine(x1, y1, x2, y2);
    }
    qreal x1 = n_verts[num - 1].first * scaled_x + x_pos;
    qreal y1 = n_verts[num - 1].second * scaled_y + y_pos;
    qreal x2 = n_verts[0].first * scaled_x + x_pos;
    qreal y2 = n_verts[0].second * scaled_y + y_pos;
    painter->drawLine(x1, y1, x2, y2);
}

void base_figure::setFigurePos(qreal x, qreal y) {
    this->x_pos = x;
    this->y_pos = y;
    update();
}

base_figure::base_figure() {
    this->num = 100;
    n_verts = new std::pair<qreal, qreal>[100];
    for (int i = 0; i < 100; i++) {
        qreal r1 = (qreal) rand() / RAND_MAX;
        qreal r2 = (qreal) rand() / RAND_MAX;
        if (rand() % 2 == 0)
            r1 *= -1;
        if (rand() % 2 == 0)
            r2 *= -1;
        n_verts[i] = {r1, r2};
    }
    scaled_x = 10;
    scaled_y = 10;
}

void base_figure::rotate(qreal ang) {
    for (int i = 0; i < this->num; i++) {
        qreal x = n_verts[i].first;
        qreal y = n_verts[i].second;
        qreal nx = x * std::cos(ang) - y * sin(ang);
        qreal ny = x * std::sin(ang) + y * cos(ang);
        n_verts[i].first = nx;
        n_verts[i].second = ny;
    }
    update();
}

void base_figure::rotateLeft() {
    rotate(-0.03);
}

void base_figure::rotateRight() {
    rotate(0.03);
}

void base_figure::moveLeft() {
    x_pos--;
}

void base_figure::moveRight() {
    x_pos++;
}

void base_figure::moveUp() {
    y_pos--;
}

void base_figure::moveDown() {
    y_pos++;
}

qreal base_figure::getPerimetr() {
    qreal sum = 0;
    for (int i = 1; i < num; i++) {
        sum += dist(n_verts[i].first, n_verts[i].second, n_verts[i - 1].first, n_verts[i - 1].second);
    }
    sum += dist(n_verts[0].first, n_verts[0].second, n_verts[num - 1].first, n_verts[num - 1].second);
    sum = sum * (scaled_x + scaled_y);
    if (sum < 0)
        return -sum;
    return sum;
}


qreal base_figure::getS() {
    qreal sum = 0;
    for (int i = 1; i < num; i++) {
        sum += dist(0, 0, n_verts[i - 1].first, n_verts[i - 1].second) *
               dist(0, 0, n_verts[i].first, n_verts[i].second) * sin(M_PI / num * 2);
    }
    sum += dist(0, 0, n_verts[0].first, n_verts[0].second) *
           dist(0, 0, n_verts[num - 1].first, n_verts[num - 1].second) * sin(M_PI / num * 2);
    sum *= scaled_x * scaled_y;
    if (sum < 0)
        return -sum;
    return sum;
}
