#ifndef BALLON_H
#define BALLON_H

#include "ellipse.h"
#include "widget.h"
class Ballon : public Ellipse
{
public:

    explicit Ballon(Ellipse *parent = nullptr);


    virtual void paintEvent(QPaintEvent *event);
public slots:
    void boom();

};



#endif // BALLON_H
