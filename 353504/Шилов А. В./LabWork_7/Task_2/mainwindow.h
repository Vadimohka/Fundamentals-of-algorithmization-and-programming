#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mybintree.h"

class MyBinTree;

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

protected:

    Ui::MainWindow *ui;
    MyBinTree *mybintree;
private slots:

    void on_randBtn_clicked();
    void on_clearBtn_clicked();
    void on_getBtn_clicked();
    void on_setBtn_clicked();
    void on_delBtn_clicked();
    void on_balanceBtn_clicked();

};

#endif // MAINWINDOW_H
