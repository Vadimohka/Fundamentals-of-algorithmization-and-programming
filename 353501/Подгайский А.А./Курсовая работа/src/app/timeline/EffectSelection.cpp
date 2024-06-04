#include "EffectSelection.h"
#include "CoreInfo.h"
#include <QWidget>
#include <qcolor.h>
#include <qfont.h>
#include <qgraphicsitem.h>
#include <qnamespace.h>
#include <qpainter.h>

int EffectSelection::cur_hue = 0;

using namespace ae;

void EffectSelection::setSelected(bool sel) {
  if(sel){
    begText->show();
    endText->show();
    color.setAlpha(165);
  } else {
    begText->hide();
    endText->hide();
    color.setAlpha(50);
  }
  setBrush(color);
  update();
}

EffectSelection::~EffectSelection() {
  begText->deleteLater();
  endText->deleteLater();
}

EffectSelection::EffectSelection(qreal x, qreal y, qreal w, qreal h, int b,
                                 int e)
    : beg(b), end(e),
      QGraphicsRectItem(x,y,w,h), color(QColor::fromHsv(cur_hue, DEF_SATURATION, DEF_VALUE, 50)) {
  cur_hue = (cur_hue + HUE_STEP) % 256;

  begText = new QGraphicsTextItem(this);
  begText->setFont(QFont("Monospace", FONT_SIZE));
  begText->setPlainText(CoreInfo::getTimeString(beg));
  begText->setPos(0, 0);

  endText = new QGraphicsTextItem(this);
  endText->setFont(QFont("Monospace", FONT_SIZE));
  endText->setPlainText(CoreInfo::getTimeString(end));

  auto brect = endText->boundingRect();
  auto end_y =
      (rect().width() <= 2 * brect.width()) ? brect.height() : 0;
  endText->setPos(
      rect().width() - endText->boundingRect().width(), end_y);
}

// void EffectSelection::paint(QPainter *painter,
//                             const QStyleOptionGraphicsItem *option,
//                             QWidget *widget) {
//   // painter->fillRect(selectionRect->rect(), Qt::transparent);

//   // selectionRect->paint(painter, option, widget);

//   // if (selection) {
//   //   painter->translate(begText->pos());
//   //   begText->paint(painter, option, widget);
//   //   painter->translate(-begText->pos());

//   //   painter->translate(endText->pos());
//   //   endText->paint(painter, option, widget);
//   // }
// }

// QRectF EffectSelection::boundingRect() const {
//   return selectionRect->boundingRect();
// }