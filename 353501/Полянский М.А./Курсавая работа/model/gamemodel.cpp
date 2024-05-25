#include "model/gamemodel.h"

namespace model {

GameModel::GameModel() : _game(nullptr) {
    reset();
}

Game::State GameModel::tick() {
    return _game->tick();
}

void GameModel::reset(bool switchToStandardMap) {
    U_INT credits = 20;
    float life = 100;

    vector<Position> map;
    vector<Position> blockedCellsMap;

    if (_game && !switchToStandardMap) {
        // Get current game map

        // TODO: not necessary when level selection is included
        for (auto cell : _game->getMap()) {
            map.push_back(cell.getPosition());
        }

        blockedCellsMap = _game->getBlockedCellsMap();
    } else {
        map.push_back(Position{0, 0});
        map.push_back(Position{1, 0});
        map.push_back(Position{1, 1});
        map.push_back(Position{1, 2});

        for (U_INT i = 2; i < 7; i++) {
            map.push_back(Position{2, i});
        }

        map.push_back(Position{3, 6});
        map.push_back(Position{4, 6});
        map.push_back(Position{4, 5});
        map.push_back(Position{4, 4});
        map.push_back(Position{5, 4});
        map.push_back(Position{5, 3});
        map.push_back(Position{5, 2});
        map.push_back(Position{6, 2});

        for (U_INT i = 2; i < 8; i++) {
            map.push_back(Position{7, i});
        }

        for (U_INT i = 8; i < 15; i++) {
            map.push_back(Position{i, 7});
        }

        map.push_back(Position{14, 6});
        map.push_back(Position{14, 5});
        map.push_back(Position{14, 4});
        map.push_back(Position{13, 4});
        map.push_back(Position{12, 4});
        map.push_back(Position{11, 4});
        map.push_back(Position{11, 3});
        map.push_back(Position{11, 2});

        for (U_INT i = 11; i < 16; i++) {
            map.push_back(Position{i, 1});
        }

        for (U_INT i = 3; i < 11; i++) {
            blockedCellsMap.push_back(Position{i, 0});
        }

        for (U_INT i = 5; i < 9; i++) {
            blockedCellsMap.push_back(Position{0, i});
        }

        for (U_INT i = 3; i < 7; i++) {
            blockedCellsMap.push_back(Position{9, i});
        }

        for (U_INT i = 12; i < 16; i++) {
            blockedCellsMap.push_back(Position{i, 8});
        }

        blockedCellsMap.push_back(Position{0, 1});
        blockedCellsMap.push_back(Position{1, 3});
        blockedCellsMap.push_back(Position{1, 8});
        blockedCellsMap.push_back(Position{2, 8});
        blockedCellsMap.push_back(Position{3, 4});
        blockedCellsMap.push_back(Position{3, 7});
        blockedCellsMap.push_back(Position{4, 2});
        blockedCellsMap.push_back(Position{6, 1});
        blockedCellsMap.push_back(Position{6, 7});
        blockedCellsMap.push_back(Position{6, 3});
        blockedCellsMap.push_back(Position{7, 1});
        blockedCellsMap.push_back(Position{8, 2});
        blockedCellsMap.push_back(Position{8, 3});
        blockedCellsMap.push_back(Position{10, 6});
        blockedCellsMap.push_back(Position{12, 2});
        blockedCellsMap.push_back(Position{12, 5});
        blockedCellsMap.push_back(Position{14, 3});
        blockedCellsMap.push_back(Position{15, 0});
        blockedCellsMap.push_back(Position{15, 2});
        blockedCellsMap.push_back(Position{15, 3});
        blockedCellsMap.push_back(Position{15, 7});
    }

    vector<Wave> wave;

    wave.push_back(Wave{100, 25, 10, 5, 60, 200, GenerateRewards()});
    wave.push_back(Wave{70, 12, 15, 3, 20, 0, GenerateRewards()});
    wave.push_back(Wave{200, 25, 10, 15, 30, 30, GenerateRewards()});
    wave.push_back(Wave{750, 40, 25, 2, 30, 60, GenerateRewards()});

    if (_game) {
        delete _game;
    }

    _game = new Game(credits, life, map, blockedCellsMap, wave, Direction::Left);
}

U_INT GameModel::GenerateRewards() const {
    U_INT seed = 2049;
    U_INT state[4] = {seed, seed, seed, seed};
    state[0] = state[3] ^ state[0] | state[1] >>5;
    state[2] = state[0] << state[4] & 73;
    U_INT u = state[0];
    U_INT v = state[1];
    U_INT n = state[2];
    U_INT r = state[3];
    U_INT t = u | (u>>11)|(u&n);
    state[2] = v^(v>>n)^n<<(u^r);
    state[3] = r | (r<<17) ^ (t&(t<<13))^ state[2];
    return (state[3]%20) + 5;
}
SP<Turret> GameModel::addTurret(TurretType type, const Position& p) {
    return _game->addTurret(type, p);
}

void GameModel::removeTurret(const Position& p) {
    return _game->removeTurret(p);
}

SP<Enemy> GameModel::lastTickSpawnedEnemy() const {
    return _game->lastTickSpawnedEnemy();
}

vector<SP<Turret>> GameModel::lastTickAttackingTurrets() const {
    return _game->lastTickAttackingTurrets();
}

U_INT GameModel::getCredits() const {
    return _game->getCredits();
}

float GameModel::getLife() const {
    return _game->getLife();
}

const vector<PathCell>& GameModel::getMap() const {
    return _game->getMap();
}

const vector<Position>& GameModel::getBlockedCellsMap() const {
    return _game->getBlockedCellsMap();
}

std::string GameModel::validateMap(const vector<Position>& map) {
    return Game::validateMap(map);
}

void GameModel::setMap(const vector<Position>& map, Direction first) {
    _game->setMap(map, first);
}

void GameModel::setBlocked(const vector<Position>& map) {
    _game->setBlocked(map);
}

}  // namespace model
