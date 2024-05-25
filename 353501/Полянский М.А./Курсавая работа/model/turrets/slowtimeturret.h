#ifndef MODEL_SLOWTIMETURRET_H_
#define MODEL_SLOWTIMETURRET_H_

#include "app/shortcuts.h"
#include "model/turrets/turret.h"

using std::vector;

namespace model {

class SlowTimeTurret : public Turret {
   public:
    SlowTimeTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies);

    virtual ~SlowTimeTurret() = default;

    virtual bool attack() override;
};
}  // namespace model

#endif