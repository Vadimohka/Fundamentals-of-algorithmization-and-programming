#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion : public Item
{
public:
    Potion();
    Potion(int id, QString name, QString descrip, int heal, int type);
    ~Potion() override = default;

    int getHeal();
    void setHeal(int);

    int use() override;
    void copy(Potion &other);

private:
    int heal;
};

#endif // POTION_H
