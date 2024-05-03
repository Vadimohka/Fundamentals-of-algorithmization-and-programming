#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include "HanoiAnimation.h"
#include <QTableWidgetItem>

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
  int speed = 2;

  HanoiTowers* towers;

  void hanoi(int n, int start, int end);
  void moveDisk(int n, int start, int end);

  MainWindow();
  ~MainWindow();
  private:
  void on_pushButton_clicked();
  void on_party_clicked();
  void on_spinBox_valueChanged(int arg1);
  void on_slider_valueChanged(int arg1);

  bool wasCalculatedFirstPos = false;

  int counter = 0;

  int onFirst = 0;
  int onSecond = 0;
  int onThird = 0;
  void calculatePrePositions();

  int movesCount = 0;
protected:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;
};
