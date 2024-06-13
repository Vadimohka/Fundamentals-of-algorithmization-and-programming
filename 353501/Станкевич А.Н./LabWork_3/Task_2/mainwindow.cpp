#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calculateAckermann()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calculateAckermann()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

unsigned int ackermann(int m,int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

void MainWindow::calculateAckermann()
{
    int m = ui->spinBox_2->value();
    int n = ui->spinBox->value();
    unsigned int result = ackermann(static_cast<unsigned int>(m), static_cast<unsigned int>(n));
    ui->label_5->setText(QString::number(result));
}
