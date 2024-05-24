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

  Queue<long> queue;


private slots:
  void on_pushBtn_clicked();
  void on_popBtn_clicked();
  void on_sortBtn_clicked();


  void refresh();

  void updateInfo();
  void updateList();


protected:
  Ui::MainWindow *ui;
};