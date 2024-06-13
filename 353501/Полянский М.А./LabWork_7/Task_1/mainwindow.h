#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "Dqueue.h"
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
  int getElements();
  void setElements(int);
  void redraw();
  

protected:
  Deque<int> q;
  Ui::MainWindow *ui;
};