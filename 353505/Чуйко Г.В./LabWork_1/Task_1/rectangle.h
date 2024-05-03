#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QPainter>
#include <QGraphicsRectItem>

class Rectangle : public QGraphicsRectItem
{
public:
    explicit Rectangle(QGraphicsRectItem *parent = nullptr);
    virtual ~Rectangle();

   // virtual void draw(QPainter &painter) const;
    void dviz(int dy);

};

#endif // RECTANGLE_H
