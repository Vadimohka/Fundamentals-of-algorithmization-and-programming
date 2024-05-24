#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>

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

void MainWindow::on_pushButton_clicked()
{
    int num = ui->spinBox->value();
    v.push_back(num);
    printV();
}

void MainWindow::printV() {
    QString strVector = "";

    for (int i = 0; i < (int)v.size(); i++) {
        strVector += QString::number(v[i]) + ", ";
        if (i==(int)v.size()-1){
        strVector.chop(2);
        }
    }

    ui->label->setText("[" + strVector + "]");
}

void MainWindow::printB() {
    ui->label_3->clear();
    QString strVector = "";

    for (int i = 0; i < (int)b.size(); i++) {
        strVector += QString::number(b[i]);

        if (i != (int)b.size() - 1) {
            strVector += ", ";
        }
    }

    ui->label_3->setText(strVector);
}


void MainWindow::on_pushButton_2_clicked()
{
    std::vector<int> a;
    int count = 0;

    for (int i = 0; i < (int)v.size(); i++) {
        a.push_back(v[i]);
        count++;

        if (count == 3) {
            std::sort(a.begin(), a.end());
            b.push_back(a[1]);
            a.clear();
            count = 0;
        }
    }

    if (a.size() != 0) {
        double sum = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            sum += a[i];
        }

        b.push_back(sum/a.size());
    }

    printB();
    b.clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    v.clear();
    printV();
}

void MainWindow::on_pushButton_4_clicked()
{
    v.clear();
    int count = ui->spinBox_2->value();
    for (int i = 0; i < count; i++) {
        v.push_back(QRandomGenerator::global()->bounded(0, 100));
    }
    printV();
}

