#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "carrepairshop.h"

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
    Ui::MainWindow *ui;
    CarRepairShop carShop1;
    CarRepairShop carShop2;
    CarRepairShop carShop3;
    CarRepairShop *carShopPointer = &carShop2;
    CarRepairShop &carShopReference = carShop3;
    void showInfo();
};
#endif // MAINWINDOW_H
