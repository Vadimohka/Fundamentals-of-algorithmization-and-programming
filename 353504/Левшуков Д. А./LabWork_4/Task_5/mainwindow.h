#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector.h"
#include "pair.h"
#include <string>
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
    void show_matrix();
    bool check_element();
    bool check_positions();
    bool check_range();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



    //void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    //void on_pushButton_5_clicked();

    //void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    MyVector<pair<MyVector<int>, MyVector<pair<int, double>>>> matrix,add;
    MyVector<int>f;
    MyVector<pair<int,double>>s;
    pair<MyVector<int>, MyVector<pair<int, double>>>el;
    int pos1=0,pos2=0;
};
#endif // MAINWINDOW_H
