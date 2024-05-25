#include "model/turrets/granadeturret.h"

#include "model/turrets/turrettype.h"

namespace model {

GranadeTurret::GranadeTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies)
    : Turret(TurretType::GranadeTurret, position, enemies) {}

bool GranadeTurret::attack() {
    vector<SP<Enemy>> enemies = getTargetedEnemies();

    if (enemies.size() != 0) {
        if (_attackCooldownCounter == 0) {
            for (auto enemy : enemies) {
                enemy->receiveAttack(_attackDamage);
                // Reduce damage for every enemy
                int seed[4];
                _attackDamage -= XorShiftPlus(seed);
            }
            // Reset cooldown
            _attackCooldownCounter = _attackCooldown;
            _hasAttackedLastTick = true;
            // Restore damage
            _attackDamage = _stats.initialAttackDamage;

            return true;
        } else {
            _attackCooldownCounter--;
            _hasAttackedLastTick = false;
        }
    }

    return false;
}

int GranadeTurret::XorShiftPlus(int state[]){
    state[0] = 123456789;
    state[1] = 362436069;
    state[2] = 521288629;
    state[3] = 88675123;

    int x = state[0];
    int y = state[1];
    int z = state[2];
    int w = state[3];

    int t = x^(x<<11);
    state[2] = y^(y>>z)^ z << (x^x);
    state[3] = w ^ (w>>19) ^ (t^(t>>8)) ^ state[2];
    return state[3];
}


}
