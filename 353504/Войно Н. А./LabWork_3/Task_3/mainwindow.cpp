#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::getNumber);
    connect(ui->lineEdit, &QLineEdit::cursorPositionChanged, this, &MainWindow::changeLien);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getNumber()
{
    bool ok;
    int temp, result = 0;

    number = ui->lineEdit->text().toUInt(&ok);
    temp = number;
    while(true)
    {
        if(temp > 0 && temp % 10 == 0)
        {
            ok = false;
            break;
        }
        else if(temp == 0)
        {
            break;
        }
        else
        {
            temp /= 10;
            continue;
        }
    }
    if(!ok)
    {
        QMessageBox::warning(this, "Ошибка", "Введенное значение не является числом");
        return ;
    }

    ui->label_3->setText(QString::number(reverse(number,result)));

}

void MainWindow::changeLien()
{
    ui->lineEdit->setReadOnly(false);
}

int MainWindow::reverse(int n, int r)
{
    if(n == 0)
    {
        return r;
    }
    r = r * 10 + n % 10;
    n /= 10;
    return reverse(n, r);
}
