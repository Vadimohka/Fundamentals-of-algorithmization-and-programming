#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"

class Armor : public Item
{
public:
    Armor();
    Armor(int id, QString armorName, QString descrip, int def, int type);
    ~Armor() override = default;
    int getDef();
    void setDef(int);

    void copy(Armor &other);
    int use() override;

private:
    int defence = DEFAULT_ARM;
};

#endif // ARMOR_H
