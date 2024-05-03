#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <qtmetamacros.h>
#include "HanoiScene.h"
#include "HanoiLogic.h"

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
  ~MainWindow();

private:
  void refreshTable();

public slots:
  void start();
  void reset();
  void pause();
  void prohibitItemSelection();
  void changeSpeed();

private slots:
  void nextAction();

private:
  HanoiScene *scene;

  QVector<QPair<short, short>> actions;
  int cur = 0;
  bool paused = true;
  
protected:
  Ui::MainWindow *ui;
};