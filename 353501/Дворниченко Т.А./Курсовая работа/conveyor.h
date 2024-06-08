#ifndef CONVEYOR_H
#define CONVEYOR_H
#include <QGraphicsItem>
#include <QPixmap>

class Conveyor : public QGraphicsItem
{
public:
    Conveyor(QGraphicsItem *parent = 0);
    void nextFrame11();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    int mCurrentFrame11;
    QPixmap mPixmap11;
};
#endif // CONVEYOR_H
