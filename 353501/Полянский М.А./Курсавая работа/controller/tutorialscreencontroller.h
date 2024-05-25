#ifndef CONTROLLER_TUTORIALSCREENCONTROLLER_H_
#define CONTROLLER_TUTORIALSCREENCONTROLLER_H_

#include <QGraphicsScene>

#include "app/shortcuts.h"
#include "controller/controller.h"
#include "model/gamemodel.h"
#include "view/screens/tutorialScreen/tutorialscene.h"

namespace controller {

class TutorialScreenController : public Controller {
    Q_OBJECT

   private:
    view::TutorialScene* _scene;

   public:
    TutorialScreenController(const SP<model::GameModel>& model);

    virtual QGraphicsScene* getScene() const override;
};

}  // namespace controller

#endif