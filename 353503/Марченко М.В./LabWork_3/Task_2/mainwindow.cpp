#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::GetAkerman);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::GetAkerman()
{
    QString textM = ui->lineEditM->text();
    QString textN = ui->lineEditN->text();
    if (textN.isEmpty()|| textM.isEmpty()) {
        ui->labelA->clear();
        return;
    }

    bool ok;
    unsigned long long m = textM.toUInt(&ok);
    unsigned long long n = textN.toUInt(&ok);

    if (ok&& n>=0 && m>=0) {
        ui->labelA->setText(QString::number(Akerman(m, n)));

    } else {
        QMessageBox::critical(this, "Ошибка", "Некорректное значение!");
    }
}
unsigned long long MainWindow::Akerman(unsigned long long m, unsigned long long n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return Akerman(m - 1, 1);
    } else {
        return Akerman(m - 1, Akerman(m, n - 1));
    }
}
