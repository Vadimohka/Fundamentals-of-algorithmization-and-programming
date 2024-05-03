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
    QStringList numbers = ui->inputNumber->text().split(" ");
    if (numbers.size() != 2) {
        ui->outputNumber->setText("Ошибка: введите два числа через пробел");
        return;
    }
    bool ok1, ok2;
    int m = numbers[0].toInt(&ok1);
    int n = numbers[1].toInt(&ok2);
    if (!ok1 || !ok2) {
        ui->outputNumber->setText("Ошибка: неверный ввод");
        return;
    }
    int result = convert.ackermann(m, n);
    ui->outputNumber->setText(QString::number(result));
    ui->outputNumber->setReadOnly(true);
}

void MainWindow::on_clearButton_clicked()
{
    ui->inputNumber->clear();
    ui->outputNumber->clear();
}
