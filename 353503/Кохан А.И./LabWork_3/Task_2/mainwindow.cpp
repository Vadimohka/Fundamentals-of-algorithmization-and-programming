#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

constexpr short MAX_GOOD_NUMBER_FOR_M = 2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_answerButton_clicked()
{
    if (ui->spinBoxForM->value() > MAX_GOOD_NUMBER_FOR_M) {
        auto answerMessange = QMessageBox::question(
            this,
            "Внимание!",
            "Вы действительно хотите выбрать это число? Расчёты могут быть долгими",
            "Да",
            "Нет");

        if (answerMessange == 0) {
            ui->lineEditAnswer->setText(
                QString::number(funAckermann(ui->spinBoxForM->value(), ui->spinBoxForN->value())));
        }
    }

    else {
        ui->lineEditAnswer->setText(
            QString::number(funAckermann(ui->spinBoxForM->value(), ui->spinBoxForN->value())));
    }
}

long long MainWindow::funAckermann(int m, int n)
{
    if (m == 0) {
        return n + 1;
    }

    else if (n == 0 && m > 0) {
        return funAckermann(m - 1, 1);
    }

    else if (n > 0 && m > 0) {
        return funAckermann(m - 1, funAckermann(m, n - 1));
    }

    return 0;
}
