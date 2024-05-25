#ifndef CONTROLLER_SETMAPCONTROLLER_H_
#define CONTROLLER_SETMAPCONTROLLER_H_

#include <QGraphicsScene>

#include "app/shortcuts.h"
#include "controller/controller.h"
#include "view/screens/setMapScreen/setmapscene.h"

namespace controller {

class SetMapScreenController : public Controller {
    Q_OBJECT

   private:
    view::SetMapScene* _scene;

    vector<model::Position> createPath(const model::Position& start, const vector<view::SetMapCell*>* cells);

   public:
    SetMapScreenController(const SP<model::GameModel>& model);

    virtual QGraphicsScene* getScene() const override;

   public slots:
    void saveToFile(const vector<view::SetMapCell*>* cells);
};

}  // namespace controller

#endif
