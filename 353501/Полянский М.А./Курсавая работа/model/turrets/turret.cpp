#include "model/turrets/turret.h"

namespace model {

Turret::Turret(
    TurretType type,
    const Position& position,
    const SP<vector<SP<Enemy>>>& enemies)
    : _position(position),
      _enemies(enemies),
      _stats(turretTypes.at(type)),
      _attackDamage(_stats.initialAttackDamage),
      _attackCooldown(_stats.initialAttackCooldown),
      _attackCooldownCounter(_stats.initialAttackCooldown),
      _hasAttackedLastTick(false) {}

vector<SP<Enemy>> Turret::getEnemiesInRadius() const {
    vector<SP<Enemy>> enemies = vector<SP<Enemy>>();

    for (auto enemy : *_enemies) {
        Position enemyPosition = enemy->getCurrentCell().getPosition();
        if (enemyPosition.x >= _position.x - _stats.attackRadius &&
            enemyPosition.x <= _position.x + _stats.attackRadius &&
            enemyPosition.y >= _position.y - _stats.attackRadius &&
            enemyPosition.y <= _position.y + _stats.attackRadius) {
            enemies.push_back(enemy);
        }
    }

    return enemies;
}

vector<SP<Enemy>> Turret::getTargetedEnemies() const {
    vector<SP<Enemy>> enemiesInRadius = getEnemiesInRadius();
    vector<SP<Enemy>> targetedEnemies = vector<SP<Enemy>>();

    U_INT targetsAmount;

    if (_stats.maxTargets == -1) {
        targetsAmount = enemiesInRadius.size();
    } else {
        targetsAmount = _stats.maxTargets;
    }

    for (U_INT i = 0; i < targetsAmount && i < enemiesInRadius.size(); i++) {
        targetedEnemies.push_back(enemiesInRadius[i]);
    }

    return targetedEnemies;
}

Position Turret::getPosition() const {
    return _position;
}

U_INT Turret::getCost() const {
    return _stats.cost;
}

bool Turret::hasAttackedLastTick() const {
    return _hasAttackedLastTick;
}

}  // namespace model
