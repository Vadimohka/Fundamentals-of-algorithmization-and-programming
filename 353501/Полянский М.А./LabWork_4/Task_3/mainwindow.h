#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QRandomGenerator>

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
  QVector<long> allNumber;
  QVector<long> median;

private slots:
  void on_add_clicked();
  void on_calculate_clicked();
  void on_randomadd_clicked();
  void on_reset_clicked();

protected:
  Ui::MainWindow *ui;
};