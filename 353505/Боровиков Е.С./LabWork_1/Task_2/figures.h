#ifndef LAB0T2_FIGURES_H
#define LAB0T2_FIGURES_H

#include <QtWidgets>

class figures {
    virtual void move();

    void resize();
    void changeAngle(int newAngle);
    virtual void updateCenter();

    int lastDegree = 0;

protected:

    double scale = 1;
    double lastScale = 1;

    QPoint mouseMovePress;
    QPoint mouseMoveNow;
    QPoint mousePress;
    QPoint mouseNow;

    virtual void findSquare();
    virtual void findPerimeter();

    QVector<QPointF> points;

public:
    figures();

    virtual void clear() {
        scale = 1;
        lastScale = 1;
        points.clear();
        perimeter = 0;
        square = 0;
        center = {0, 0};
    }

    virtual void draw(QPainter *);

    void mousePressing(QMouseEvent *);

    void mouseMoving(QMouseEvent *);

    virtual void setPoints(QMouseEvent *);

    void mouseMovePressing(QMouseEvent *);

    void mouseMoveMoving(QMouseEvent *);

    void upScale();
    void downScale();

    void rotateLEFT();
    void rotateRIGHT();

    bool isShift = false;
    QPointF center;
    double square{};
    double perimeter{};
};


#endif
