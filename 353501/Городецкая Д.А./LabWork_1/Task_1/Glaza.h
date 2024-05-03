#pragma once
#include "Ellipse.h"
#include "QPainter"
#include <QPushButton>
#include <qmainwindow.h>
#include <qwidget.h>

class Glaza : public Ellipse {
public:
  Glaza(QGraphicsObject *parent = nullptr);
  ~Glaza();
  void moveEyes();
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);

  //   private slots:
  // void on_pushButton_clicked();

public slots:

  void onTime();

private:
  bool buttonClicked = true;
  int pright = 15;
  int pstop = 0;
  bool stop = false;
  bool right = false;

  int x;
  QTimer *tim;
};
