#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

class Buisnessman;

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

private slots:
  void print();


protected:
  Ui::MainWindow *ui;
  Buisnessman *buisenessman;
};