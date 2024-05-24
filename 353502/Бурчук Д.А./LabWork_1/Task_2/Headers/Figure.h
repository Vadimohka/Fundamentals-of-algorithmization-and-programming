#ifndef LAB1TASK2_FIGURE_H
#define LAB1TASK2_FIGURE_H


#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <QtMath>
#include <QPolygon>
#include <vector>


class Figure : public QWidget {
    Q_OBJECT
public:
    Figure(QWidget *parent, std::vector <QPointF> points);

    ~Figure() override;

    virtual void draw(QPainter *painter) = 0;

    virtual void drawPress(QMouseEvent *event);

    virtual void drawMove(QMouseEvent *event) = 0;

    QPointF *_center;

    long double _perimeter;

    long double _area;

    long double _thorns;

    std::vector <QPointF> points;
public
    slots:

            void startRotationLeft();

    void stopRotationLeft();

    virtual void rotateLeft();

    void startRotationRight();

    void stopRotationRight();

    virtual void rotateRight();

    void startIncreasingSize();

    void stopIncreasingSize();

    virtual void increasingSize();

    void startDiminishingSize();

    void stopDiminishingSize();

    virtual void diminishingSize();

    virtual void changeStar(int newThorns);

public:
    void startMoving(QMouseEvent *event);

    void movingInTime();

    void movingClick(QMouseEvent *event);

protected:
    QTimer *_timer;

    QPointF _insertionPoint;

    QPolygonF _polygon;

    QPointF eventMove;

    QPointF eventClickC;

    QPointF eventClickI;

    std::vector <QPointF> eventDifference;

    virtual void findArea() = 0;

    virtual void findPerimeter() = 0;
};


#endif //LAB1TASK2_FIGURE_H
