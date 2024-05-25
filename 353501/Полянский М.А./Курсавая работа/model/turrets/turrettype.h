#ifndef MODEL_TURRETTYPE_H_
#define MODEL_TURRETTYPE_H_

#include <unordered_map>

#include "app/shortcuts.h"

namespace model {

enum class TurretType {
    /**
     * WeakTurret
     * StandardAttackTurret
     * 
     * cost = 10
     * attackDamage = 10
     * attackCooldown = 20
     * attackRadius = 1
     * maxTargets = infinite
     */
    WeakTurret,
    /**
     * MitraTurret
     * StandardAttackTurret
     * 
     * cost = 25
     * attackDamage = 5
     * attackCooldown = 5
     * attackRadius = 2
     */
    MitraTurret,
    /**
     * Granade
     * 
     * cost = 40
     * attackDamage = 50 (- 10 for every enemy after the one attacked)
     * attackCooldown = 60
     * attackRadius = 3
     * maxTargets = 5
     */
    GranadeTurret,
    /**
     * ComboTurret
     * StandardAttackTurret
     * 
     * cost = 20
     * initialAttackDamage = 5
     * attackDamage = increment every attack (reset when changes targeted enemy)
     * attackCooldown = 15
     * attackRadius = 2
     */
    ComboTurret,
    /**
     * SplitTurret
     * StandardAttackTurret
     * 
     * cost = 30
     * initialAttackDamage = 30
     * attackDamage = inversely proportional to targeted enemies count (equally divided between enemies)
     * attackCooldown = 20
     * attackRadius = 1
     * maxTargets = infinite
     */
    SplitTurret,
    /**
     * SlowTime
     * 
     * cost = 50
     * attackDamage = 0
     * attackCooldown = 0
     * attackRadius = 2
     * maxTargets = infinite
     * 
     * Slow time enemies in target by 50%
     */
    SlowTimeTurret
};

struct TurretStats {
    U_INT cost;
    float initialAttackDamage;
    float initialAttackCooldown;
    U_INT attackRadius;
    // Ignored if SingularTargetTurret
    // Infinite if -1
    short int maxTargets;
};

const std::unordered_map<TurretType, TurretStats> turretTypes =
    {
        {TurretType::WeakTurret, TurretStats{10, 10, 20, 1, -1}},
        {TurretType::MitraTurret, TurretStats{25, 5, 5, 2, 1}},
        {TurretType::GranadeTurret, TurretStats{40, 50, 60, 3, 5}},
        {TurretType::ComboTurret, TurretStats{20, 5, 15, 2, 1}},
        {TurretType::SplitTurret, TurretStats{30, 30, 20, 2, -1}},
        {TurretType::SlowTimeTurret, TurretStats{50, 0, 0, 1, -1}},
};

}  // namespace model

#endif