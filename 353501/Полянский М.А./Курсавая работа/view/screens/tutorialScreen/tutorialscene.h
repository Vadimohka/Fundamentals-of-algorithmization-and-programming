#ifndef VIEW_TUTORIALSCENE_H_
#define VIEW_TUTORIALSCENE_H_

#include <QGraphicsScene>

namespace view {

class TutorialScene : public QGraphicsScene {
    Q_OBJECT

   private:
    void drawBackground();

   public:
    TutorialScene();

   signals:
    void startGame();
    void returnToMenu();
};

}  // namespace view

#endif