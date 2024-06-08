#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

#include "tasksolver.h"

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
    void insert();
    void get();
    void remove();
    void findMinKey();
    void reset();

protected:
    TaskSolver *solver = nullptr;
    Ui::MainWindow *ui;
};
