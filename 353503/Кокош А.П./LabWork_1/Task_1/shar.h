#ifndef SHAR_H
#define SHAR_H
#include "ellips.h"


class Shar : public Ellips
{
public:
    Shar();
    ~Shar();
    QGraphicsLineItem *shnur;
    QGraphicsEllipseItem *ellipse;

private:
    QRectF boundingRect() const override;
};

#endif // SHAR_H
