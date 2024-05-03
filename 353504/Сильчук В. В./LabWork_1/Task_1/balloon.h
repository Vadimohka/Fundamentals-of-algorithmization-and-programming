#ifndef BALLOON_H
#define BALLOON_H

#include "movingellipse.h"
#include <QRectF>
#include <QPainter>

class Balloon : public Movingellipse
{
    Q_OBJECT
private:
    QRectF geometry;
    qreal coordY, coordX, balloonWidth, balloonHeight;
public:
    double scale = 1;
    Balloon(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
public slots:
    void burst();
    //void readyToBurst();
signals:
    void stopTimer2();
};

#endif // BALLOON_H
