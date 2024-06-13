#ifndef FIGURE_H
#define FIGURE_H

#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QtMath>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QPolygon>

const int BIG_NUM = 2000;
const double LESS=0.95;
const double MORE=1.05;

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int status = 1;
    double square, perimetr, defaultdist, defaultDist;
    QPointF mouseNow, mousePress, centre;
    QVector <QPointF> vertices;
    QPair <double, double> defaultVector;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    virtual void updateSquare() = 0;
    virtual void updatePerimetr();
    virtual void updateCentre();
    virtual void updateInfo();
    double dist(QPointF, QPointF);
    double angle(QPair <double, double> a, QPair <double, double> b);
    double calcAngle(QPair <double, double> a, QPair <double, double> b);
    void resizeFigure(QGraphicsSceneMouseEvent* mouse);
    void rotateFigure(QGraphicsSceneMouseEvent* mouse);

signals:
    void isSceneUpdate();
    void printSquare(const double &square);
    void printPerimetr(const double &perimetr);
    void printCentre(const QPointF &centre);
};

#endif // FIGURE_H
