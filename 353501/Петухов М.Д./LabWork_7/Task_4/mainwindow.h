#pragma once

#include <QMainWindow>
#include <QFile>
#include <QTreeWidgetItem>
#include <QStandardItem>
#include "hashTable.h"
#include <QRandomGenerator>
#include <QGraphicsView>
#include <QGraphicsRectItem>

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
  Ui::MainWindow *ui;
private:
  HashTable* table16;
  HashTable* table64;
  HashTable* table128;
  HashTable* table2048;
public slots:
  void display();
  void on_pushButton_2_clicked();
  void on_pushButton_clicked();
  void on_deleteButton_clicked();
  void on_insertButton_clicked();
};