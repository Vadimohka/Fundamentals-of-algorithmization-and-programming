#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette p(ui->centralwidget->palette());
    p.setColor(QPalette::Window, QColor(180,243,192));
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}

unsigned long long MainWindow::A(int m, int n){
    if (m == 0) return n + 1;
    else if (m>0&&n == 0) return A(m - 1, 1);
    else if (m>0&&n>0) return A(m - 1, A(m, n - 1));
}

void MainWindow::on_pushButton_clicked()
{
    int m = ui -> spinBox_2 -> value(), n = ui -> spinBox -> value();
    if((m==4&&n>=1)||m>4||(m==3&&n>12))
    {
        ui -> label_4 -> setText("Значение функции Аккермана слишком большое");
    }
    else
    {
        ui -> label_4 -> setText("Результат: "+QString::number(A(m, n)));
    }
}
