#ifndef GAMELEVELSSCENE_H
#define GAMELEVELSSCENE_H

#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QPen>
#include <QPainter>

#include "gamepoint.h"
#include "graph.h"
#include "montecarlo.h"
#include "gamescene.h"
#include "gamesceneview.h"
#include "dialogshop.h"
#include "dialogshowcards.h"


namespace Ui {
class GameLevelsScene;
}

class GameLevelsScene : public QWidget
{
    Q_OBJECT

public:
    explicit GameLevelsScene(QWidget *parent = nullptr);
    ~GameLevelsScene();
signals:
    void GameLevelSceneExitSignal();
    void openGameScene();
    void openShop();
    void openShowCards();
public slots:
    void openSlot();
    void getInfoGameScene(GameScene *gameS);
    void openMainMenu();

private slots:
    void on_pushButton_Back_clicked();

    void on_pushButton_ShowCards_clicked();

    void on_pushButton_Shop_clicked();

private:
    Ui::GameLevelsScene *ui;
    QGraphicsView *graphicsView;
    Graph *scene;
    GameScene *gameScene;
    Player *player;
    int activeGamePoint;
    DialogShop *d;
    DialogShowCards *DSV;
    bool flag=0;
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // GAMELEVELSSCENE_H
