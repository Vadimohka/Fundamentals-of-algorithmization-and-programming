    #ifndef PEN_H
#define PEN_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QDebug>

class Pen: public Figure
{
    public:
    Pen(QPointF point, QObject *parent = 0);
    QTimer *timer;
    private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void draw(QPainter *painter);
};
#endif // PEN_H
