#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "plant.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void printArr(int arr[], int n);

private:
    Ui::MainWindow *ui;

    Plant plant;
    Plant _plant;
    Plant plantUser;
    Plant _plant1;
    Plant* plant1;
    Plant _plant2;
};
#endif // MAINWINDOW_H
