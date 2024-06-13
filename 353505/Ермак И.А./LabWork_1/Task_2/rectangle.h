#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "form.h"
#include <QPainter>
#include <QColor>

class Rectangle : public form
{
    Q_OBJECT
public:
    Rectangle(int x, int y, int w, int h, QColor bColor, QColor pColor);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    double perimetr();
    double square();
    void setScale(int widthScale, int heightScale);
public slots:
    void Scale();
protected:
    int height;
    int heightScal;
    int width;
    int widthScal;
};

#endif // RECTANGLE_H

