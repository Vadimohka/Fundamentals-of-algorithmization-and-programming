#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "VisualVect.h"
#include <QGraphicsScene>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui
{
  class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();
  void ReDraw();

private slots:
  void on_arraysize_valueChanged();
  void on_reset_clicked();
  void on_start_clicked();
  void on_find_clicked();
  
private:
  bool sortingInProgress = false;

protected:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;
  QElapsedTimer* time = nullptr;
  VisualVector* array;
  
};