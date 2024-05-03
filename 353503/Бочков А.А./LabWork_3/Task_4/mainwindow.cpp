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

void MainWindow::hanoi(int n, int s, int f)
{
    if (n == 1) {
        ui->textBrowser->append("From " + QString::number(s) + " to " + QString::number(f));
        return;
    }
    int t = 6 - s - f;
    hanoi(n - 1, s, t);
    ui->textBrowser->append("From " + QString::number(s) + " to " + QString::number(f));
    hanoi(n - 1, t, f);
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    n = ui->lineEdit->text().toInt(&ok);
    if (!ok || n > 15 || n < 1) {
        msgBox.setText("Неправильный ввод");
        msgBox.exec();
    } else {
        hanoi(n, 1, 3);
    }
}
