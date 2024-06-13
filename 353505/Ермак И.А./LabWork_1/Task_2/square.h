#ifndef SQUARE_H
#define SQUARE_H

#include "form.h"
#include <QPainter>
#include <QColor>

class Square : public form
{
    Q_OBJECT
public:
    Square(int x, int y, int sideS, QColor bColor, QColor pColor);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    double perimetr();
    double square();
    void setScale(int sideScale);
public slots:
    void Scale();
protected:
    int side;
    int sideScal;
};

#endif // SQUARE_H

