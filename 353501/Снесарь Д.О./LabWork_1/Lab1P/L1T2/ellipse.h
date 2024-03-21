#ifndef ELLIPSE_H
#define ELLIPSE_H

#include  "figure.h"

class Ellipse : public Figure
{
protected:

    double xrad;
    double yrad;
    double rotAngle;

public:
    Ellipse();
    Ellipse(QPointF centr, QPointF size);
    void draw(QPainter *pntr) override;
    virtual void setSize(QPointF nPoint) override;
    void upScale() override;
    void downScale() override;
    void rotateL() override;
    void rotateR() override;
    virtual double getS() override;
    virtual double getP() override;
    int getId() override;
    QPointF getRadSize() override;



};

#endif // ELLIPSE_H
