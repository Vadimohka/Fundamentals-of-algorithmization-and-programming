#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <random>
#include <QStandardItemModel>
#include "pair.h"
#include "vector.cpp"

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
    int getRandomNumber(int min, int max);

private:
    Ui::MainWindow *ui;
    static std::random_device rd;
    static std::mt19937 gen;
    QStandardItemModel *modelL, *modelR;
};
#endif // MAINWINDOW_H
