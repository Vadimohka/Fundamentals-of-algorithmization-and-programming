#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : public Item
{
public:
    Weapon();
    Weapon(int id, QString name, QString descrip, int damage, int type);
    ~Weapon() override = default;

    int getDam();
    void setDam(int);

    void copy(Weapon &other);
    int use() override;

private:
    int damage;
};

#endif // WEAPON_H
