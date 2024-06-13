#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "VisualBST.h"

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
  void update();

private slots:
  void on_clearBtn_clicked();
  void on_randBtn_clicked();
  void on_getBtn_clicked();
  void on_setBtn_clicked();
  void on_balanceBtn_clicked();
  void on_delBtn_clicked();

protected:
  Ui::MainWindow *ui;
  VisualBST* bst;
};