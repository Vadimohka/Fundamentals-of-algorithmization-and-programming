#ifndef VIEW_ERRORMODAL_H_
#define VIEW_ERRORMODAL_H_

#include "model/game.h"
#include "view/hud/modal.h"

namespace view {

class LostWonModal : public Modal {
    Q_OBJECT

   private:
    const model::Game::State _lostWon;

   protected:
    virtual void paintContent(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   public:
    LostWonModal(model::Game::State lostWon, const QSize &size);

   signals:
    void returnToMenu();
    void restart();
};

}  // namespace view

#endif