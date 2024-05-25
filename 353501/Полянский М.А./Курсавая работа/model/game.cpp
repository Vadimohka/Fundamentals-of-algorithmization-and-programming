#include "model/game.h"

#include "model/enemy.h"
#include "model/turrets/comboturret.h"
#include "model/turrets/granadeturret.h"
#include "model/turrets/slowtimeturret.h"
#include "model/turrets/splitturret.h"
#include "model/turrets/standardattackturret.h"

namespace model {

Game::Game(
    U_INT credits,
    float life,
    const vector<Position>& map,
    const vector<Position>& blockedCellsMap,
    const vector<Wave>& waves,
    Direction first)
    : _blockedCellsMap(blockedCellsMap),
      _waves(waves),
      _currentWave(_waves.end()),
      _currentState(State::Ready),
      _credits(credits),
      _life(life),
      _tick(0),
      _spawnCount(0) {
    setMap(map, first);

    _enemies = model::make_shared<vector<SP<Enemy>>>();

    _currentWave = _waves.begin();
}



SharedPtr<Turret> Game::addTurret(TurretType type, const Position& position) {
    if (_currentState == State::InExecution) {
        // Check if turret can be placed
        bool cellIsOccupied = false;

        for (auto i = _blockedCellsMap.cbegin(); i != _blockedCellsMap.cend() && !cellIsOccupied; ++i) {
            cellIsOccupied = (*i) == position;
        }

        for (auto i = _map.cbegin(); i != _map.cend() && !cellIsOccupied; ++i) {
            cellIsOccupied = i->getPosition() == position;
        }

        for (auto i = _turrets.cbegin(); i != _turrets.cend() && !cellIsOccupied; ++i) {
            cellIsOccupied = (*i)->getPosition() == position;
        }

        if (cellIsOccupied) {
            throw new turret_error("You can't insert a turret in this position");
        }

        // Check if enough credit
        if (_credits < turretTypes.at(type).cost) {
            throw new turret_error("You don't have enough credits to insert this turret");
        }

        // Otherwise create turret
        SharedPtr<Turret> temp;

        switch (type) {
            case TurretType::ComboTurret:
                temp.reset(new ComboTurret(position, _enemies));
                break;
            case TurretType::GranadeTurret:
                temp.reset(new GranadeTurret(position, _enemies));
                break;
            case TurretType::MitraTurret:
                temp.reset(new StandardAttackTurret(TurretType::MitraTurret, position, _enemies));
                break;
            case TurretType::SplitTurret:
                temp.reset(new SplitTurret(position, _enemies));
                break;
            case TurretType::SlowTimeTurret:
                temp.reset(new SlowTimeTurret(position, _enemies));
                break;
            case TurretType::WeakTurret:
            default:
                temp.reset(new StandardAttackTurret(TurretType::WeakTurret, position, _enemies));
                break;
        }

        _credits -= temp->getCost();

        _turrets.pushBack(temp);

        return temp;
    }

    return nullptr;
}

void Game::removeTurret(const Position& p) {
    for (auto i = _turrets.cbegin(); i != _turrets.cend(); ++i) {
        if ((*i)->getPosition() == p) {
            _credits += (*i)->getCost() / 2;
            _turrets.erase(*i);
            break;
        }
    }
}

U_INT Game::getCredits() const {
    return _credits;
}

float Game::getLife() const {
    return _life;
}

const vector<PathCell>& Game::getMap() const {
    return _map;
}

const vector<Position>& Game::getBlockedCellsMap() const {
    return _blockedCellsMap;
}

void Game::setMap(const vector<Position>& map, Direction first) {
    if (_currentState == State::Ready) {
        std::string error = validateMap(map);
        if (error != "")
            throw new path_error(error);

        _map.clear();

        PathCell prev;
        Direction from;

        for (auto i = map.cbegin(); i != map.cend(); ++i) {
            auto next = i + 1;

            if (i == map.cbegin()) {
                from = first;
            } else {
                switch (prev.to) {
                    case Direction::Up:
                        from = Direction::Down;
                        break;
                    case Direction::Down:
                        from = Direction::Up;
                        break;
                    case Direction::Left:
                        from = Direction::Right;
                        break;
                    default:
                        from = Direction::Left;
                        break;
                }
            }

            if (next != map.cend()) {
                if ((i->x == next->x - 1) && (i->y == next->y)) {
                    _map.push_back(PathCell{i->x, i->y, from, Direction::Right});
                } else if ((i->x == next->x) && (i->y == next->y + 1)) {
                    _map.push_back(PathCell{i->x, i->y, from, Direction::Up});
                } else if ((i->x == next->x + 1) && (i->y == next->y)) {
                    _map.push_back(PathCell{i->x, i->y, from, Direction::Left});
                } else if ((i->x == next->x) && (i->y == next->y - 1)) {
                    _map.push_back(PathCell{i->x, i->y, from, Direction::Down});
                }
                prev = _map.at(_map.size() - 1);
            } else {
                // Calculate last cell to
                Direction to;

                switch (from) {
                    case Direction::Left:
                        to = Direction::Right;
                        break;
                    case Direction::Up:
                        to = Direction::Down;
                        break;
                    case Direction::Right:
                        to = Direction::Left;
                        break;
                    case Direction::Down:
                        to = Direction::Up;
                        break;
                }
                _map.push_back(PathCell{i->x, i->y, from, to});
            }
        }  // namespace model
    } else {
        throw new state_error("You can't set the map if the game already started");
    }
}

void Game::moveEnemies() {
    int damage = 0;
    auto i = _enemies->begin();
    while (i != _enemies->end()) {
        damage = (*i)->move();
        if (damage > 0) {
            _life -= damage;
            i = _enemies->erase(i);
        } else {
            ++i;
        }
    }

    if (_life <= 0) _currentState = State::Lost;
}

void Game::spawnEnemy() {
    if (_currentWave != _waves.end()) {
        _spawnCount++;
        if (_currentWave->enemiesNumber > 0) {
            if (_spawnCount >= _currentWave->startsAfter && ((_spawnCount - _currentWave->startsAfter) % _currentWave->enemiesIntervalTick == 0 || (_spawnCount - _currentWave->startsAfter) == 0)) {
                _enemies->push_back(SP<Enemy>(new Enemy(_map, _currentWave->enemiesHealth, _currentWave->enemiesSpeed, _currentWave->enemiesAttackDamage, _currentWave->reward)));
                _currentWave->enemiesNumber--;

                _lastTickSpawnedEnemy = _enemies->back();
            } else {
                if (_lastTickSpawnedEnemy) {
                    _lastTickSpawnedEnemy.reset();
                }
            }
        } else {
            if (_enemies->size() == 0) {
                _currentWave++;
                _spawnCount = 0;
            }

            if (_lastTickSpawnedEnemy) {
                _lastTickSpawnedEnemy.reset();
            }
        }
    }
}

void Game::attack() {
    bool hasAttacked;

    _lastTickAttackingTurrets.clear();

    for (auto i = _turrets.begin(); i != _turrets.end(); ++i) {
        hasAttacked = (*i)->attack();

        if (hasAttacked) {
            _lastTickAttackingTurrets.push_back(*i);
        }
    }
}

void Game::checkDeadEnemies() {
    auto i = _enemies->begin();
    while (i != _enemies->end()) {
        if ((*i)->getHealth() <= 0) {
            _credits += (*i)->getReward();
            i = _enemies->erase(i);
        } else {
            ++i;
        }
    }
}

void Game::checkWon() {
    if (_enemies->size() == 0 && _currentWave == _waves.end()) {
        _currentState = State::Won;
    }
}

Game::State Game::tick() {
    if (_currentState == State::Ready) {
        _currentState = State::InExecution;
    }

    if (_currentState == State::InExecution) {
        _tick++;
        moveEnemies();
        spawnEnemy();
        ////reorderEnemies();
        attack();
        checkDeadEnemies();
        checkWon();
    }

    return _currentState;
}

SP<Enemy> Game::lastTickSpawnedEnemy() const {
    return _lastTickSpawnedEnemy;
}

vector<SharedPtr<Turret>> Game::lastTickAttackingTurrets() const {
    return _lastTickAttackingTurrets;
}

std::string Game::validateMap(const vector<Position>& map) {
    std::string err;

    if (map.size() > 0) {
        bool isUnique = true;

        for (auto i = map.cbegin(); i != map.cend() && isUnique; ++i) {
            for (auto j = map.cbegin(); j != map.cend() && isUnique; ++j) {
                if (i != j && *i == *j) {
                    isUnique = false;
                }
            }
        }

        if (isUnique) {
            for (auto i = map.cbegin(); i != map.cend(); ++i) {
                auto next = i + 1;

                if (next != map.cend()) {
                    if (!(((i->x == next->x - 1) && (i->y == next->y)) ||
                          ((i->x == next->x) && (i->y == next->y + 1)) ||
                          ((i->x == next->x + 1) && (i->y == next->y)) ||
                          ((i->x == next->x) && (i->y == next->y - 1)))) {
                        err = "This is not a correct path, some cells are disconnected";
                    }
                }
            }
        } else {
            err = "This is not a correct path, you can't go through the same cell twice";
        }
    } else {
        err = "This is not a correct path, there's no cell position in your path";
    }

    return err;
}

void Game::setBlocked(const vector<Position>& map) {
    _blockedCellsMap = map;
}

}  // namespace model
