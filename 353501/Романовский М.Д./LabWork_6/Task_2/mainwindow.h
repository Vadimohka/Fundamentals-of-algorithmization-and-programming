#pragma once

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

private slots:
  void onSubtaskSelect();

protected:
  Ui::MainWindow *ui;
  QWidget *currentSubtask;
};