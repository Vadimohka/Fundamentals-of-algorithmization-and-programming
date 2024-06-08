#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "deque.h"
#include <QTableWidget>
#include <QTableWidgetItem>

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

protected:
  Ui::MainWindow *ui;
  Deque<int> q;
};