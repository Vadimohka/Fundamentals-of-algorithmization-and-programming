#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cmath>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->doubleSpinBox->setMaximum(1e308);
     ui->doubleSpinBox->setMinimum(-1e308);
    ui->doubleSpinBox->setValue(0);
     ui->doubleSpinBox->clear();
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::create(){
    QString a=ui->doubleSpinBox->text();
    double t=ui->doubleSpinBox->value();
    QChar k=a[0];
    if(t==0){
        ui->lineEdit_3->setText(QString::number(0));
        ui->lineEdit_2->setText(QString::number(0));
        ui->lineEdit->setText(QString::number(0));
        ui->lineEdit_4->setText(QString::number(0));
        ui->lineEdit_5->setText(QString::number(0));

    }
    else {
         double tt=t;
        if(t>10){
        t=to_binary->get_normalized(std::abs(t));
        }
        else {
            t=to_binary->get_normalized1(std::abs(t));
        }
        std::string kk=(to_binary->convert_c(floor(std::abs(t)))).toStdString();
       std::reverse(kk.begin(),kk.end());
        QString kkk=QString::fromStdString(kk);
       QString h=kkk+to_binary->convert_ch(std::abs(t)-floor(std::abs(t)));

        if(floor(std::abs(tt))==0){
           if(h.size()>52){
               h.resize(52);
           }
           if(h=="1" || tt<-1e15) h="0000000000000000000000000000000000000000000000000000";
            ui->lineEdit_5->setText(h);
           if(tt==-1e307){
                ui->lineEdit_5->setText("10");
           }
           else if(tt==-1e308){
               ui->lineEdit_5->setText("1");
           }
           else {
           double step=log10(std::abs(tt)/to_binary->get_normalized1(t));
           std::string kkl=(to_binary->convert_c((int)((step)*log2(10)+1023))).toStdString();
           std::reverse(kkl.begin(),kkl.end());
           QString kkkl=QString::fromStdString(kkl);
           ui->lineEdit_4->setText(kkkl);
           }
        }
       else {
           if(h.size()>52){
               h.resize(52);
           }
           double step=log10(std::abs(tt));

           ui->lineEdit_5->setText(h);
           std::string kkl=(to_binary->convert_c((int)(step*log2(10)+1024))).toStdString();
           std::reverse(kkl.begin(),kkl.end());
           QString kkkl=QString::fromStdString(kkl);
           ui->lineEdit_4->setText(kkkl);
       }
    ui->lineEdit_3->setText(to_binary->get_first_bit(k));
    if(std::abs(t)>1){
        ui->lineEdit->setText(QString::number(1/std::abs(tt)));
    }
    else {
        ui->lineEdit->setText(QString::number(std::abs(tt)));
    }
    ui->lineEdit_2->setText("1");
    }
}

void MainWindow::on_doubleSpinBox_textChanged(const QString &arg1)
{

    create();

}
