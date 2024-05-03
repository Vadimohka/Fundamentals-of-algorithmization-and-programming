#ifndef RING_H
#define RING_H
#include <QGraphicsItem>
#include <QPainter>
#include <QRandomGenerator>
#include <QDateTime>

class Ring : public QGraphicsItem, public QObject
{
public:
    Ring(qreal witdh);
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    qreal getWidth() const;

private:
    qreal width;
    int number;
};

#endif // RING_H
