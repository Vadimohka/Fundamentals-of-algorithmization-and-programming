#ifndef GAMESCENEVIEW_H
#define GAMESCENEVIEW_H

#include <QGraphicsScene>

#include "player.h"
#include "enemy.h"

class GameSceneView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameSceneView(QObject *parent = nullptr);
    ~GameSceneView();
    Deck *setDeck(){return this->player->setDeck();}
    void getPlayer(Player *p);
    void GenerateEnemy(int num);
    Player *setPlayer(){return this->player;}
    Enemy *getEnemy(){return this->enemy;}

    enum TypesOfEnemy{
        BOSSET,
        DEFAULTET,
        HARDET,
        NOT
    };

    enum levelsTypes{
        BossT,
        RestT,
        StartT,
        RandT,
        DefaultT,
        FreebieT
    };

    void addPlayerAndEnemyToScene();

private:
    QPixmap *p = new QPixmap(":/new/prefix1/prefix1/DEFAULT.png");
    QPixmap *p1= new QPixmap(":/new/prefix1/prefix1/BOSSIMAGE.png");
    QPixmap *p3= new QPixmap(":/new/prefix1/prefix1/Koster.png");
    QPixmap *p4= new QPixmap(":/new/prefix1/prefix1/HARD.png");
    Player *player;
    Enemy *enemy;

public slots:
    void takeEnemyNum(int num);
    void updateSlot();
};

#endif // GAMESCENEVIEW_H
