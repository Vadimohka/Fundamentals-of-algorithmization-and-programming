#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->spinBox->setRange(-100000, 100000);
    ui->spinBox_2->setRange(-100000, 100000);

    for(int i = 0; i < 10; i++)
    {
        a.push_back(i);
        ui->listWidget->addItem(new QListWidgetItem("  " + QString::number(a[i]) + "  "));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    int n = ui->spinBox->value();
    if(n < a.size() && n >=0)
        ui->textBrowser->append(QString::number(a.at(n)));
    else
        ui->textBrowser->append("err");
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
    a.clear();
    ui->listWidget->clear();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->textBrowser->clear();
    ui->textBrowser->append(QString::number(a.capacity()));
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->clear();
    ui->textBrowser->append(QString("0x%1").arg(reinterpret_cast<quintptr>(a.data()), QT_POINTER_SIZE * 2, 16, QChar('0')));
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->textBrowser->clear();
    int n = ui->spinBox->value();
    if(n < a.size() && n >=0 && a.size()!=0){
        a.erase(a.begin() + n);
        ui->listWidget->takeItem(n);
        qDebug()<<a.size();
    }
    else
        ui->textBrowser->append("err");
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->textBrowser->clear();
    if( a.size()!=0){
        a.pop_back();
        ui->listWidget->takeItem(ui->listWidget->count() - 1);
        qDebug()<<a.size();
    }
    else
        ui->textBrowser->append("err");
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->textBrowser->clear();
    int n = ui->spinBox->value();

    a.push_back(n);
    ui->listWidget->addItem(new QListWidgetItem("  " + QString::number(n) + "  "));
    qDebug()<<a.size();

}


void MainWindow::on_pushButton_9_clicked()
{
    ui->textBrowser->clear();
    ui->textBrowser->append(QString::number(a.size()));
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->textBrowser->clear();
    ui->listWidget->clear();
    int n = ui->spinBox->value();

    if(n >= 0){
        a.resize(n);
        for(int i = 0; i < a.size(); i++)
        {
            ui->listWidget->addItem(new QListWidgetItem("  " + QString::number(a[i]) + "  "));
        }
        qDebug()<<a.size();
    }
    else
        ui->textBrowser->append("err");
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->textBrowser->clear();
    ui->listWidget->clear();
    int n = ui->spinBox->value();
    int l = ui->spinBox_2->value();
    if(l>= 0 && l <=a.size()){
        a.insert(l , n);
        for(int i = 0; i < a.size(); i++)
        {
            ui->listWidget->addItem(new QListWidgetItem("  " + QString::number(a[i]) + "  "));
        }
        qDebug()<<a.size();
    }
    else
        ui->textBrowser->append("err");
}


void MainWindow::on_pushButton_11_clicked()
{

}
