#ifndef CART_H
#define CART_H

#include "rectangle.h"

class Cart : public Rectangle
{
    Q_OBJECT
public:
    Cart(QWidget* parent = nullptr);
    void moveCart();
    void moveBackCart();
protected:
    void paintEvent(QPaintEvent *) override;
private:
    int angle = 0;
};

#endif // CART_H
