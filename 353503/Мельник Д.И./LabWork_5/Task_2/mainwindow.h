#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "String.h"

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

  QString generateData(String cur, String another);

private slots:
  void updateOuts();

protected:
  Ui::MainWindow *ui;
};