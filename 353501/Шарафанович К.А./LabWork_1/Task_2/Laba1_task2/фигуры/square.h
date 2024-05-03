#ifndef SQUARE_H
#define SQUARE_H

#include <QtWidgets>
#include "figures.h"

class square : public figures
{
public:
    square();

    void setPoints(QMouseEvent *) override;

};

#endif // SQUARE_H
