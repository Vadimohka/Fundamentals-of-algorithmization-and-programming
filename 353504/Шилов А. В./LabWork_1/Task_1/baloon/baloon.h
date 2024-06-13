//
// Created by darina on 3/9/24.
//

#ifndef LAB_BALOON_H
#define LAB_BALOON_H

#include "../movingEllipse/movingEllipse.h"

class baloon : public movingEllipse{

public:
    baloon(qint32 x, qint32 y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //void move(qint32 x, qint32 y);

private:
    qint32 x_size, y_size;

protected:
    baloon *Baloon;

};


#endif //LAB_BALOON_H
