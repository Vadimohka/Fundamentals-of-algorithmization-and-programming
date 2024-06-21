#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>


class Canvas : public QGraphicsScene
{
public:
    explicit Canvas(QObject *parent) : QGraphicsScene(parent) {}
    ~Canvas() override = default;

private:
    QPointF point;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CANVAS_H
