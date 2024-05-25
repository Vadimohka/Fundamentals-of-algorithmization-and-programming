#include "model/enemy.h"

namespace model {

Enemy::Enemy(const vector<PathCell>& path, float health, U_INT speed, float attackDamage, U_INT reward)
    : _currentCell(0),
      _cellPosition(0),
      _health(health),
      _speed(speed),
      _attackDamage(attackDamage),
      _path(path),
      _reward(reward),
      _initialHealth(health),
      _speedFactor(1) {}

void Enemy::receiveAttack(float damage) {
    _health -= damage;
}

float Enemy::move() {
    float speed = static_cast<float>(_speed) * _speedFactor;
    // Restore speed
    _speedFactor = 1;

    _cellPosition += 100 / speed;

    if (_cellPosition >= 99) {
        _cellPosition = 0;
        _currentCell++;
    }

    // Check if last cell, then return the damage
    if (_currentCell == static_cast<int>(_path.size())) {
        _health = 0;  //! KAMIKAZE!
        return _attackDamage;
    }
    return 0;
}

void Enemy::changeSpeedNextTick(float speedFactor) {
    _speedFactor = speedFactor;
}

PathCell Enemy::getCurrentCell() const {
    return _path[_currentCell];
}

float Enemy::getCellPosition() const {
    return _cellPosition;
}

float Enemy::getHealth() const {
    return _health;
}

U_INT Enemy::getReward() const {
    return _reward;
}

float Enemy::getInitialHealth() const {
    return _initialHealth;
}

}  // namespace model
