#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class Circle : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

public:

    Circle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr );

public slots:
    void move( int angle );

signals:
};

#endif // CIRCLE_H
