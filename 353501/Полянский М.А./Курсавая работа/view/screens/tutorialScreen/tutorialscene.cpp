#include "view/screens/tutorialScreen/tutorialscene.h"

#include "view/screens/tutorialScreen/tutorialcontent.h"

namespace view {

TutorialScene::TutorialScene() {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();

    TutorialContent* content = new TutorialContent(QSizeF(1920, 1080));
    addItem(content);

    connect(content, &TutorialContent::startPlayPressed, this, &TutorialScene::startGame);
    connect(content, &TutorialContent::returnToMenuPressed, this, &TutorialScene::returnToMenu);
}

void TutorialScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

}  // namespace view
