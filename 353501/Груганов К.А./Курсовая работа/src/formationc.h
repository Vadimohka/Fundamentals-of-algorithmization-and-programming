#ifndef FORMATIONC_H
#define FORMATIONC_H

#include "formation.h"

class FormationC : public Formation
{
public:
    FormationC();

    void beginForm() override;
};

#endif // FORMATIONC_H
