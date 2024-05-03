#ifndef LAB0T2_FIGURES_H
#define LAB0T2_FIGURES_H

#include <QtWidgets>

#define PI 3.141592

class Figures {
    virtual void move();

protected:
    QPointF pressDragPosition;
    QPointF nowDragPisition;
    QPointF pressPosition;
    QPointF nowPosition;
    QPointF centerPoint;
    QPointF* points = new QPointF[16];
    int pointsCount = 0;
    int flag;
    double difx;
    double dify;
    double angle;
    double nowAngle;
    double square;
    double perimetr;

    QPointF rotatePoint(const QPointF, const QPointF, const double);
    double distance(QPointF, QPointF);
    int sign(const double);

public:
    Figures();

    virtual void mousePress(QMouseEvent*);
    void mouseMove(QMouseEvent*);
    void mouseDragPress(QMouseEvent*);
    void mouseDragMove(QMouseEvent*);
    virtual void create(QPainter*);

    virtual void setPoints(QMouseEvent*);
    void setCenterPoint(const double, const double);
    virtual void setNewPoints(const double, const int);
    virtual void setParameters(const double, const int);

    int getPointsCount();
    double getSquare();
    double getPerimetr();
    int getFlag();
    QPointF getCenterPoint();

    virtual void updateData();
    void resizePlus();
    void resizeMinus();
    void rotateLeft();
    void rotateRight();
    void clear();
};


#endif
