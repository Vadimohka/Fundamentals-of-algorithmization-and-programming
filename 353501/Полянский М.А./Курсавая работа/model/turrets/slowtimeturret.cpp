#include "model/turrets/slowtimeturret.h"

#include "model/turrets/turrettype.h"

namespace model {

SlowTimeTurret::SlowTimeTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies)
    : Turret(TurretType::SlowTimeTurret, position, enemies) {}

bool SlowTimeTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    bool hasAttacked = false;
    if (enemies.size() != 0) {
        for (auto enemy : enemies) {
            // Slow down enemy for next tick
            enemy->changeSpeedNextTick(2);
            hasAttacked = true;
        }
    }

    return hasAttacked;
}

}  // namespace model
