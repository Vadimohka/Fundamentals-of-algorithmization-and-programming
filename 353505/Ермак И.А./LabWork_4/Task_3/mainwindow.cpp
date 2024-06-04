#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    countElements = ui->SpinBox->value();
    on_Button_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_clicked()
{
    vector.clear();
    int element = 0;
    countElements = ui->SpinBox->value();
    for (int i = 0; i < countElements; ++i) {
        element = QRandomGenerator::global()->bounded(1, 300);
        vector.append(element);
    }
    ui->textEdit->setText(printVector() + "\n" + printMedians());
}

QString MainWindow::printVector()
{
    QString text = "Вектор: ";
    for (int i = 0; i < countElements; ++i) {
        text += ' ' + QString::number(vector[i]);
    }
    return text;
}

QString MainWindow::printMedians()
{
    QString text = "Медианы: ";
    std::sort(vector.begin(), vector.end());
    for (int i = 1; i <= countElements - countElements % 3; i += 3) {
        text += ' ' + QString::number(vector[i]);
    }
    if (countElements % 3 == 1) {
        text += ' ' + QString::number(vector[countElements - 1]);
    }
    else if (countElements % 3 == 2) {
        text += ' ' + QString::number((vector[countElements - 1] + vector[countElements - 2]) / 2);
    }
    return text;
}

