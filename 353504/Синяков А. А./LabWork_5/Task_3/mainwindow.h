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

private slots:
    void on_pushButton_all_clicked();

    void on_pushButton_any_clicked();

    void on_pushButton_count_clicked();

    void on_pushButton_none_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_set_clicked();

    void on_pushButton_getSize_clicked();

    void on_pushButton_ullong_clicked();

    void on_pushButton_ulong_clicked();

    void on_pushButton_flip_clicked();

    void on_pushButton_flipArg_clicked();

    void on_pushButton_setArg_clicked();

    void on_pushButton_resetArg_clicked();

    void on_pushButton_testArg_clicked();

private:
    Ui::MainWindow *ui;
    BitSet* bitset;
};
#endif // MAINWINDOW_H
