 #ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
class Rectangle: public QGraphicsRectItem,public QObject
{

public :
    Rectangle();
    Rectangle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
public slots:
    void move();
    void move_up();
};

#endif // RECTANGLE_H
