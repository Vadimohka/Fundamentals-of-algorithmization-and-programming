#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Reverse Number");
    ui->reverseNum_edit->setReadOnly(true);

    connect(ui->reverse_button, SIGNAL(clicked()), this, SLOT(ShowReversedNumber()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


long long MainWindow::ReverseNumber(long long number)
{
    // Recursive solution
    if (number == 0)
    {
        return 0;
    }
    else
    {
        return (number % 10) * pow(10, int(log10(number))) + ReverseNumber(number / 10);
    }
}

void MainWindow::ShowReversedNumber()
{
    bool flag = false;
    long long number = ui->numToReverse_edit->text().toLongLong(&flag);
    if (ui->numToReverse_edit->text().isEmpty() || !flag)
    {
        ui->reverseNum_edit->setText("Please enter a number");
        return;
    }

    if (ui->numToReverse_edit->text().toInt() < 0)
    {
        ui->reverseNum_edit->setText("Please enter a positive number");
        return;
    }


    ui->reverseNum_edit->setText(QString::number(ReverseNumber(number)));
}
