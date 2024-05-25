#include "model/turrets/comboturret.h"

#include "model/turrets/turrettype.h"

namespace model {

ComboTurret::ComboTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies)
    : StandardAttackTurret(TurretType::ComboTurret, position, enemies), _attackMultiplier(1) {}

bool ComboTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        SP<Enemy> targetedEnemy = enemies[0];
        if (targetedEnemy != _lastTargetedEnemy) {
            _attackMultiplier = 1;
            _attackDamage = _stats.initialAttackDamage;
            _lastTargetedEnemy = targetedEnemy;
        } else if (_attackCooldownCounter == 0) {
            _attackDamage *= _attackMultiplier;
            _attackMultiplier += 0.1;
        }

        return StandardAttackTurret::attack();
    }

    return false;
}

}  
