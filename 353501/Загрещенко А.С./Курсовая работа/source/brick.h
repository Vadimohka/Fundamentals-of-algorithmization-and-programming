#ifndef BRICK_H
#define BRICK_H

#include <QLabel>



class Brick
{
public:
    Brick();
    Brick(const Brick &brick) { *this = brick; }
    Brick(const int val);

    int getVal(){ return currVal; }
    void update() { currVal *= MULTIPLIER; }
    bool getUpdated() { return upDated; }
    void setUpdated(const bool &upDated) { this->upDated = upDated; }

private:
    int currVal;
    bool upDated;

    static const int MULTIPLIER = 2;
};

#endif // BRICK_H
