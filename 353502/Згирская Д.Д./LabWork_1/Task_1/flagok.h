#ifndef FLAGOK_H
#define FLAGOK_H

#include "movingrectangle.h"

class Flagok : public MovingRectangle
{
    Q_OBJECT
public:
    explicit Flagok(QWidget *parent);

    void paintEvent(QPaintEvent *event) override;
};

#endif // FLAGOK_H
