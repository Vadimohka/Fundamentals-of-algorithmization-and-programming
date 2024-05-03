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

int MainWindow::A(int m, int n)
{
    count++;
    //qDebug() << n << m;
    if (count >= 1e6) {
        return -1;
    }
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return A(m - 1, 1);
    }
    return A(m - 1, A(m, n - 1));
}

void MainWindow::on_pushButton_clicked()
{
    n = ui->lineEdit_2->text().toInt(&ok1, dec);
    m = ui->lineEdit_4->text().toInt(&ok2, dec);
    if (ok1 && ok2 && n >= 0 && m >= 0) {
        count = 0;
        ans = A(m, n);
        if (ans == -1) {
            msgBox.setText("Слишком большие числа");
            msgBox.exec();
        } else {
            ui->lineEdit_5->setText(QString::number(ans));
        }
    } else {
        msgBox.setText("Неправильный ввод");
        msgBox.exec();
    }
}
