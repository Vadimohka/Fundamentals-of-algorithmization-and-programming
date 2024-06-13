#ifndef FISH_H
#define FISH_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class Fish: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Fish(QObject *parent = 0);
    ~Fish();
    int *xj, *yj, *wj, *hj, x=500, y=500, w=60, h=60, points=0;;

    void move(int k);
public slots:
    void growFish(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget, int i);
signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // FISH_H
