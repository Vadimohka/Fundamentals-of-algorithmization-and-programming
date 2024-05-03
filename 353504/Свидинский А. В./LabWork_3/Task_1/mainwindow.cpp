#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QKeyEvent"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMinimumSize(this->size());
    ui->inputNumber->setFocus();
    ui->outputNumber->setFocusPolicy(Qt::NoFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        if (ui->clearButton->hasFocus())
            ui->convertButton->setFocus();
        else if (ui->convertButton->hasFocus())
            ui->inputNumber->setFocus();
        break;
    case Qt::Key_Down:
        if (ui->inputNumber->hasFocus())
            ui->convertButton->setFocus();
        else if (ui->convertButton->hasFocus())
            ui->clearButton->setFocus();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}


void MainWindow::on_convertButton_clicked()
{
    bool ok;
    long double number = ui->inputNumber->text().toDouble(&ok);
    if (!ok) {
        ui->outputNumber->setText("Ошибка: неверный ввод");
        return;
    }
    QString binaryNumber = convert.decimalToBinary(number);
    ui->outputNumber->setText(binaryNumber);
    ui->outputNumber->setReadOnly(true);
}


void MainWindow::on_clearButton_clicked()
{
    ui->inputNumber->clear();
    ui->outputNumber->clear();
}
