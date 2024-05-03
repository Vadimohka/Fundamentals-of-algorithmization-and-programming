#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
      
public:
  QTimer* timer;
  long long numberM, numberN;
  unsigned long long funk(long long m, long long n);
  void on_pushButton_clicked();
  void change();
  MainWindow();
  ~MainWindow();

protected:
  Ui::MainWindow *ui;
};
