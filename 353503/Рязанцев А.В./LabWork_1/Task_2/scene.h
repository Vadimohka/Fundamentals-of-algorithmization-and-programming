#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Scene(qreal x, qreal y, qreal a, qreal b);


public:
    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
    void wheelEvent(QGraphicsSceneWheelEvent*) override;
    void keyPressEvent(QKeyEvent*) override;

signals:
    void signalMousePressEvent(QGraphicsSceneMouseEvent*);
    void signalMouseMoveEvent(QGraphicsSceneMouseEvent*);
    void signalMouseReleaseEvent(QGraphicsSceneMouseEvent*);
    void signalWheelRotationEvent(QGraphicsSceneWheelEvent*);
    void signalKeyPressEvent(QKeyEvent*);
};

#endif // SCENE_H
