#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), showRing(nullptr)
{
    ui->setupUi(this);
    ui->pushButton_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addElements()
{
    beginRing.clear();
    ui->textEdit->clear();
    int size = ui->spinBox->value();
    for (int var = 0; var < size; ++var) {
        int num = QRandomGenerator::global()->bounded(1000);
        beginRing.pushback(num);
        ui->textEdit->append(QString::number(num) + ' ');
    }
    showRing = beginRing.begin();
}

void MainWindow::makeRings()
{
    if(beginRing.empty()) return;

    else{
        firstRing.clear();
        secondRing.clear();
        indexofmax = 0;
        indexofmin = 0;
        int index = 0;
        int minValue = *beginRing.begin();
        int maxValue = *beginRing.begin();
        for (int & it : beginRing) {
            if (it < minValue) {
                minValue = it;
                indexofmin = index;
            }
            if (it > maxValue) {
                maxValue = it;
                indexofmax = index;
            }
            ++index;
        }
        if(beginRing.size() != 0){
            auto it = beginRing.end();
            if (*it < minValue) {
                minValue = *it;
                indexofmin = index;
            }
            if (*it > maxValue) {
                maxValue = *it;
                indexofmax = index;
            }
        }

        index = 0;
        if(indexofmin > indexofmax){
            std::swap(indexofmax, indexofmin);
        }
        for (auto it = beginRing.begin(); it != beginRing.end(); ++it) {
            if(index >= indexofmin and index <= indexofmax){
                firstRing.pushback(*it);
            }
            else{
                secondRing.pushback(*it);
            }

            ++index;
        }
        auto it = beginRing.end();
        if(index >= indexofmin and index <= indexofmax){
            firstRing.pushback(*it);
        }
        else{
            secondRing.pushback(*it);
        }
        index = 0;
    }
}

void MainWindow::showtime()
{
    makeRings();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();

    for (auto it = firstRing.begin(); it != firstRing.end(); ++it) {
        ui->textEdit_2->append(QString::number(*it));
    }
    if(firstRing.size() != 0){
        auto it = firstRing.end();
        ui->textEdit_2->append(QString::number(*it));
    }

    for (auto it = secondRing.begin(); it != secondRing.end(); ++it) {
        ui->textEdit_3->append(QString::number(*it));
    }
    if(secondRing.size() != 0){
        auto it = secondRing.end();
        ui->textEdit_3->append(QString::number(*it));
    }
}

void MainWindow::on_pushButton_clicked()
{
    valid = false;
    addElements();
    showtime();
    ui->pushButton_2->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(!valid){
        showRing = beginRing.begin();
        valid = true;
    }
    ui->label_5->setText(QString::number(*showRing));
    ++showRing;
}
