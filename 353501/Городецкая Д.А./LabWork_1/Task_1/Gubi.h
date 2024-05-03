#pragma once
#include "Ellipse.h"
#include "QPainter"
#include <QPushButton>
#include <qmainwindow.h>
#include <qwidget.h>

class Gubi : public Ellipse {
public:
  Gubi(QGraphicsObject *parent = nullptr);
  ~Gubi();
  void moveMouse();
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);

public slots:

  void onTime2();

private:
  bool buttonClicked = true;
  int pup = 5;
  int pstop2 = 0;
  bool stop2 = false;
  bool up = false;

  int y;
  QTimer *tim2;
};
