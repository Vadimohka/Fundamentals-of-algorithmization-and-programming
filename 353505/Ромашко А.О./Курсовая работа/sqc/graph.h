#ifndef GRAPH_H
#define GRAPH_H
#include <QVector>
#include <QGraphicsScene>

#include "montecarlo.h"
#include "gamepoint.h"
#include "gamescene.h"
#include "ufloid.h"

class Graph: public QGraphicsScene
{
     Q_OBJECT
public:
    Graph(int LevelNum);
    int setlevelNum();
    enum levelsTypes{
        BossT,
        RestT,
        StartT,
        RandT,
        DefaultT,
        FreebieT
    };
    ~Graph();
    GameScene *setGameScene(){return this->gameScene;}
    void getGameScene(GameScene *GScene){this->gameScene = GScene;}
    void getPlayer(Player *p) {this->player=p;}
    Player *setPlayer(){return this->player;}
public slots:
    void takeClick(GamePoint *GP);
    void easyPath();

signals:
    void forOpenGameScene(GameScene *gamescene);
    void ClickChangeColor(Qt::GlobalColor);
private:
    void generateMatrix();
    int levelNum;
    QVector <GamePoint*> GamePointsVec;
    QVector <QVector<int>> matrix;
    GameScene *gameScene;
    QVector <int> coordinate;
    int sizeCoordinate;
    void addLineToScene();
    Player *player;
    void doActivSomePoints(GamePoint *GP);
    bool hasEmptyRows(QVector<QVector<int> > &matrix);
    GamePoint *lastGamePoint;
};

#endif // GRAPH_H
