#include "mainwindow.h"
#include "ui_mainwindow.h"
#define er QMessageBox::warning(this,"Error", "This key doesn't exist in this container")
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gen.seed(time(NULL));

    for(int i=0;i<10;i++)
    {
        s.insert(i*i);
        m.insert(i,(i+1)*(1+i)*(i+1));
        //qDebug()<<i*i*i;
    }

    upd();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::upd()
{
    ui->sc->clear();
    ui->sc_2->clear();
    QString text = "";
    if(s.size()!=0)
    for (auto& el : s) {
        text += QString::number(el.key) + "\n";
    }
    ui->textBrowser->setText(text);
    text = "";
    if(m.size()!=0)
    for (auto& el : m) {
        text += QString::number(el.key) + "; "+QString::number(el.val)+ "\n";
    }
    ui->textBrowser_2->setText(text);
}

void MainWindow::on_pushButton_clicked()
{
    // if(!s.contains(ui->spinBox->value()))
    s.insert(ui->spinBox->value());
    // else
    //     QMessageBox::warning(this,"Error", "This key already exist in this container");
    upd();
}


void MainWindow::on_pushButton_2_clicked()
{
    // if(s.contains(ui->spinBox->value()))
    s.remove(ui->spinBox->value());
    // else
    //     er;
    upd();
}





void MainWindow::on_pushButton_4_clicked()
{
    if(s.contains(ui->spinBox->value()))
    {
        ui->sc->setText("Yes");
    }
    else
        ui->sc->setText("No");
}


void MainWindow::on_pushButton_7_clicked()
{
    //if(!m.contains(ui->spinBox->value()))
    qDebug()<<ui->spinBox_2->value();
        m.insert(ui->spinBox_2->value(),ui->spinBox_3->value());
    //else
      //  QMessageBox::warning(this,"Error", "This key already exist in this container");
    upd();
}


void MainWindow::on_pushButton_5_clicked()
{
    //if(m.contains(ui->spinBox->value()))
        m.remove(ui->spinBox_2->value());
    // else
    //     er;
    upd();
}



void MainWindow::on_pushButton_6_clicked()
{
    if(m.contains(ui->spinBox->value()))
    {
        ui->sc_2->setText("Yes");
    }
    else
        ui->sc_2->setText("No");
}

