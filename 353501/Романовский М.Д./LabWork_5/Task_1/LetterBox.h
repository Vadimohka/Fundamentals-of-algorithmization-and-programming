#pragma once

#include "PixArt.h"
#include <QObject>
#include <qbrush.h>
#include <qtmetamacros.h>

class LetterBox: public PixArt {
  Q_OBJECT

public:
  LetterBox(QString letter, int pixSize, QGraphicsItem *parent = nullptr);
    
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
  bool setEntered(QString letter);

  QString getLetter();

private:
  QString letter;
  bool isArabic;
};