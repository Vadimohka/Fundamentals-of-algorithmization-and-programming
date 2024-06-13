#pragma once

#include "FileFunction/Service.h"
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

    QString actions = "1 - paragraph\n2 - array\n3 - Text structure\n4 - Binary struct\n5 - Sentense";
    Service* service = nullptr;
  
public:
  MainWindow();
  ~MainWindow();


private slots:
  void on_chooseBtn_clicked();

protected:
  Ui::MainWindow *ui;
};