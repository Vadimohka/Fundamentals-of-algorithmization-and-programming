#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene(QObject *parent = nullptr);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

signals:
    void MyMouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYSCENE_H
