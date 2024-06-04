//
// Created by volodya-petarda on 3/11/24.
//

#include "nstar.h"
#include "math.h"

nstar::nstar(int n) {
    n *= 2;
    this->num = n;
    this->n_verts = new std::pair<qreal, qreal>[n];
    qreal x = 0, y = 1;
    qreal ang = (360.0 / n) / 180 * M_PI;
    for(int i = 0; i < n; i++){
        qreal alpha = 1;
        if(i % 2 == 1)
            alpha = 0.5;
        n_verts[i] = {x * alpha, y * alpha};
        qreal nx = x * std::cos(ang) - y * sin(ang);
        qreal ny = x * std::sin(ang) + y * cos(ang);
        x = nx;
        y = ny;
    }
}
