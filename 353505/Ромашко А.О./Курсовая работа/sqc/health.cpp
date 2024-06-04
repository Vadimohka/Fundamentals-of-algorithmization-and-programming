 #include "health.h"

Health::Health(QObject *parent)
    : QObject{parent}
{ hp=0;}

void Health::takeDamage(int damage){hp-=damage;}

void Health::addHP(int HP){hp+=HP;}

int Health::setHP(){return this->hp;}
