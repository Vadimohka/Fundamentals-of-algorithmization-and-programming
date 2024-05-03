#pragma once

#include "RectArray.h"
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
  ~MainWindow();

protected:
  Ui::MainWindow *ui;
  RectArray *array;
  QGraphicsScene *scene;

private slots:

void on_spinBox_valueChanged(int arg1);
};
