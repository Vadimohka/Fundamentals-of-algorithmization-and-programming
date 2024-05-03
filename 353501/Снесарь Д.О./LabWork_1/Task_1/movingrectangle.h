#ifndef MOVINGRECTANGLE_H
#define MOVINGRECTANGLE_H


#include <QGraphicsItem>
#include <QPointF>
#include <QPainter>
#include <QWidget>
#include <QObject>

class MovingRectangle: public QGraphicsItem, public QObject
{
    //Q_OBJECT

public:
    MovingRectangle();
    void rotateR();
    void rotateL();
/*protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;*/
};

#endif // MOVINGRECTANGLE_H
