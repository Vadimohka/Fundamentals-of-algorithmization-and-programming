#ifndef VIEW_PAUSEMODAL_H_
#define VIEW_PAUSEMODAL_H_

#include "view/hud/modal.h"

namespace view {

class PauseModal : public Modal {
    Q_OBJECT

   protected:
    virtual void paintContent(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   public:
    PauseModal(const QSize &size);

   signals:
    void returnToMenu();
};

}  // namespace view

#endif