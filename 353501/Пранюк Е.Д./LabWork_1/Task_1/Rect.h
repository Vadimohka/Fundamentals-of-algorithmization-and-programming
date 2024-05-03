#ifndef RECT_H
#define RECT_H
#include <QGraphicsObject>
#include <QPainter>
#include <QTimer>

class Rect : public QGraphicsObject
{
public:
    Rect();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
private:
    int x, y, minY, maxY;
    QTimer *timerUp;
    QTimer *timerDown;
public slots:
    void moveUp();
    void moveDown();
};


#endif // RECT_H
