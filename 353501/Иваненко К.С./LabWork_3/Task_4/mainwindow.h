#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include "towers.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
      
public:

  int numDisks = 3; // Количество дисков
  char sourcePeg = 'A';
  char auxiliaryPeg = 'B';
  char targetPeg = 'C';
  int N = 1;
  int cnt;
  int speed = 0;

  HanoiTowers* towers;

  void hanoi(int n, char source, char auxiliary, char target);
  void moveDisk(int n, char source, char target);

  MainWindow();
  ~MainWindow();
  private:
  void on_pushButton_clicked();
  void on_party_clicked();
  void on_spinBox_valueChanged(int arg1);
  void on_slider_valueChanged(int arg1);

protected:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;
};
