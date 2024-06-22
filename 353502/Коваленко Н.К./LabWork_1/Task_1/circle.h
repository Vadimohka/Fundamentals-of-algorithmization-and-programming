#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class Circle : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Circle(QGraphicsScene *parent = 0);
    ~Circle();
public slots:
    void moveLeft();
    void moveRight();
    void moveCenter();
protected:
    bool isrotated = false;
    QPointF center;
    qreal step;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CIRCLE_H
