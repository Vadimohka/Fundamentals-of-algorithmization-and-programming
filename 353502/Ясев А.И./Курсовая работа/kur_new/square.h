#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsObject>
#include <QPainter>
#include <QtMath>
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDir>


class Square : public QGraphicsObject
{

public:
    enum Direction{
        NONE = 360,
        RIGHT = 0,
        DOWN = 90,
        LEFT = 180,
        UP = 270
    };
    struct Cell
    {
        qint32 x;
        qint32 y;
        Cell(qint32 x = -1, qint32 y = -1){
            this->x = x;
            this->y = y;
        }
        bool operator==(Cell b){
            return (x==b.x)&&(y==b.y);
        }
        bool operator!=(Cell b){
            return !(*this==b);
        }
    };
    static Direction getOpposite(Direction dir);
    Square(qint8 x, qint8 y, QGraphicsObject *parent = 0);
    ~Square();
    Square::Cell getCell();
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPixmap pixmap;

};

#endif // SQUARE_H
