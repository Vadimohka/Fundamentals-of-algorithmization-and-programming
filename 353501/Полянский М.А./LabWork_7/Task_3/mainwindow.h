#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "VisualHashMap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void clearClicked();
  void randClicked();
  void getClicked();
  void setClicked();
  void delClicked();
  void update();

private:
  Ui::MainWindow *ui;
  VisualMap *visualMap;

};

#endif // MAINWINDOW_H
