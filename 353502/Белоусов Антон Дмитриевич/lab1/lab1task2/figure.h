#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include <QPainter>
#include "pointsMath.h"
#include <iostream>

class figure : public QGraphicsItem
{
public:
    figure();
    ~figure() override;
    void rotateFigureFromPointToPoint(QPointF a, QPointF b);
    void resizeFigureFromPointToPoint(QPointF a, QPointF b);
    virtual double getPerimeter() = 0;
    virtual double getSquare() = 0;
    virtual void setFigure(QPointF* points) = 0;
    void moveFigure(QPointF delta);
    void rotateFigure(double delta);
    void resizeFigure(double delta);
    QPointF *getPoints() const;
    QPointF* getMassCenter() const;
    int getPointNeeded() const;
    void setPoints(QPointF* points);
    void setMassCenter(QPointF* massCentre);
    void setPointNeeded(int pointsNeeded);
    virtual bool isPointInside(QPointF point) = 0;
private:
    QPointF* points;
    QPointF* massCenter;
    int pointsNeeded;
};

#endif // FIGURE_H
