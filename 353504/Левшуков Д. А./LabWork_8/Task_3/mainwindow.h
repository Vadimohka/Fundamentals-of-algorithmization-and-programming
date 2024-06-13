#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rbt.h"
#include <ctime>
#include <random>
#include<QMessageBox>
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

    void upd();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();


    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    Map<int,int> m;
    Set<int>s;
    std::mt19937 gen;
};
#endif // MAINWINDOW_H
