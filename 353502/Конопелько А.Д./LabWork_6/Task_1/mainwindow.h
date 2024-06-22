#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "autorepair.h"

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
    AutoRepair repairInst;
    int step = 0, stepArray = 0;
    Ui::MainWindow *ui;
    AutoRepair repair1;
    AutoRepair repair2;
    AutoRepair repair3;
    AutoRepair *repairPtr = &repair3;
    AutoRepair repair4;
    AutoRepair &repairRef = repair4;
    QString myArray;
};
#endif // MAINWINDOW_H
