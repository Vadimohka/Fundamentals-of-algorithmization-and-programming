#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

long long reverse(long long a, int iteration)
{
    if(a == 0) return 0;
    return ((a % 10) * pow(10, iteration) + reverse(a / 10, floor(iteration - 1)));
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->spinBox->value()<0){
        ui->label->setText("-"+QString::number(reverse(-ui->spinBox->value(), log10(-ui->spinBox->value()))));
        return;
    }
    ui->label->setText(QString::number(reverse(ui->spinBox->value(), log10(ui->spinBox->value()))));
}

