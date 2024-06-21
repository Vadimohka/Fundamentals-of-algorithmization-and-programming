#ifndef SQUARE_H
#define SQUARE_H


#include <figure.h>
#include <QPainter>

class Square : public Figure
{
    Q_OBJECT
public:
    explicit Square(QPointF point, QObject *parent = nullptr) : Figure(point, parent) {}
    ~Square() override = default;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // SQUARE_H
