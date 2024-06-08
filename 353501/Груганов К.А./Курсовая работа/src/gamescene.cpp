#include "gamescene.h"
#include "enemy.h"
#include "formationa.h"
#include "formationb.h"
#include "formationc.h"
#include "formationd.h"
#include "meteorflow.h"
#include "player.h"

GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}
{
    m_gameObjects = std::vector<GameObj *>();
    m_formations = std::vector<Formation *>();

    background.load(":/img/фон.jpg");
    background1 = new QGraphicsPixmapItem(background);
    background2 = new QGraphicsPixmapItem(background);
    background2->setPos(0, -background.height());
    addItem(background1);
    addItem(background2);
}

GameScene::~GameScene()
{
    Destroy();
}

void GameScene::Start(int level)
{
    isPaused = false;
    isOver = false;



    Player *player = SpawnObject<Player>();

    player->setPos(width() / 2 - player->pixmap().width() / 2,
                   height() - player->pixmap().height() - 20);


    FormationA *formA = SpawnObject<FormationA>();
    MeteorFlow *flow = SpawnObject<MeteorFlow>();
    FormationB *formB = SpawnObject<FormationB>();
    FormationC *formC = SpawnObject<FormationC>();
    FormationD *formD = SpawnObject<FormationD>();

    m_formations.push_back(formA);
    m_formations.push_back(flow);
    m_formations.push_back(formB);
    m_formations.push_back(formC);
    m_formations.push_back(flow);
    m_formations.push_back(formD);

    m_lastForm = level - 1;
}

void GameScene::Destroy()
{
    isPaused = false;
    isOver = false;

   for(size_t i = 0; i < m_gameObjects.size(); i++)
    {
        if(m_gameObjects[i])
        {
            m_gameObjects[i]->OnDestroy();
            delete m_gameObjects[i];
            m_gameObjects[i] = nullptr;
        }
    }
    m_lastForm = 0;
    m_totalTime = 0;
    m_gameObjects.clear();
    m_formations.clear();
}

void GameScene::Update(float dt)
{
    if(isPaused) return;
    m_totalTime += dt;

    background1->setPos(background1->pos().x(), background1->pos().y() + m_scrollSpeed);
    background2->setPos(background2->pos().x(), background2->pos().y() + m_scrollSpeed);

    if (background1->pos().y() >= height()) {
        background1->setPos(0, background2->pos().y() - background.height());
    }
    if (background2->pos().y() >= height()) {
        background2->setPos(0, background1->pos().y() - background.height());
    }

    m_gameObjects.erase(std::remove_if(m_gameObjects.begin(),
                                       m_gameObjects.end(),
                                       [](auto &obj) { return obj == nullptr; }),
                        m_gameObjects.end());

    std::vector<GameObj *> tmp = m_gameObjects;

    for(size_t i = 0; i < tmp.size(); i++)
    {
        auto &obj = tmp[i];
        /*if(obj)
        {*/
        if (obj->isPendingKill) {
            obj->OnDestroy();
            removeItem(obj);
            delete obj;
            m_gameObjects[i] = nullptr;
            continue;
            }
            obj->PreUpdate();
            obj->Update(dt);
            obj->PostUpdate();
            // }
    }

    if(GetObjectsOfClass<Enemy>().size() == 0)
    {
        m_lastForm = (m_lastForm + 1) % m_formations.size();
        m_formations[m_lastForm]->beginForm();
    }
}

void GameScene::GameOver()
{
    isOver = true;
}

void GameScene::drawBackground(QPainter *p, const QRectF &rect)
{
    QGraphicsScene::drawBackground(p, rect);

    this->setBackgroundBrush(Qt::black);
}
