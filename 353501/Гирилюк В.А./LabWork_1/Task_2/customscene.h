#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include "shape.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class CustomScene: public QGraphicsScene, public Shape
{

public:
    QPointF point;
    explicit CustomScene(QObject *parent = 0);
    ~CustomScene();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // CUSTOMSCENE_H
