#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "Rect.h"
#include "details.h"

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
  ~MainWindow(); // это деструктор. штука, которая вызывается, когда класс удаляется 

protected:
  Ui::MainWindow *ui;
  Rect *rect;
  details *det; 
  QGraphicsScene *scene;
};