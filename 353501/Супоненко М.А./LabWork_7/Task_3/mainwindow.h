#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "HashTableGui.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
    HashTableGui hashtable;
  
public:
  MainWindow();

private slots:
  void on_insertBtn_clicked();
  void on_removeBtn_clicked();
  void on_searchBtn_clicked();
  void on_randomBtn_clicked();
  void on_minKeyBtn_clicked();


  private:
  void refresh();


protected:
  Ui::MainWindow *ui;
};