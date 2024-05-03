#pragma once

#include "bitset.h"
#include <QMainWindow>
#include <qgraphicsscene.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
  static const size_t bsetSize = 512;
  Bitset<bsetSize> bitset;

public:
  MainWindow();

private slots:
  void on_flipBtn_clicked();
  void on_resetBtn_clicked();
  void on_testBtn_clicked();
  void on_setBtn_clicked();


private:
  void update_info();
  void updateBitset();

  QString bstr(bool b);

protected:
  Ui::MainWindow *ui;
};