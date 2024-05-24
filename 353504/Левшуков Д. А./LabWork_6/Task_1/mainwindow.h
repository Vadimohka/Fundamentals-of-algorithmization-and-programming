#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ship.h"
#include <QMessageBox>

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

    bool check();
    void set_structs();
    std::string toString(Ship x);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Ship ship_1, ship_2, ship_3, *ship_4, *ship_base=new Ship();
    Ship &ship_5=*ship_base;
    bool init=false;
};
#endif // MAINWINDOW_H
