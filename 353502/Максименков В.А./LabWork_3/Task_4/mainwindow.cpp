#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_executeButton_clicked()
{
    int numberOfCircles = ui->spinBox->value();
    QString ans = "";
    hanoi(numberOfCircles, ans, 'A', 'C', 'B');
    ans.remove(0, 1);
    ui->textBrowser->setText(ans);
}

void MainWindow::hanoi(int n, QString& ans, char first, char second, char third) // всегда мы хотим переместить с первого на второй
{
    if (n == 1)
    {
        ans += "|1 ";
        ans.push_back(second);
        return;
    }

    hanoi(n-1, ans, first, third, second);
    ans.push_back('|');
    ans += QString::number(n);
    ans.push_back(' ');
    ans.push_back(second);
    hanoi(n-1, ans, third, second, first);
}

