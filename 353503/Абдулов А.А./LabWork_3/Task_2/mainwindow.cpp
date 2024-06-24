#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m = -1;
    n = -1;

    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::getNumberM);
    connect(ui->lineEdit_2, &QLineEdit::returnPressed, this, &MainWindow::getNumberN);
    connect(ui->lineEdit, &QLineEdit::cursorPositionChanged, this, &MainWindow::changeLien);
    connect(ui->lineEdit_2, &QLineEdit::cursorPositionChanged, this, &MainWindow::changeLien);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getNumberM()
{
    bool ok;
    m = ui->lineEdit->text().toUInt(&ok);
    if(!ok || (m == 0 && n == 0))
    {
        QMessageBox::warning(this, "Ошибка", "Введенное значение не является числом");
    }
    else
    {
        ui->lineEdit->setReadOnly(true);
    }
    if(m > 0 && n > 0)
    {
        ui->label_5->setText(QString::number(functionAkerman(m,n)));
    }
}

void MainWindow::getNumberN()
{
    bool ok;
    n = ui->lineEdit_2->text().toUInt(&ok);
    if(!ok || (m == 0 && n == 0))
    {
        QMessageBox::warning(this, "Ошибка", "Введенное значение не является числом");
    }
    else
    {
        ui->lineEdit_2->setReadOnly(true);
    }
    if(m > 0 && n > 0)
    {
        ui->label_5->setText(QString::number(functionAkerman(m,n)));
    }
}

int MainWindow::functionAkerman(int m, int n)
{
    if(m == 0)
    {
        return n + 1;
    }
    else if(m > 0 && n == 0)
    {
        return functionAkerman(m - 1, 1);
    }
    else
    {
        return functionAkerman(m - 1, functionAkerman(m, n - 1));
    }
}

void MainWindow::changeLien()
{
    ui->lineEdit->setReadOnly(false);
    ui->lineEdit_2->setReadOnly(false);
}
