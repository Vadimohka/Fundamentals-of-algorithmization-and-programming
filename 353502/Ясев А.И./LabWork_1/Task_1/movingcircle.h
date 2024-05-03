#ifndef MOVINGCIRCLE_H
#define MOVINGCIRCLE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class MovingCircle : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MovingCircle(QGraphicsScene *parent = 0);
    ~MovingCircle();
public slots:
    void moveLeft();
    void moveRight();
protected:
    bool isrotated = false;
    QPointF center;
    qreal step;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MOVINGCIRCLE_H
