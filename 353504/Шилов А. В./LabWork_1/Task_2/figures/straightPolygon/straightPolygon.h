//
// Created by darina on 3/12/24.
//

#ifndef LAB_1_TASK_2_STRAIGHTPOLYGON_H
#define LAB_1_TASK_2_STRAIGHTPOLYGON_H

#include "../baseFigure.h"
#include <QGraphicsObject>
#include <QWidget>


class straightPolygon : public baseFigure {

public:
    straightPolygon(int n, qreal x0, qreal y0, qreal x1, qreal y2, bool e);

private:
    void setBase();

};


#endif //LAB_1_TASK_2_STRAIGHTPOLYGON_H
