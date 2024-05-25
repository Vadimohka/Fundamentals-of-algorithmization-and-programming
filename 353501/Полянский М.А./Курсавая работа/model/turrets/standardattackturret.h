#ifndef MODEL_STANDARDATTACKTURRET_H_
#define MODEL_STANDARDATTACKTURRET_H_

#include "app/shortcuts.h"
#include "model/turrets/turret.h"
#include "model/turrets/turrettype.h"

using std::vector;

namespace model {

class StandardAttackTurret : public Turret {
   public:
    StandardAttackTurret(
        TurretType type,
        const Position& position,
        const SP<vector<SP<Enemy>>>& enemies);

    virtual ~StandardAttackTurret() = default;

    virtual bool attack() override;
};

}  // namespace model

#endif