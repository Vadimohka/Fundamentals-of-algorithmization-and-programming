#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <myscene.h>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QRect>
#include <QRectF>
#include <QResizeEvent>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow* ui;
  MyScene* scene;
  QGraphicsView* view;
  QTimer* timer;

 private:
  void resizeEvent(QResizeEvent* event);
 private slots:
  void slotTimer();
  void on_pushbutton_clicked();
};
#endif  // MAINWINDOW_H
