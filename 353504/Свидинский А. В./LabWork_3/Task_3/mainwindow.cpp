#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QKeyEvent"
#include <gmp.h>

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
    mpz_t m, n, result;
    mpz_init_set_str(m, numbers[0].toStdString().c_str(), 10);
    mpz_init_set_str(n, numbers[1].toStdString().c_str(), 10);
    mpz_init(result);
    convert.ackermann(result, m, n);
    char * result_str = mpz_get_str(NULL, 10, result);
    ui->outputNumber->setText(QString(result_str));
    ui->outputNumber->setReadOnly(true);
    free(result_str);
    mpz_clears(m, n, result, NULL);
}

void MainWindow::on_clearButton_clicked()
{
    ui->inputNumber->clear();
    ui->outputNumber->clear();
}
