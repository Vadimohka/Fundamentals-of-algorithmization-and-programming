#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QWidget>
#include <QGraphicsView>

#include "gamesceneview.h"
#include "deck.h"
#include "dialoglose.h"
#include "dialogwinmenu.h"

namespace Ui {
class GameScene;
}

class GameScene : public QWidget
{
    Q_OBJECT

public:
    explicit GameScene(QWidget *parent = nullptr);
    ~GameScene();
    int setDif(){return this->difficulty;}
    int setType(){return this->levelType;}
    void getDif(int a){this->difficulty = a;}
    void getType(int a){this->levelType = a;}
    void generateGraphicsView();
    //void getLevelNum(int l);
    void getPlayer(Player *p);
    GameSceneView *setGameSceneView(){return this->gameSceneView;}
    enum TypesOfEnemy{
        BOSSET,
        DEFAULTET,
        HARDET,
        NOT
    };
    enum typesOfCard{
        AttackT,
        DefenceT,
        HealtPointT,
        EnergyT,
        EffectT,
        CombinationT
    };
signals:
    void goBack();
    void toMoveEnemy();
    void playerDeckUpdate();
    void lose();
    void openWNMenu();
public slots:
    void openSlot();
    void loser();
    void WinSlot();

private slots:
    void on_pushButton_Back_clicked();
    void on_pushButton_Move_clicked();


private:
    int difficulty, levelType;
    Ui::GameScene *ui;
    int level;
    QGraphicsView *graphicsView;
    QGraphicsView *deck;
    GameSceneView *gameSceneView;
    Deck *deckP ;
    Player *player;
    DialogLOSE *dl;
    DialogWinMenu *wm;

    enum levelsTypes{
        BossT,
        RestT,
        StartT,
        RandT,
        DefaultT,
        FreebieT
    };
};

#endif // GAMESCENE_H
