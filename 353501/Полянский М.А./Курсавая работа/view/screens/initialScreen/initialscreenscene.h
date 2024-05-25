#ifndef VIEW_INITIALSCREENSCENE_H_
#define VIEW_INITIALSCREENSCENE_H_

#include <QGraphicsScene>

namespace view {

class InitialScreenScene : public QGraphicsScene {
    Q_OBJECT

   private:
    void drawBackground();
    void createHUD();

   public:
    InitialScreenScene();

   signals:
    void startButtonPressed();
    void setMapButtonPressed();
    void uploadMapButtonPressed();
    void tutorialButtonPressed();
};

}  // namespace view

#endif
