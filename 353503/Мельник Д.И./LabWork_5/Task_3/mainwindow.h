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

private slots:
  void update();
private:
  size_t getPos();

protected:
  Ui::MainWindow *ui;
  Bitset<300> bits;
};