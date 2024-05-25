#ifndef CONTROLLER_INITIALSCREENCONTROLLER_H_
#define CONTROLLER_INITIALSCREENCONTROLLER_H_

#include <QGraphicsScene>

#include "app/shortcuts.h"
#include "controller/controller.h"
#include "view/screens/initialScreen/initialscreenscene.h"

namespace controller {

class InitialScreenController : public Controller {
    Q_OBJECT

   private:
    view::InitialScreenScene* _scene;

   public:
    InitialScreenController(const SP<model::GameModel>& model);

    virtual QGraphicsScene* getScene() const override;

   public slots:
    void uploadFromFile();
};

}  // namespace controller

#endif