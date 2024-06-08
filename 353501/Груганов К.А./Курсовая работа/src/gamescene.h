#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QtWidgets>
#include "formation.h"
#include "gameobj.h"
class GameScene : public QGraphicsScene
{
public:
    bool isPaused;
    bool isOver;

public:
    explicit GameScene(QObject *parent = nullptr);
    ~GameScene();

    template<class T>
    T* SpawnObject();

    template<class T>
    std::vector<T *> GetObjectsOfClass();

public:
    void Start(int level);
    void Update(float dt);
    void Destroy();

    std::vector <GameObj *> GetObjects() { return m_gameObjects; }

    void GameOver();

private:
    void drawBackground(QPainter *p, const QRectF &rect) override;

private:
    std::vector<GameObj *> m_gameObjects;
    float m_totalTime;
    std::vector<Formation *> m_formations;
    int m_lastForm;
    QPixmap background;

    float m_scrollSpeed = 1.0f;
    QGraphicsPixmapItem *background1;
    QGraphicsPixmapItem *background2;
};

template<class T>
T *GameScene::SpawnObject()
{
    T *tObj = new T();
    GameObj *obj = dynamic_cast<GameObj *>(tObj);
    if(obj)
    {
        m_gameObjects.push_back(obj);
    }
    else
    {
        return nullptr;
    }
    addItem(obj);
    obj->m_Scene = this;
    obj->isPendingKill = false;
    obj->Start();
    return tObj;
}

template<class T>
std::vector<T *> GameScene::GetObjectsOfClass()
{

    std::vector<T *> objs = std::vector<T *>();

    if(m_gameObjects.empty())
    {
        return objs;
    }

    for(size_t i = 0; i < m_gameObjects.size(); i++)
    {
        T *tObj = dynamic_cast<T*>(m_gameObjects[i]);
        if(tObj != nullptr)
        {
            objs.push_back(tObj);
        }
    }
    return objs;
}

#endif // GAMESCENE_H
