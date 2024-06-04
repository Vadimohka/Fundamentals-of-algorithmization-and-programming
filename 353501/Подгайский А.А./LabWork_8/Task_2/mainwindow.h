#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "PriorityTree.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

    PriorityTree<long> * tree;

public:
  MainWindow(QWidget* = nullptr);
  ~MainWindow();

  void refresh();
private slots:
  void on_pushBtn_clicked();
  void on_initBtn_clicked();
  void on_popBtn_clicked();


protected:
  Ui::MainWindow *ui;
};