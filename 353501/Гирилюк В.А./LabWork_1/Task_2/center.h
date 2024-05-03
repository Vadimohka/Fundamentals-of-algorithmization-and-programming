#ifndef CENTER_H
#define CENTER_H

#include <QPainter>
#include <QGraphicsObject>

class Center: public QGraphicsObject
{

public:
    Center(QGraphicsItem *parent = nullptr);
    ~Center();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // CENTER_H
