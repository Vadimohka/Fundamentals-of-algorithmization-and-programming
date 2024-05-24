#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QFile>
#include<QMessageBox>
#include<QInputDialog>
#include "func_with_files.h"
#include"data.h"
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
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();


    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);



    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    func_with_files *a=new func_with_files;
    int sch=0;
    Data *data=new Data[1000];
    int pos=0;
    QString *c=new QString[6];
    QString *c1=new QString[6];
    bool fl1=0;
    bool fl2=0;
    bool fl3=0;
    int year=0;
    QString aa;
};
#endif // MAINWINDOW_H
