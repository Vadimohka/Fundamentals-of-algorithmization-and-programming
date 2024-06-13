#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "hanoitower.h"

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
    void on_spinBoxDisks_valueChanged(int arg1);

    void on_pushButtonStart_clicked();

    void on_pushButtonReset_clicked();

private:
    void hanoi(int diskCount, QChar from, QChar to, QChar temp);
    int disksCount = 3;
    HanoiTower *tower;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
