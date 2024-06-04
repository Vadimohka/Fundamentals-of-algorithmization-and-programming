#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../../../../alexandr/myvector/myvector.h"
#include <mypair.h>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    std::vector<mypair<int, int> > a;
    myvector<mypair<int, int> > b;
    mypair<int, int> c;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
