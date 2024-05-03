#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "CustomValidator.h"

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
  void print();
  long long solve(unsigned long long n, unsigned long long res);

protected:
  Ui::MainWindow *ui;
  
  
};