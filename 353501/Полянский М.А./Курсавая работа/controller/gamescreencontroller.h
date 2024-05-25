#ifndef CONTROLLER_GAMECONTROLLER_H_
#define CONTROLLER_GAMECONTROLLER_H_

#include <QGraphicsScene>
#include <QTimer>

#include "app/shortcuts.h"
#include "controller/controller.h"
#include "model/position.h"
#include "model/turrets/turrettype.h"
#include "view/screens/gameScreen/gamescene.h"

namespace controller {

class GameScreenController : public Controller {
    Q_OBJECT

   private:
    view::GameScene* _scene;

    QTimer* gameTimer;
    QTimer* renderTimer;
    bool isRunning;
    bool isFastForward;

    void start();

   public:
    GameScreenController(const SP<model::GameModel>& model);

    virtual QGraphicsScene* getScene() const override;

   public slots:
    void returnToMenu();
    void restart();

    void gameTick();
    void viewTick();

    void playPause();
    void fastForward();

    void addTurret(const model::Position& position, model::TurretType turretType);
    void removeTurret(const model::Position& position);
};

}  

#endif