#ifndef MODEL_GRANADETURRET_H_
#define MODEL_GRANADETURRET_H_

#include "app/shortcuts.h"
#include "model/turrets/turret.h"

using std::vector;

namespace model {

class GranadeTurret : public Turret {
   public:
    GranadeTurret(const Position& position, const SP<vector<SP<Enemy>>>& enemies);

    virtual ~GranadeTurret() = default;

    virtual bool attack() override;
    virtual int XorShiftPlus(int seed[4]);
};
}  

#endif
