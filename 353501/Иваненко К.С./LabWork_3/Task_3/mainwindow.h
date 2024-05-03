#pragma once

#include <QMainWindow>
#include "longlongval.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
      
public:
  long long number;
  QTimer *timer;
  void calculate();
  int reverse(int n, int a);
  MainWindow();
  ~MainWindow();

protected:
  Ui::MainWindow *ui;
};
