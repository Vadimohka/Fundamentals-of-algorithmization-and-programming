#ifndef VIEW_ERRORMODAL_H_
#define VIEW_ERRORMODAL_H_

#include "view/hud/modal.h"

namespace view {

class ErrorModal : public Modal {
    Q_OBJECT

   private:
    const QString _text;

   protected:
    virtual void paintContent(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   public:
    ErrorModal(const QString &text,const QSize& size);

   signals:
    void returnToMenu();
};

}  // namespace view

#endif