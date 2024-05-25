#ifndef MODEL_WAVE_H_
#define MODEL_WAVE_H_

#include "app/shortcuts.h"

namespace model {

struct Wave {
    float enemiesHealth;
    U_INT enemiesSpeed;
    float enemiesAttackDamage;
    U_INT enemiesNumber;
    U_INT enemiesIntervalTick;
    U_INT startsAfter;
    U_INT reward;
};

}  // namespace model

#endif
