#ifndef TRIANGLE_H
#define TRIANGLE_H


#include <figure.h>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsSceneEvent>

class Triangle : public Figure
{
    Q_OBJECT
public:
    explicit Triangle(QPointF point, QObject *parent = nullptr) : Figure(point, parent){}
    ~Triangle() override = default;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // TRIANGLE_H
