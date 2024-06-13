#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setInputMask("000");
    ui->IndexEdit->setInputMask("00");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Push_Back_clicked()
{
    int item = ui->lineEdit->text().toInt();

    deque.push_back(item);

    ui->label->setText(Print());
}

QString MainWindow::Print()
{
    QString Line = "";

    int c = 0;
    DequeIterator<int> it = deque.begin();
    for(; it != deque.end(); ++it){
        if(it == deque.begin()){
            c++;
            if(c == 2){
                break;
            }
        }

        Line += QString::number(*it) + " ";
    }

    return Line;
}


void MainWindow::on_Push_front_clicked()
{
    int item = ui->lineEdit->text().toInt();

    deque.push_front(item);

    ui->label->setText(Print());
}


void MainWindow::on_PopBack_clicked()
{
    deque.pop_back();

    ui->label->setText(Print());
}


void MainWindow::on_Pop_Front_clicked()
{
    deque.pop_front();

    ui->label->setText(Print());
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << deque[0];
}


void MainWindow::on_Clear_clicked()
{
    deque.clear();

    ui->label->setText(Print());
}


void MainWindow::on_Size_clicked()
{
    int a = deque.size();

    ui->Size_label->setNum(a);
}


void MainWindow::on_Empty_clicked()
{
    if(deque.empty()){
        ui->Empty_label->setText("True");
    }
    else{
        ui->Empty_label->setText("False");
    }
}


void MainWindow::on_Index_clicked()
{
    int index = ui->IndexEdit->text().toInt();

    ui->Index_Label->setNum(deque.at(index));
}

