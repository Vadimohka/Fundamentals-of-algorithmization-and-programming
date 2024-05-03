#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "Pair.h"
#include "../t4/Vector.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT 
    Pair< Vector<int>, Vector<Pair<int, double >>> matrix;
  
public:
  MainWindow();
  

private slots:
  void on_firstPushBtn_clicked();
  void on_firstInsertBtn_clicked();

  void on_secondPushBtn_clicked();
  void on_secondInsertBtn_clicked();

  void on_popBackBtn_clicked();

  void on_clearBtn_clicked();
  void on_eraseBtn_clicked();

  void updateTable(int tnum, int beg, int end);

protected:
  Ui::MainWindow *ui;
};