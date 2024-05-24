#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "Deque.h"

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
  void redraw();

  int getEl();
  void setEl(int val);

  void createRing(bool inner);

protected:
  Ui::MainWindow *ui;
  Deque<int> q;
};