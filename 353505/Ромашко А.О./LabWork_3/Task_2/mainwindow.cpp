#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Функция Аккермана");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::Akfunc(int m, int n)
{
    if(m == 0)
        return n+1;
    if(m>0 && n == 0)
        return Akfunc(m-1, 1);
    if(m>0 && n >0)
        return Akfunc(m-1, Akfunc(m,n-1));
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    mg = arg1;

}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    ng = arg1;
}


void MainWindow::on_pushButton_clicked()
{
    if(mg > 4 || (mg == 3 && ng >= 11) || (mg == 4 && ng >= 1)) {
        ui->label_4->setText("A(" + ui->spinBox->text() + ", " + ui->spinBox_2->text() +") слишком велико!");
        return;
    }
    ui->label_4->setText(QString::number(Akfunc(ui->spinBox->value(),ui->spinBox_2->value())));
}

