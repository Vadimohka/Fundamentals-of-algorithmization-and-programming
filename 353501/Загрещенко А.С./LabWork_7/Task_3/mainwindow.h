#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

class Solver;

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

public slots:
  void clearClicked();
  void randClicked();
  void getClicked();
  void setClicked();
  void delClicked();

protected:
  Ui::MainWindow *ui;
  Solver *solver;
};