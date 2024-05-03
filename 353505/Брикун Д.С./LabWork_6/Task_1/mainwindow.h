#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "house.h"

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
    void on_pushButton_clicked();

    void on_pushButton_send_clicked();

private:
    House houseKeyboard;
    int step = 0, stepArray = 0;
    Ui::MainWindow *ui;
    House house1;
    House house2;
    House house3;
    House *housePtr = &house3;
    House house4;
    House &houseRef = house4;
    QString intArray;
};
#endif // MAINWINDOW_H
