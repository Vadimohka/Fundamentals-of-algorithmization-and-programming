#include "paintScene.h"

#include <math.h>

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, 100, 100);
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (drawingTime)
    {
        addEllipse(event->scenePos().x() - 10,
                   event->scenePos().y() - 10,
                   20,
                   20,
                   QPen(Qt::NoPen),
                   QBrush(Qt::darkGreen));
        previousPoint = event->scenePos();
    }
    else
    {
        figure = nullptr;
        x_c = static_cast<float>(event->scenePos().x());
        y_c = static_cast<float>(event->scenePos().y());
    }
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (drawingTime)
    {
        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(Qt::GlobalColor::darkGreen,20,Qt::SolidLine,Qt::RoundCap));
        previousPoint = event->scenePos();
    }
    else
    {
        delete figure;
        float curx = static_cast<float>(event->scenePos().x());
        float cury = static_cast<float>(event->scenePos().y());
        float R = sqrtf(powf(x_c - curx, 2) + powf(y_c - cury, 2));
        float angle = acosf((curx - x_c) / R);
        if (y_c - cury < 0)
        {
            angle = acosf(-1) * 2 - angle;
        }

        figure = new star(x_c, y_c, angle, R, corners, isConvex);
        addItem(figure);

        setPS();
    }
}

void paintScene::setFigure(int _corners, bool _isConvex)
{
    drawingTime = false;
    corners = _corners;
    isConvex = _isConvex;
}

void paintScene::setTriangle()
{
    drawingTime = false;
    corners = 3;
}

void paintScene::setRect()
{
    drawingTime = false;
    corners = 4;
    isConvex = true;
}

void paintScene::setCircle()
{
    drawingTime = false;
    corners = 365;
    isConvex = true;
}

void paintScene::setRhombus()
{
    drawingTime = false;
    corners = 2;
    isConvex = false;
}

void paintScene::setDrawing()
{
    drawingTime = true;
}

void paintScene::moveFigure(int t)
{
    if (figure == nullptr)
    {
        return;
    }

    switch(t)
    {
        case 0:
            figure->move(0, -movingConst);
            break;
        case 1:
            figure->move(0, movingConst);
            break;
        case 2:
            figure->move(-movingConst, 0);
            break;
        case 3:
            figure->move(movingConst, 0);
            break;
        default:
            break;
    }
}

void paintScene::rotateFigure(int t)
{
    if (figure == nullptr)
    {
        return;
    }

    switch(t)
    {
        case 0:
            figure->rotate(rotateConst);
            break;
        case 1:
            figure->rotate(-rotateConst);
            break;
        default:
            break;
    }
}

void paintScene::changeFigureSize(int t)
{
    if (figure == nullptr)
    {
         return;
    }

    switch(t)
    {
        case 0:
            figure->changeR(-resizeConst);
            break;
        case 1:
            figure->changeR(resizeConst);
            break;
        default:
            break;
    }
}

void paintScene::setP(QLabel *x)
{
    p = x;
}

void paintScene::setSquare(QLabel *x)
{
    square = x;
}

void paintScene::setPS()
{
    if (figure == nullptr)
    {
        return;
    }

    float R = figure->getR();
    float angle = figure->getAngle();
    int convex = 0;
    if (isConvex)
    {
        convex = 1;
    }
    else
    {
        convex = 2;
    }

    float pi = acosf(-1);
    float gap = pi / static_cast<float>(corners) * static_cast<float>(1 + convex % 2);

    float r = R / 2;
    if (isConvex)
    {
        float tmp = R;
        tmp = tmp * tmp * sinf(pi * 2 / static_cast<float>(corners)) / 2;
        r = tmp / sqrtf(powf(sinf(angle) * R - sinf(angle + gap) * R, 2) + powf(cosf(angle) * R - cosf(angle + gap) * R, 2));
    }

    float per = sqrtf(powf(sinf(angle) * R - sinf(angle + gap) * r, 2) + powf(cosf(angle) * R - cosf(angle + gap) * r, 2));
    per *= static_cast<float>(corners * convex);
    float sq = per * r / 2;
    if (sq < 0)
    {
        sq = 0;
    }
    QString s = QString::number(per);
    p->setText(s);
    s = QString::number(sq);
    square->setText(s);
}


