#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "bitset.h"


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

private slots:
    void on_pushButton_flipArg_clicked();
    void on_pushButton_setArg_clicked();
    void on_pushButton_resetArg_clicked();
    void on_pushButton_testArg_clicked();

private:
    Ui::MainWindow *ui;
    BitSet* bitset;

    void demonstrateAll();
    void demonstrateAny();
    void demonstrateCount();
    void demonstrateNone();
    void demonstrateReset();
    void demonstrateSet();
    void demonstrateGetSize();
    void demonstrateUllong();
    void demonstrateUlong();
    void demonstrateFlip();

};
#endif // MAINWINDOW_H
