#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "akkermanfunction.h"

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

void MainWindow::on_getAnswerButton_clicked()
{
    unsigned long long m = ui -> mSpinBox -> value();
    unsigned long long n = ui -> nSpinBox -> value();
    if ((m == 3 && n > 10) || (m == 2 && n > 10000) || (m == 1 && n > 170000) || (m == 0 && n > 250000))
    {
        ui -> lineEdit -> setText("Out of range");
        return;
    }
    ui -> lineEdit -> setText(QString::number(AkkermanFunction::akkermanFunction(m , n)));
}

