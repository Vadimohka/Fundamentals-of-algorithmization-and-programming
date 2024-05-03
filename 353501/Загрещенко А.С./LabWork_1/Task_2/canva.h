#ifndef CANVA_H
#define CANVA_H

#include <QGraphicsScene>
#include "QMouseEvent"
#include "abstractfigure.h"
#include "ellipsefigure.h"
#include <QMainWindow>
#include "QVector"
#include "QGraphicsItem"

class Canva : public QGraphicsScene {
Q_OBJECT

public:
    explicit Canva(QObject *parent = nullptr);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:

    void signalMouseDoubleLeftClickEvent(QGraphicsSceneMouseEvent *event);

    void signalMousePressLeftButtonEvent(QGraphicsSceneMouseEvent *event);

    void signalMousePressRightButtonEvent(QGraphicsSceneMouseEvent *event);

    void signalMouseReleaseLeftButtonEvent(QGraphicsSceneMouseEvent *event);

    void signalMouseReleaseRightButtonEvent(QGraphicsSceneMouseEvent *event);

    void signalMouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CANVA_H
