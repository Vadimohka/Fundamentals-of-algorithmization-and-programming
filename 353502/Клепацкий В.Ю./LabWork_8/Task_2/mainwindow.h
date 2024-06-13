#pragma once

#include <QLibrary>
#include <QMainWindow>
#include "Heap.h"
#include <memory>
#include <qgraphicsscene.h>

class Solver;

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
    void update();

public slots:
    void randomize();

protected:
    Ui::MainWindow *ui;
    std::unique_ptr<Heap> solver;
    QLibrary lib;
};
