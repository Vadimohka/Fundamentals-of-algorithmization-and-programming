#ifndef SAMOSVAL_H
#define SAMOSVAL_H
#include "rectangle.h"

class Samosval : public Rectangle
{
public:
   explicit Samosval(Rectangle *parent = nullptr);
   virtual void paintEvent(QPaintEvent *event);
   public slots:
};

#endif // SAMOSVAL_H
