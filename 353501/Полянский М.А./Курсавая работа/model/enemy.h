#ifndef MODEL_ENEMY_H_
#define MODEL_ENEMY_H_

#include <vector>

#include "app/shortcuts.h"
#include "model/pathcell.h"
#include "model/position.h"

using std::vector;

namespace model {

class Enemy {
   private:
    U_INT _currentCell;
    float _cellPosition;
    float _health;
    U_INT _speed;
    float _attackDamage;
    vector<PathCell> _path;
    U_INT _reward;
    float _initialHealth;
    float _speedFactor;

   public:
    Enemy(const vector<PathCell>& path, float _health, U_INT _speed, float _attackDamage, U_INT reward);

    void receiveAttack(float damage);
    float move();
    void changeSpeedNextTick(float speedFactor);

    PathCell getCurrentCell() const;
    float getCellPosition() const;
    float getHealth() const;
    U_INT getReward() const;
    float getInitialHealth() const;
};

}  // namespace model

#endif