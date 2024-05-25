#include "view/screens/initialScreen/initialscreenscene.h"

#include "view/hud/gametitle.h"
#include "view/hud/standardbutton.h"

namespace view {

InitialScreenScene::InitialScreenScene() {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
    createHUD();
}

void InitialScreenScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

void InitialScreenScene::createHUD() {
    GameTitle* title = new GameTitle();
    title->setPos(1920 / 2 - title->boundingRect().width() / 2, 200);
    addItem(title);

    StandardButton* startButton = new StandardButton("START", 400);
    StandardButton* uploadMapButton = new StandardButton("PLAY MAP", 400);
    StandardButton* setMapButton = new StandardButton("SET MAP", 400);
    StandardButton* tutorialButton = new StandardButton("TUTORIAL", 400);

    qreal size =
        startButton->boundingRect().width() + 10 +
        uploadMapButton->boundingRect().width() + 10 +
        setMapButton->boundingRect().width() + 10 +
        tutorialButton->boundingRect().width();

    startButton->setPos(
        1920 / 2 - size / 2,
        600);
    uploadMapButton->setPos(
        1920 / 2 - size / 2 + uploadMapButton->boundingRect().width() + 10,
        600);
    setMapButton->setPos(
        1920 / 2 + size / 2 - setMapButton->boundingRect().width() - setMapButton->boundingRect().width() - 10,
        600);
    tutorialButton->setPos(
        1920 / 2 + size / 2 - tutorialButton->boundingRect().width(),
        600);

    addItem(startButton);
    addItem(uploadMapButton);
    addItem(setMapButton);
    addItem(tutorialButton);

    connect(startButton, &StandardButton::pressed, this, &InitialScreenScene::startButtonPressed);
    connect(uploadMapButton, &StandardButton::pressed, this, &InitialScreenScene::uploadMapButtonPressed);
    connect(setMapButton, &StandardButton::pressed, this, &InitialScreenScene::setMapButtonPressed);
    connect(tutorialButton, &StandardButton::pressed, this, &InitialScreenScene::tutorialButtonPressed);
}

}  // namespace view
