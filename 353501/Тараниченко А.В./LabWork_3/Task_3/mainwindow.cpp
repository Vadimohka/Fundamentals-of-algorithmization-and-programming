#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    My_validator *validator = new My_validator(this);
    ui->input->setValidator(validator);
    connect(ui->input, &QLineEdit::textChanged, this, &MainWindow::number);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::reverseNum(long long num, long long res)
{
    if (num == 0) {
        return res;
    } else {
        return reverseNum(num / 10, res * 10 + num % 10);
    }
}

void MainWindow::number(const QString &text)
{
    if (text.isEmpty()) {
        ui->output->setText(" ");
    } else if (text.count('-') == text.length()) {
        ui->output->setText("-");
    } else {
        long long num = text.toLongLong();
        long long res = reverseNum(qAbs(num), 0);
        if (num < 0) {
            res *= -1;
        }
        ui->output->setText(QString::number(res));
    }
}
