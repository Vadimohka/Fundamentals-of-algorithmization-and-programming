#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    status = true;


    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::getNumber);
    connect(ui->lineEdit, &QLineEdit::cursorPositionChanged, this, &MainWindow::changeLien);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getNumber()
{
    int integerPart = 0;
    double floatPart = 0;
    bool ok;
    number = ui->lineEdit->text().toDouble(&ok);
    if(!ok)
    {
        QMessageBox::warning(this, "Ошибка", "Введенное значение не является числом");
    }
    else
    {
        ui->lineEdit->setReadOnly(true);
        ui->label_3->setText(QString::number(number));
    }

    int k = 12;
    integerPart = number;
    floatPart = number - integerPart;
    ui->label_3->setText(recurse(integerPart, floatPart, k) + "." + recurse(integerPart, floatPart, k));

}

QString MainWindow::recurse(int a, double b, int k)
{
    if(status)
    {
        if(k == 0)
        {
            status = false;
            return "";
        }
        else
        {
            double newB = 2 * b;
            int intB = newB;
            if(intB == 1)
            {
                return "1" + recurse(a, newB - intB, k - 1);
            }
            else
            {
                return "0" + recurse(a, newB, k - 1);
            }
        }

    }
    else
    {
        if(a == 0)
        {
            status = true;
            return "";
        }
        else
        {
            return recurse(a / 2, b, k) + QString::number(a % 2);
        }
    }
}

void MainWindow::changeLien()
{
    ui->lineEdit->setReadOnly(false);
}
