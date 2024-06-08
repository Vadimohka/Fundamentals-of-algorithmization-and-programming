#include "formationb.h"
#include "enemy.h"
#include "straightlinepath.h"
#include "shootingenemy.h"
#include "divingenemy.h"
#include "gamescene.h"

FormationB::FormationB() {}


void FormationB::beginForm()
{
    QPointF center(scene()->width() / 2, scene()->height() / 5);

    const int numEnemies = 8;

    const qreal spreadFactor = 50;

    for(int i = 0; i < numEnemies; i++)
    {
        qreal xPos;
        if(i % 2 == 0)
        {
            xPos = -150;
        }
        else
        {
            xPos = scene()->width() + 150;
        }
        qreal yPos = center.y();

        Enemy *enemy;
        if((i / 2)%3 == 1)
        {
            enemy = m_Scene->SpawnObject<DivingEnemy>();
        }
        else
        {
            enemy = m_Scene->SpawnObject<ShootingEnemy>();
        }

        int x = i % 2 == 0 ?  -1 : 1;
        QPointF targetPos = center + QPointF(i * spreadFactor * x, (i - i%2) * spreadFactor);


        enemy->setPos(xPos, yPos);
        StraightLinePath *path = new StraightLinePath(enemy->pos(), targetPos, 1);
        enemy->SetPath(path, false);
    }
}
