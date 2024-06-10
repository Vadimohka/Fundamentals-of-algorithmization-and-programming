//
// Created by darina on 3/10/24.
//

#ifndef LAB_1_TASK_2_BASEFIGURE_H
#define LAB_1_TASK_2_BASEFIGURE_H

#include <QGraphicsObject>
#include <QWidget>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

#include<cmath>

class baseFigure : public QGraphicsObject {
public:

    baseFigure(int n, qreal xCenter, qreal yCenter, qreal xFinish, qreal yFinish);

    QRectF boundingRect() const final;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) final;

    qreal getPerimeter();

    qreal getSquare();

    std::pair<qreal, qreal> getCenter() const;

    void setX2(qreal x);

    void setY2(qreal y);

    void setDeltaX(qreal x);

    void setDeltaY(qreal y);

    void setRadiuse(qreal delta);

    void setEqual();

    void rotateAll(qreal angle);

private:
    qreal rotateAngle;
    qreal insideRadius = 1;
    const qreal minRadiuse = 0.01;
    qreal x1, x2, y1, y2;
    qreal xCenter, yCenter;
    qreal moveX, moveY;
    const int six = 6;
    qreal perimeter, fullSquare;
    void setPoints();


protected:
    bool equal = false;
    int numPoints;

    static std::pair<qreal, qreal> rotate(qreal x, qreal y, qreal angle);

    std::pair<qreal, qreal> changeSize(qreal x, qreal y) const;

    std::pair<qreal, qreal> move(qreal x, qreal y) const;

    std::pair<qreal, qreal> *points;
    std::pair<qreal, qreal> *basePoints;
};


#endif //LAB_1_TASK_2_BASEFIGURE_H
