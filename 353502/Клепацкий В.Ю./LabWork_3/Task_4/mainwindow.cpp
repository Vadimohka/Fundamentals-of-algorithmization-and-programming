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

void MainWindow::hanoi(int n, int i, int k)
{
    QString str;
    if (n == 1) {
        otvet += "    move disk 1 from tower " + QString::number(i) + " to " + QString::number(k);
        str = otvet.join("\n");
        ui->textEdit->setPlainText(str);
    } else {
        int tmp = 6 - i - k;
        hanoi(n - 1, i, tmp);
        otvet += "    move disk " + QString::number(n) + " from tower " + QString::number(i)
                 + " to " + QString::number(k);
        str = otvet.join("\n");
        ui->textEdit->setPlainText(str);
        hanoi(n - 1, tmp, k);
    }
}
void MainWindow::on_pushButton_clicked()
{
    int n = ui->spinBox->text().toInt();
    hanoi(n, 1, 2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
    otvet.clear();
}
