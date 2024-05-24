#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPainter>
#include <QColor>
#include <QGraphicsObject>

class Rectangle : public QGraphicsObject
{
    Q_OBJECT
public slots:
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
public:
    Rectangle(int x, int y, int w, int h, QColor bColor, QColor pColor);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    int GetPosX();
    int GetPosY();

protected:
    int positionX;
    int positionY;
    QColor PenColor;
    QColor BrushColor;
    int height;
    int heightScal;
    int width;
    int widthScal;
};


#endif // RECTANGLE_H
