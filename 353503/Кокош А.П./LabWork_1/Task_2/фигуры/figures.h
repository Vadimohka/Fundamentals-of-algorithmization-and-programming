#ifndef FIGURES_H
#define FIGURES_H

#include <QtWidgets>

class figures
{
    virtual void move();

    void resize();

    void angle(int newAngle);

    virtual void moveCenter();

    int lastDegree = 0;

protected:
    double scale = 1;
    double lastScale = 1;

    QPoint mouseMoveWhenPress;
    QPoint mouseMoveCurrentPos;
    QPoint mouseWhenPress;
    QPoint mouseCurrentPos;

    virtual void findSquare();
    virtual void findPerimetr();

    QVector<QPointF> points;

public:
    figures();

    virtual void clear()
    {
        scale = 1;
        lastScale = 1;
        square = 0;
        perimetr = 0;
        points.clear();
        center = {0, 0};
    }

    virtual void moveByCord(int x, int y);

    virtual void draw(QPainter * /*unused*/);

    void mousePressing(QMouseEvent * /*event*/);

    void mouseMoving(QMouseEvent * /*event*/);

    virtual void setPoints(QMouseEvent * /*event*/);

    void mouseMovePressing(QMouseEvent * /*event*/);

    void mouseMoveMoving(QMouseEvent * /*event*/);

    void upScale();
    void downScale();

    void rotateLeft();
    void rotateRight();

    bool isShift = false;

    QPointF center;
    double square{};
    double perimetr{};
};

#endif // FIGURES_H
