#pragma once

#include "Footwear.h"
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
  Footwear * fw = nullptr;

  void initDefaultFootwear();
  void resetFootwear(Footwear*);


private slots:
  void on_initialiseButton_clicked();
  void on_initialiseValuesButton_clicked();
  void on_printButton_clicked();


};