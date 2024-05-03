#ifndef SHAPE_H
#define SHAPE_H

#include "figure.h"

class Shape : public Figure
{

protected:
    QVector<QPointF> points;
    double curAngle = 0;
public:
    Shape();
    void draw(QPainter *pntr) override;

    void move(QPointF nPoint) override;
    void setSize(QPointF nPoint) override;
    virtual void rotateR() override;
    virtual void rotateL() override;
    virtual void upScale() override;
    virtual void downScale() override;
    virtual double getS() override;
    virtual double getP() override;
    virtual int getId() override;
    int getAngle();
    double getCordCenterX();
    double getCordCenterY();
    QPointF getCenter();
    int getNumPoints();
    QPointF getPoint(int n);
    QVector<QPointF> getPointsVector() override;
    void setCenterEdit(QPointF newPoint, int pointN) override;

};

#endif // SHAPE_H
