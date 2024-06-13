#pragma once

#include <QMainWindow>
#include <QFile>
#include <QTreeWidgetItem>
#include <QStandardItem>
#include "BST.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
  void displayTree(QStandardItem* parentItem, BinarySearchTree<QString>::Node* node);

private:
  QStandardItemModel* model;
  BinarySearchTree<QString> tree;
public:
  QString strToTraversals;
public:
  MainWindow();

public slots:
  void on_displayTreeButton_clicked();
  void on_find_clicked();
  void on_insert_clicked();
  void on_del_clicked();
  void on_pushButton_PreOrder_clicked();
  void on_pushButton_InOrder_clicked();
  void on_pushButton_PostOrder_clicked();
  void on_destroy_clicked();
  void on_deleteRightBranch_clicked();
  void on_deleteLeftBranch_clicked();
  void on_destroySubTree_clicked();
  void on_findCommonKey_clicked();
protected:
  Ui::MainWindow *ui;
};