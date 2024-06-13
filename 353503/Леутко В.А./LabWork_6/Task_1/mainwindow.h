#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "autorepairshop.h"

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
    QString printInfo(const AutoRepairShop& shop);

private slots:
    void handleInitMethodChanged(int index);

private:
    Ui::MainWindow *ui;
    AutoRepairShop shop1, shop2, shop3, shop4;

    void explicitInitialization();
    void initializeWithPointer();
    void initializeWithReference();
    void initializeFromTheKeyboard();
};
#endif // MAINWINDOW_H
