#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

class Cloth;

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

private: 
  void fillUiFromStruct();

protected:
  Ui::MainWindow *ui;
  Cloth *cloth;
};