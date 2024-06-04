#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "Vector.h"
#include "Pair.h"

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

protected:
  void updateFirstTable();
  int getFirstNew();
  int getFirstRow();


  void updateSecondTable();
  Pair<int, double> getSecondNew();
  int getSecondRow();

protected:
  Ui::MainWindow *ui;
  Vector<int> firstVec;
  Vector<Pair<int, double>> secondVec;
};