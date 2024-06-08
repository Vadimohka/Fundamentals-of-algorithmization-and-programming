#ifndef FORMATIOND_H
#define FORMATIOND_H

#include "formation.h"

class FormationD : public Formation
{
public:
    FormationD();

public:
    void beginForm() override;
};

#endif // FORMATIOND_H
