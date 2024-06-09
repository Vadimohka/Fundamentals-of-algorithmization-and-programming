#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "Bitset.h"

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
  void updateSet();
  void updateInfo();

private slots:
  void on_flip_clicked();
  void on_reset_clicked();
  void on_test_clicked();
 void on_set_clicked();


protected:
  Ui::MainWindow *ui;
  static const size_t Size = 512;
  Bitset<Size> bits;
};