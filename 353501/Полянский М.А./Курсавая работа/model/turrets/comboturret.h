#ifndef MODEL_COMBOTURRET_H_
#define MODEL_COMBOTURRET_H_

#include "app/shortcuts.h"
#include "model/turrets/standardattackturret.h"

using std::vector;

namespace model {

class ComboTurret : public StandardAttackTurret {
   private:
    float _attackMultiplier;
    SP<Enemy> _lastTargetedEnemy;

   public:
    ComboTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies);

    virtual ~ComboTurret() = default;

    virtual bool attack() override;
};

}  // namespace model

#endif