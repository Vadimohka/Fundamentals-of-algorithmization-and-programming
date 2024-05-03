#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
unsigned long long MainWindow::ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_4->setText("A(m,n) = ");

    int m, n;

    m = ui->spinBox->value();
    n = ui->spinBox_2->value();

    if ((m > 5 && n > 0) || (m > 5 && n > 1) || (m > 4 && n > 1) || (m > 61 && n == 3) || (m >= 4 && n >= 4)) {
        QMessageBox::critical(0, "Ошибка", "Число A(m, n) получится слишком большим и будет\nсчитаться очень долго или получится переполнение.\nВведите, пожалуйста другие значения.");
    } else {
        ui->label_4->setText("A(m,n) = "+QString::number(ackermann(m, n)));
    }
}

