#include "LetterBox.h"
#include "PixArt.h"
#include <qchar.h>
#include <qnamespace.h>
#include <qpainter.h>

const char *BOX_ART = "\
_gggggggggggggg_\
grrrrrrrrrrrrrrg\
grggrrrrrrrrggrg\
grgrrrrrrrrrrgrg\
grrrrrrrrrrrrrrg\
grrrrrrrrrrrrrrg\
grrrrrrrrrrrrrrg\
grrrrrrrrrrrrrrg\
grrrrrrrrrrrrrrg\
grrrrrrrrrrrrrrg\
grrrrrrrrrrrrrrg\
grrrrrrrrrrrrrrg\
grgrrrrrrrrrrgrg\
grggrrrrrrrrggrg\
grrrrrrrrrrrrrrg\
_gggggggggggggg_";

const QBrush def_color = Qt::darkGray;

LetterBox::LetterBox(QString letter, int pixSize, QGraphicsItem *parent)
    : PixArt(BOX_ART, pixSize, parent), letter(letter) {
  setEntered("");
  
  isArabic = false;
  if(letter.size() > 0)
    isArabic = letter[0].script() == QChar::Script_Arabic;
}

void LetterBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget) {
  PixArt::paint(painter, option, widget);
  painter->setPen(Qt::white);

  QFont font = painter->font();
  
  font.setPointSize(isArabic ? 15 : 20);
  font.setBold(true);
  painter->setFont(font);

  painter->drawText(boundingRect(), Qt::AlignCenter | Qt::AlignVCenter, letter);
}

bool LetterBox::setEntered(QString entered) {
  if (entered.isEmpty()) {
    updateColormap('r', def_color);
    return true;
  } else if (letter != entered) {
    updateColormap('r', Qt::darkRed);
    return false;
  } else {
    updateColormap('r', Qt::darkGreen);
    return true;
  }
}

QString LetterBox::getLetter() {
  return letter;
}