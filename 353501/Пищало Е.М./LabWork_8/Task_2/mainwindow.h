#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "TreeHeap.h"
#include "ArrayHeap.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
    TreeHeap* h;

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
