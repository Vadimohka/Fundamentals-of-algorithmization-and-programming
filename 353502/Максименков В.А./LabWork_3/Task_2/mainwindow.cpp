#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 900; ++i)
    {
        a[0][i] = i+1;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_evaluateButton_clicked()
{
    int m = ui->mSpinBox->value();
    int n = ui->nSpinBox->value();
    ui->answerBrowser->setText(QString::number(AccermanFunction(m, n)));
}

int MainWindow::AccermanFunction(int m, int n)
{
    qDebug() << ++col << m << n;
    if (a[m][n] != 0)
    {
        return a[m][n];
    }
    if (m == 0)
    {
        a[m][n] = n+1;
        return n+1;
    }
    if (m > 0 && n == 0) return AccermanFunction(m-1, 1);
    if (m > 0 && n > 0)
    {
        int temp = AccermanFunction(m, n-1);
        return AccermanFunction(m-1, temp);
    }
}

