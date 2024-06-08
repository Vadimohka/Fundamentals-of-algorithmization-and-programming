#include "formationd.h"
#include "rotatingenemy.h"
#include "gamescene.h"

FormationD::FormationD() {}


void FormationD::beginForm()
{
    RotatingEnemy *en = m_Scene->SpawnObject<RotatingEnemy>();
    en->setPos(scene()->width()/2, 0);
}
