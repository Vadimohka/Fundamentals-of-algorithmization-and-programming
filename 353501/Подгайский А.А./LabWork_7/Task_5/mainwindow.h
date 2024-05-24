#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "Queue.h"

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

  Deque<long> queue;


private slots:
  void on_pushBackBtn_clicked();
  void on_pushFrontBtn_clicked();
  void on_popBackBtn_clicked();
  void on_popFrontBtn_clicked();


  void refresh();

  void updateInfo();
  void updateList();


protected:
  Ui::MainWindow *ui;
};