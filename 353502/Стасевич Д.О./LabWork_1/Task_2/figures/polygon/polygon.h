//
// Created by darina on 3/11/24.
//

#ifndef LAB_1_TASK_2_POLYGON_H
#define LAB_1_TASK_2_POLYGON_H

#include "../baseFigure.h"
#include <QGraphicsObject>
#include <QWidget>
#include <cmath>


class polygon : public baseFigure {

public:
    polygon(int n, qreal x0, qreal y0, qreal x1, qreal y2);

private:
    void setBase();

};


#endif //LAB_1_TASK_2_POLYGON_H
