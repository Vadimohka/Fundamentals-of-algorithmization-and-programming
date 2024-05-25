#ifndef VIEW_TUTORIALCONTENT_H_
#define VIEW_TUTORIALCONTENT_H_

#include <QGraphicsItem>
#include <QPainter>

#include "app/shortcuts.h"
#include "view/hud/standardbutton.h"

namespace view {

class TutorialContent : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   private:
    QSizeF _size;
    U_INT currentStep;

    StandardButton *nextStepButton;

    void paintTitle(QPainter *painter, const QString &title);
    void paintTurretInfo(
        QPainter *painter,
        const QString &image,
        const QString &name,
        const QString &description,
        const QString &stats);

   public:
    TutorialContent(const QSizeF &size);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   public slots:
    void nextStep();

   signals:
    void startPlayPressed();
    void returnToMenuPressed();
};

}  // namespace view

#endif
