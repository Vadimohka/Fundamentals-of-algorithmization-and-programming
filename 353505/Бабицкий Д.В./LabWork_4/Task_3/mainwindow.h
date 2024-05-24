#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <qspinbox.h>

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
  QList<int> getInpValues();
  QList<int> compute(QList<int> inp);


private slots:
  void updateInpTable();
  void updateOut();


protected:
  Ui::MainWindow *ui;
};