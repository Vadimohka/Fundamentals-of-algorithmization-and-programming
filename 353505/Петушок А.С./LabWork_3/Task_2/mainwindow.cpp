#include "mainwindow.h"
#include "./ui_mainwindow.h"


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

void MainWindow::on_SolutionButton_clicked()
{
    short m = ui -> mValue -> value();
    short n = ui -> nValue -> value();
    if ((m == 4 && n >= 1) || m > 4 || (m == 3 && n > 12)) {
        ui -> AnswerLine -> setText("Ackermann function value is too high");
    } else {
        ui -> AnswerLine -> setText(QString::number(ackermannFunction.ackermann(m,n)));
    }
}


