#pragma once

#include "Rect.h"
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
  Rect *rect;
  QGraphicsScene *scene;

private slots:
  void onLeftClicked();
  void onRightClicked();
};
