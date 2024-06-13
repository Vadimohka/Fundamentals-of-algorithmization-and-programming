#pragma once

#include <QMainWindow>
#include <QFile>
#include <QTreeWidgetItem>
#include <QStandardItem>
#include "myHash.h"

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
private:
  myHash* hashTable;
public slots:
  void on_generateRandom_clicked();
  void update();
  void on_insertButton_clicked();
  void on_deleteButton_clicked();
  void on_findMin_clicked();
  void on_getByKey_clicked();
protected:
  Ui::MainWindow *ui;
};