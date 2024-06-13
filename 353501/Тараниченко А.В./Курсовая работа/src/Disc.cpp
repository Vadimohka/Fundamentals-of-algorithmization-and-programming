#include "Disc.hpp"

void Disc::setEnd(QPointF end){
    end_ = end;
    animationHaveFinish_ = false;
}


void Disc::moveDisc()
{
    if(y()<end_.ry()){
        this->setPos(x(), y() + 10);
    }
    else if(!animationHaveFinish_){
        animationHaveFinish_ = true;
        emit animationHaveFinish();
    }
}
