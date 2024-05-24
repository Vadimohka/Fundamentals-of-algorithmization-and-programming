#include "mainwindow.h"
#include "ui_mainwindow.h"

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

uint_least64_t MainWindow::Akermanfunc(uint_least64_t m, uint_least64_t n)
{
    if (n == 0 && m > 0) {
        return Akermanfunc(m - 1, 1);
    }
    if (n > 0 && m > 0) {
        return Akermanfunc(m - 1, Akermanfunc(m, n - 1));
    }
    if (m == 0) {
        return n + 1;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString mInput = ui->linform->text();
    QString nInput = ui->linforn->text();

    bool mOk, nOk;
    uint_least64_t m = mInput.toUInt(&mOk);
    uint_least64_t n = nInput.toUInt(&nOk);

    if ((m > 3) || (m == 3 && n > 10) || (m == 2 && n > 10000) || (m == 1 && n > 170000) || (m == 0 && n > 250000)){
        ui->answerlabel->setText("Out of range");
        return;
    }

    if (mOk && nOk) {
        long long result = Akermanfunc(m, n);
        ui->answerlabel->setText(QString::number(result));
    } else {
        ui->answerlabel->setText("Invalid input");
    }
}
