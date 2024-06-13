#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->enterSpinBox->setMinimum(0);
    ui->enterSpinBox->setMaximum(1000000000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::reverse(int number, int now)
{
    if (number == 0) return now;
    now *= 10;
    now += (number % 10);
    number /= 10;
    return reverse(number, now);
}

void MainWindow::on_reverseButton_clicked()
{
    int number = ui->enterSpinBox->value();
    int ans = reverse(number, 0);
    ui->answerBrowser->setText(QString::number(ans));
}

