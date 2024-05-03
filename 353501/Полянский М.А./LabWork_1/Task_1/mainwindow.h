#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QTimer>
#include "truck.h"
#include "body.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
  
public:
  MainWindow();

protected slots:
  //void startClockwiseRotation();
  void rotateBody();
  void rotateDown();
  

private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;
  QGraphicsView *view;
  Truck *truck;
  Body *body;
  
  
  
};