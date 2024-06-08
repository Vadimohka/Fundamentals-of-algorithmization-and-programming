#include "formationa.h"
#include "gamescene.h"
#include "enemy.h"
#include "shootingenemy.h"
#include "beziercurvepath.h"
#include "straightlinepath.h"

FormationA::FormationA() {}

void FormationA::beginForm()
{

    for(int i = 0; i < 5; i++)
    {
        Enemy *basicEnemy = m_Scene->SpawnObject<Enemy>();
        basicEnemy->setPos((i - 2) * 100 + scene()->width() / 2, 100);
        BezierCurvePath *path = new BezierCurvePath(BezierCurvePath::curve1());
        basicEnemy->SetPath(path, false);
    }

    QPointF center = QPointF(scene()->width() / 2, scene()->height() / 2);

    const qreal offset = 100;
    const qreal yOffset = 100;

    for(int i = 0; i < 2; i++)
    {
        ShootingEnemy *leftShootingEnemy = m_Scene->SpawnObject<ShootingEnemy>();
        leftShootingEnemy->setPos(50, yOffset + i * 150);
        QPointF leftEndPos = QPointF(center.x() - offset, yOffset + i * 150);
        StraightLinePath *leftPath = new StraightLinePath(QPointF(50, yOffset + i * 150), leftEndPos, 1);
        leftShootingEnemy->SetPath(leftPath, false);

        ShootingEnemy *rightShootingEnemy = m_Scene->SpawnObject<ShootingEnemy>();
        rightShootingEnemy->setPos(scene()->width() - 50, yOffset + i * 150);
        QPointF rightEndPos = QPointF(center.x() + offset, yOffset + i * 150);
        StraightLinePath *rightPath = new StraightLinePath(QPointF(scene()->width() - 50, yOffset + i * 150), rightEndPos, 1);
        rightShootingEnemy->SetPath(rightPath, false);
    }

}
