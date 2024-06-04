#include "energy.h"

Energy::Energy(QObject *parent)
    : QObject{parent}
{}

void Energy::upEnergy(int en){this->energy+=en;}

void Energy::upEnergy(Energy *en){this->energy+=en->setEnergy();}

void Energy::downEnergy(){this->energy--;}

int Energy::setEnergy(){return this->energy;}
