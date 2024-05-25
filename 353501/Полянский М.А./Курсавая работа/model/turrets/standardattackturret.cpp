#include "model/turrets/standardattackturret.h"

namespace model {

StandardAttackTurret::StandardAttackTurret(
    TurretType type,
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies)
    : Turret(type, position, enemies) {}

bool StandardAttackTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        // There is at least one enemy to attack
        if (_attackCooldownCounter == 0) {
            for (auto enemy : enemies) {
                enemy->receiveAttack(_attackDamage);
            }
            // Reset cooldown
            _attackCooldownCounter = _attackCooldown;
            _hasAttackedLastTick = true;

            return true;
        } else {
            _attackCooldownCounter--;
            _hasAttackedLastTick = false;
        }
    }

    return false;
}

}  // namespace model
