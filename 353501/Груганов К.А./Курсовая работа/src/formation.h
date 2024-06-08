#ifndef FORMATION_H
#define FORMATION_H

#include "gameobj.h"

class Formation : public GameObj
{

public:
    virtual void beginForm() = 0;

};

#endif // FORMATION_H
