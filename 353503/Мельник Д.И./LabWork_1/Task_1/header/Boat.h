//
// Created by dmitry on 10.2.24.
//

#ifndef FIRST_BOAT_H
#define FIRST_BOAT_H

#include <Flag.h>


class Boat :
        public Flag
{
public:
    Boat(QWidget *parent = nullptr);
    ~Boat();
protected:
    void paintEvent(QPaintEvent *e) override;
};


#endif //FIRST_BOAT_H
