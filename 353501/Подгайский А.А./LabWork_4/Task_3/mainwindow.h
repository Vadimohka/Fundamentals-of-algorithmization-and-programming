#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "ui_mainwindow.h"

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

private slots:
  void addElementSlot();
  void removeElement();
  void changedMedians(int row, int column);

private:
  void addElement();
  void setMedians(int beg, int end);



protected:
  Ui::MainWindow *ui;
};