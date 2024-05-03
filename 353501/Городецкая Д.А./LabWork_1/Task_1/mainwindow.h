#pragma once

#include "Ellipse.h"
#include "Glaza.h"
#include "Gubi.h"
#include <QMainWindow>
#include <qgraphicsscene.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow();
  ~MainWindow();

protected:
  Ui::MainWindow *ui;
  Ellipse *ellipse;
  Glaza *glaza;
  Gubi *gubi;
  // QTimer *tim;
  //   QTimer *tim2;

  QGraphicsScene *scene;

private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
};
