#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void setStat();
private slots:
    void on_flipBtn_clicked();

    void on_setBtn_clicked();

    void on_resetBtn_clicked();

    void on_testBtn_clicked();

private:
    Ui::MainWindow *ui;
    BitSet<64> bit;
};
#endif // MAINWINDOW_H
