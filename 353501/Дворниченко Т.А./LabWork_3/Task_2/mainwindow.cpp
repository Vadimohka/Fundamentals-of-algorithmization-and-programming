#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->zaebok, &QPushButton::clicked, this, &MainWindow::on_zaebok_clicked);

}
uint_least64_t ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

MainWindow::~MainWindow()
{
    delete ui;   
}

void MainWindow::on_zaebok_clicked()
{
    int m = ui->Argum1->text().toInt();
    int n = ui->Argum2->text().toInt();

    uint_least64_t result = ackermann(m, n);

    ui->label->setText("Результат: " + QString::number(result));
}

