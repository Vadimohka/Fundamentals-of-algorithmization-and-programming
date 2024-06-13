#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QChartView>

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
  void onCalc();

protected:
  Ui::MainWindow *ui;
  QChartView *chartView;
};