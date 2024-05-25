#ifndef MODEL_SPLITTURRET_H_
#define MODEL_SPLITTURRET_H_

#include "app/shortcuts.h"
#include "model/turrets/standardattackturret.h"

using std::vector;

namespace model {

class SplitTurret : public StandardAttackTurret {
   private:
    SP<Enemy> _lastTargetedEnemy;

   public:
    SplitTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies);

    virtual ~SplitTurret() = default;

    virtual bool attack() override;
};

}  // namespace model

#endif