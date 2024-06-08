#include "meteorflow.h"
#include "gamescene.h"
#include "item.h"
#include "meteor.h"
MeteorFlow::MeteorFlow()
{
    m_started = false;
    m_buffSpawned = false;
}


void MeteorFlow::beginForm()
{
    m_started = true;
    m_buffSpawned = false;
    m_totalTime = 0;
    m_nextSpawnTime = 0;
}

void MeteorFlow::Update(float dt)
{
    if(!m_started) return;

    m_totalTime += dt;
    if (m_totalTime >= duration) {
        m_started = false;
        return;
    }

    int x1 = QRandomGenerator::global()->bounded(60, scene()->width() - 60);
    int x2 = QRandomGenerator::global()->bounded(30, scene()->width() - 30);

    if (!m_buffSpawned && QRandomGenerator::global()->bounded(0, 100) < 50) {
        m_buffSpawned = true;
        Item *double_shoot = m_Scene->SpawnObject<Item>();
        double_shoot->Setup(QPixmap(":/img/energy_blast-11.png"), Item::DOUBLE_SHOT, 0);
        double_shoot->setPos(x2, -50);
    }
    if (m_totalTime >= m_nextSpawnTime) {
        Meteor *en = m_Scene->SpawnObject<Meteor>();
        en->setPos(x1, -100);
        m_nextSpawnTime = m_totalTime + (float) QRandomGenerator::global()->bounded(2, 16) / 10;
    }
}
