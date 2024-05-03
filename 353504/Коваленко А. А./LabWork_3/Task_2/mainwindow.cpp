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

qint64 MainWindow::A(qint64 m, qint64 n)
{
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return A(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return A(m - 1, A(m, n - 1));
    }
    return -1;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_answer->setText(QString::number(A(ui->spinBox1->value(), ui->spinBox2->value())));
}
