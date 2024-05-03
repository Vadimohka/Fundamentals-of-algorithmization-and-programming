#ifndef BASE_H
#define BASE_H

#include <QWidget>
#include <QInputDialog>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsRotation>
#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QPolygonF>
#include <QPointF>
#include <QtMath>


class base:  public QWidget, public QGraphicsRectItem
{
    Q_OBJECT
public:
    base();
    virtual void draw(QGraphicsScene *scene, int width, int height, int a, int &h) = 0;

    virtual void perSquareMasse(int width, int height, int a) = 0;
    virtual void getParametrs(int &side1, int &side2, int &side3, int a) = 0;

    void centerMasse(QGraphicsScene *scene, int &x, int &y);
    void up(QGraphicsScene *scene, int &x, int &y);
    void down(QGraphicsScene *scene, int &x, int &y);
    void left(QGraphicsScene *scene, int &x, int &y);
    void right(QGraphicsScene *scene, int &x, int &y);
    void rotateLeft(QGraphicsScene *scene,int x, int y, int a);
    void rotateRight(QGraphicsScene *scene, int x, int y, int a);
    void moveToObject(QGraphicsView *view, int x, int y);

signals:
    void sendPerimetr(double perimetr);
    void sendSquare(double square);

};

#endif // BASE_H
