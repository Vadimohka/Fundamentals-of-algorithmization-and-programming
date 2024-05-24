#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "Pair.h"
#include "CustomVector.h"

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

private slots:

  void updateFirst();
  int getFirVal();
  int getFirRow();
  

  void updateSecond();
  Pair<int, double> getSecVal();
  int getSecRow();

protected:
  Ui::MainWindow *ui;
  MyVector<int> firstVector;
  MyVector<Pair<int, double>> secondVector;


};