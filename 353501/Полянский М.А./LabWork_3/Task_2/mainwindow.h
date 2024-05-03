#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

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

private slots:
  void showRes();
  int ackerman(int m, int n);
  void setMax();


protected:
  Ui::MainWindow *ui;
  
};