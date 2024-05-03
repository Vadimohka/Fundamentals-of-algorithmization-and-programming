#ifndef MOVEABLERECT_H
#define MOVEABLERECT_H

#include <QPainter>
#include <QGraphicsObject>


class MoveableRect : public QGraphicsObject
{
public:
    MoveableRect(QGraphicsObject *parent = nullptr);
    MoveableRect(int x, int y, int w, int h, QGraphicsObject *parent = nullptr);
    MoveableRect(int x, int y, int w, int h, QColor color, QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public slots:
    virtual void rotate();

private:
    QRect *rect;
    float angle;
    QColor rect_color;
};

#endif // MOVEABLERECT_H
