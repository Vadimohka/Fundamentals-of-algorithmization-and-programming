#ifndef LIFT_H
#define LIFT_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QRadioButton>
#include <QTimer>
#include <QColor>

class lift : public QGraphicsItem
{
public:
    lift();

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* opinion, QWidget* widget ) override;
    QRectF boundingRect() const override;
};

#endif // LIFT_H
