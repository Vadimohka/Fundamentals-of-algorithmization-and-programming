#ifndef VIEW_MAINWINDOW_H_
#define VIEW_MAINWINDOW_H_

#include <QMainWindow>

#include "app/routes.h"
#include "app/shortcuts.h"
#include "controller/controller.h"
#include "model/gamemodel.h"
#include "view/mainwindowview.h"

using std::vector;

namespace view {

class MainWindow : public QMainWindow {
    Q_OBJECT

   private:
    SP<model::GameModel> _model;
    MainWindowView *view;
    controller::Controller *currentViewController;

    void closeEvent(QCloseEvent *event) override;

    void readSettings();
    void setTutorialShown() const;
    bool tutorialHasBeenShown() const;

   public:
    MainWindow(const SP<model::GameModel> &model);

   public slots:
    void setScreen(app::Routes route);
};

}  // namespace view

#endif
