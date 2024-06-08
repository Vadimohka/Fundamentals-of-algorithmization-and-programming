#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "smartphone.h"
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
    void on_print_result_clicked();

    void on_pushButton_clicked();

    void onCheckBox1Clicked();
    void onCheckBox2Clicked();
    void onCheckBox3Clicked();
    void onCheckBox4Clicked();

private:
    Ui::MainWindow *ui;
    Smartphone smartphone1;
    Smartphone smartphone2;
    Smartphone smartphone3;
    Smartphone *smartPtr = &smartphone3;
    Smartphone smartphone4;
    Smartphone &smartRef = smartphone4;
};
#endif // MAINWINDOW_H
