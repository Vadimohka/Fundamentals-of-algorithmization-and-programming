#ifndef TRINKET_H
#define TRINKET_H

#include "item.h"

class Trinket : public Item
{
public:
    Trinket();
    ~Trinket() override = default;
};

#endif // TRINKET_H
