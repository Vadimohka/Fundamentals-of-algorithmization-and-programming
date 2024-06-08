#include "formationc.h"
#include "beziercurvepath.h"
#include "enemyspiral.h"
#include "shootingenemy.h"
#include "straightlinepath.h"
#include "gamescene.h"

FormationC::FormationC() {}


void FormationC::beginForm()
{
    QPointF center(scene()->width() / 2, scene()->height() / 7);

    const int numRows = 3;
    const int numEnemiesPerRow = 2;
    const qreal rowSpacing = 90;
    const qreal colSpacing = 100;

    EnemySpiral *sp = m_Scene->SpawnObject<EnemySpiral>();
    sp->setPos(scene()->width()/2, -120);
    sp->SetPath(new StraightLinePath(QPointF(0, 0), QPointF(0, 150), 1), false);

    for(int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numEnemiesPerRow; col++)
        {
            qreal xPos = scene()->width() / 3 +  (col - (numEnemiesPerRow / 2)) * colSpacing;
            qreal yPos = row * rowSpacing - 150;

            Enemy *enemy;
            if (row % 2 == 0)
            {
                enemy = m_Scene->SpawnObject<ShootingEnemy>();
            }
            else
            {
                enemy = m_Scene->SpawnObject<Enemy>();
            }

            enemy->setPos(xPos, yPos);
            BezierCurvePath *path = new BezierCurvePath(BezierCurvePath::curve1Mir());
            enemy->SetPath(path, false);
        }
    }

    for(int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numEnemiesPerRow; col++)
        {
            qreal xPos = scene()->width() - scene()->width() / 3 - (col - (numEnemiesPerRow / 2)) * colSpacing;
            qreal yPos = row * rowSpacing - 150;

            Enemy *enemy;
            if (row % 2 == 0)
            {
                enemy = m_Scene->SpawnObject<ShootingEnemy>();
            }
            else
            {
                enemy = m_Scene->SpawnObject<Enemy>();
            }

            enemy->setPos(xPos, yPos);
            BezierCurvePath *path = new BezierCurvePath(BezierCurvePath::curve1Mir());
            enemy->SetPath(path, false);
        }
    }
}
