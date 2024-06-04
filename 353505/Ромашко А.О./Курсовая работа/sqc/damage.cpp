#include "damage.h"

Damage::Damage(QObject *parent)
    : QObject{parent}
{}

void Damage::upDamage(int d){damag+=d;}

void Damage::downDamage(int d){damag-=d;}

int Damage::damage(){return this->damag;}
