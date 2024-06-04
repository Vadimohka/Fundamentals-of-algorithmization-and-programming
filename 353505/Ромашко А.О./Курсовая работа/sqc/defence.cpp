#include "defence.h"

Defence::Defence(QObject *parent)
    : QObject{parent}
{

}

void Defence::takeDamage(int damage){
    defence-=damage;
}

void Defence::addDef(int def){defence+=def;}

int Defence::setDef(){return this->defence;}
