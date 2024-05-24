//
// Created by volodya-petarda on 3/11/24.
//

#include "npolygon.h"
#include "base_figure.h"
#include <cmath>
#include <QDebug>

npolygon::npolygon(int n) {
    this->num = n;
    this->n_verts = new std::pair<qreal, qreal>[n];
    qreal x = 0, y = 1;
    qreal ang = (360.0 / n) / 180 * M_PI;
    for (int i = 0; i < n; i++) {
        n_verts[i] = {x, y};
        qreal nx = x * std::cos(ang) - y * sin(ang);
        qreal ny = x * std::sin(ang) + y * cos(ang);
        x = nx;
        y = ny;
    }
}
