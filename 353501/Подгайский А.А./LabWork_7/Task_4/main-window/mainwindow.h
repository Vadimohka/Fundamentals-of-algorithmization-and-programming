#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "PlotBuilder.h"

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
  void on_plotBtn_clicked();
  void on_typeBox_currentIndexChanged(int ind);


protected:
  Ui::MainWindow *ui;
};