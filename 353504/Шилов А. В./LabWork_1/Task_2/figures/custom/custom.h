//
// Created by darina on 3/16/24.
//

#ifndef LAB_1_TASK_2_CUSTOM_H
#define LAB_1_TASK_2_CUSTOM_H

#include "../baseFigure.h"
#include <QGraphicsObject>
#include <QWidget>
#include <cmath>

class custom : public baseFigure {
public:
    custom(int n, qreal x0, qreal y0, qreal x1, qreal y1);

private:
    void setBase();
};


#endif //LAB_1_TASK_2_CUSTOM_H
