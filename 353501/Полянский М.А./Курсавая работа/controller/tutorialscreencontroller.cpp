#include "controller/tutorialscreencontroller.h"

#include "app/routes.h"

namespace controller {

TutorialScreenController::TutorialScreenController(const SP<model::GameModel>& model) : Controller(model) {
    _scene = new view::TutorialScene();

    connect(
        _scene,
        &view::TutorialScene::startGame,
        this,
        [=]() { emit navigateTo(app::Routes::GameScreen); });

    connect(
        _scene,
        &view::TutorialScene::returnToMenu,
        this,
        [=]() { emit navigateTo(app::Routes::InitialScreen); });
}

QGraphicsScene* TutorialScreenController::getScene() const {
    return _scene;
}

}  // namespace controller
