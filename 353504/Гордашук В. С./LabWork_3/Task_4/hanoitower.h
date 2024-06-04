#ifndef HANOITOWER_H
#define HANOITOWER_H

#include <QDebug>
#include <QGraphicsItem>
#include <QPainter>
#include <QVector>

class HanoiTower : public QGraphicsItem
{
public:
    HanoiTower(int n);

    void hanoi(int n, int first, int third, int second);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QVector<int> from;
    QVector<int> to;

protected:
    int n_;
};

#endif // HANOITOWER_H
