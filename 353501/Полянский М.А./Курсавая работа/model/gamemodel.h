#ifndef MODEL_GAMEMODEL_H_
#define MODEL_GAMEMODEL_H_

#include <vector>

#include "app/shortcuts.h"
#include "model/enemy.h"
#include "model/game.h"
#include "model/pathcell.h"
#include "model/position.h"
#include "model/turrets/turret.h"
#include "model/turrets/turrettype.h"

using std::vector;

namespace model {

class GameModel {
   private:
    Game* _game;

   public:
    GameModel();

    Game::State tick();

    void reset(bool switchToStandardMap = false);

    SP<Turret> addTurret(TurretType type, const Position& p);
    void removeTurret(const Position& p);

    SP<Enemy> lastTickSpawnedEnemy() const;
    vector<SP<Turret>> lastTickAttackingTurrets() const;

    void setMap(const vector<Position>& map, Direction first);
    void setBlocked(const vector<Position>& map);

    U_INT getCredits() const;
    float getLife() const;
    const vector<PathCell>& getMap() const;
    const vector<Position>& getBlockedCellsMap() const;

    static std::string validateMap(const vector<Position>& map);
    U_INT GenerateRewards() const;
};

}  // namespace model

#endif
