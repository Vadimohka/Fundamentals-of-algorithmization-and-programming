#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>


class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Scene(qreal, qreal, qreal, qreal, QWidget *parent = nullptr);

public:
    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
    void keyPressEvent(QKeyEvent*) override;

signals:
    void signalMousePressEvent(QGraphicsSceneMouseEvent*);
    void signalMouseReleaseEvent(QGraphicsSceneMouseEvent*);
    void signalMouseMoveEvent(QGraphicsSceneMouseEvent*);
    void signalKeyPressEvent(QKeyEvent*);

};

#endif // SCENE_H
