#ifndef VIEW_MAINWINDOWVIEW_H_
#define VIEW_MAINWINDOWVIEW_H_

#include <QGraphicsView>

namespace view {

class MainWindowView : public QGraphicsView {
   protected:
    void resizeEvent(QResizeEvent* event) override;

   public:
    MainWindowView();
};

}  // namespace view

#endif