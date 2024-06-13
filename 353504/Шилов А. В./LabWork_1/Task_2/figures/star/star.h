//
// Created by darina on 3/12/24.
//

#ifndef LAB_1_TASK_2_STAR_H
#define LAB_1_TASK_2_STAR_H


#include "../baseFigure.h"
#include <QGraphicsObject>
#include <QWidget>
#include <cmath>

class star : public baseFigure {
public:
    star(int n, qreal x0, qreal y0, qreal x1, qreal y1);

private:
    void setBase();
};


#endif //LAB_1_TASK_2_STAR_H
