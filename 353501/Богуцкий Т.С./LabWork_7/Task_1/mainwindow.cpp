#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    queueMain.createQueue(150);
    ui->beginLabel->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->EndLabel->setStyleSheet("QLabel { background-color : red; color : black; }");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString str;
    bool ok;
    str = ui->lineEdit->text();
    int element = str.toInt(&ok);

    if (ok){
        if (queueMain.IsFull())
        {
            ui->pushButton->setEnabled(false);
            ui->lineEdit->setText("Очередь переполнена!");
            ui->lineEdit->setEnabled(false);
        }
        queueMain.addElement(element);
        ui->textBrowser->setText(queueMain.print());
    }
    ui->lineEdit->clear();

}

void MainWindow::on_pushButton_5_clicked()
{    
    if (ui->textBrowser->toPlainText().isEmpty()){
        ui->textBrowser->setText("Очередь является пустой");
        return;
    }

    if (queueMain.IsFull()){
        ui->textBrowser->setText("Очередь является полной");
    }
    else if (queueMain.IsEmpty()){
        ui->textBrowser->setText("Очередь является пустой");
    }
    else{
        ui->textBrowser->setText("Очередь НЕ является пустой");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->textBrowser->setText(queueMain.print());
}


void MainWindow::on_EraseElement_clicked()
{
    queueMain.deleteElement();
    ui->textBrowser->setText(queueMain.print());
}


void MainWindow::on_ShowFirst_clicked()
{
    ui->textBrowser->setText(QString::number(queueMain.ShowFirst()));
}


void MainWindow::on_ShowSecond_clicked()
{
    ui->textBrowser->setText(QString::number(queueMain.ShowLast()));
}


void MainWindow::on_Queue1Button_clicked()
{
    QString str;
    bool ok;
    str = ui->line1QUEUE->text();
    int size = str.toInt(&ok);

    if (ok && size >= 1){
        queue1.createQueue(size);
        queue1.makeRandom();
        ui->textBrowser_4->clear();
        ui->textBrowser_2->setText(queue1.print());
    }
}

void MainWindow::on_solveTask_clicked()
{
    QString str1 = queue1.print();

    int Array1[50];
    for (int i =0; i < 50; i++){
        Array1[i] = 0;
    }

    QString helpstr1;
    int helpint1, counter1 = 0;
    for (int i = 0; i < str1.size() ; i++){
        if (str1[i] != " " && str1[i] != "0"){
            helpstr1 += str1[i];
            if (i == str1.size()-1){
                helpint1 = helpstr1.toInt();
                Array1[counter1] = helpint1;
            }
        }
        else{
            helpint1 = helpstr1.toInt();
            Array1[counter1] = helpint1;
            counter1++;
            helpstr1 = nullptr;
        }
    }
    int max = 0, index = 0, counter = 0;;
    for (int i =0; i < 50; i++){
        if (Array1[i] > max) max = Array1[i];
        if (Array1[i] != 0) counter++;
    }

    additional.createQueue(counter);
    additional.addElement(max);
    for (int i =0; i < 50; i++){
        if (Array1[i] != 0 && Array1[i] != max) additional.addElement(Array1[i]);
    }
    ui->textBrowser_4->setText(additional.print());


}

