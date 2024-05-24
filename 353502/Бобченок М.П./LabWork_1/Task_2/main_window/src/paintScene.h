//
// Created by u on 10.03.24.
//

#ifndef PAINTDEGRODATED_PAINTSCENE_H
#define PAINTDEGRODATED_PAINTSCENE_H


#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <cmath>
#include "figures/star.h"

class paintScene : public QGraphicsScene {
    Q_OBJECT
private:
    const float movingConst = 10;
    const float rotateConst = 0.1;
    const float resizeConst = 5;
    QPointF previousPoint;
    bool drawingTime = true;
    bool isConvex{};
    int corners = 4;
    float x_c{}, y_c{};
    star *figure = nullptr;
    QLabel *p{};
    QLabel *square{};

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

public slots:
    void setFigure(int _corners, bool _isConvex);

    void setTriangle();

    void setRect();

    void setCircle();

    void setRhombus();

    void setDrawing();

public:
    void setPS();

    void moveFigure(int t);

    void rotateFigure(int t);

    void changeFigureSize(int t);

    void setP(QLabel *x);

    void setSquare(QLabel *x);

    explicit paintScene(QObject *parent = nullptr);
};


#endif //PAINTDEGRODATED_PAINTSCENE_H
