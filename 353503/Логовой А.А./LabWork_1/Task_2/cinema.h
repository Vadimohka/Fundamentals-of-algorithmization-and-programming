#ifndef CINEMA_H
#define CINEMA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

class Cinema : public QGraphicsScene

{
    Q_OBJECT
public:
    explicit Cinema(QObject *parent = nullptr);

    ~Cinema();

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:

    void signalMouseDoubleLeftClickEvent(QGraphicsSceneMouseEvent *event);

    void signalMousePressLeftButtonEvent(QGraphicsSceneMouseEvent *event);

    void signalMouseReleaseLeftButtonEvent(QGraphicsSceneMouseEvent *event);

    void signalMouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CINEMA_H
