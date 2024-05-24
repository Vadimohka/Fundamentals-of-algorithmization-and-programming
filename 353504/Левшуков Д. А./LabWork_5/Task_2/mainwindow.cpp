#include "mainwindow.h"
#include "ui_mainwindow.h"

#define incor_n QMessageBox::warning(this,"Error","Incorrect n")

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

void MainWindow::update_textes()
{
    ui->s1->setText(QString::fromStdString(s1.data()));
    ui->s2->setText(QString::fromStdString(s2.data()));
    ui->result->setText("");
}

bool MainWindow::getn()
{
    std::string s=ui->textEdit_3->toPlainText().toStdString();

    if(s.size()==0)
    {
        incor_n;
        return false;
    }
    for(auto &i:s)
    {
        if(!(i>='0'&&i<='9'))
        {
            //qDebug()<<i<<" "<<(int)i;
            incor_n;
            return false;
        }
    }

    try
    {
        n=stoi(s);
    }
    catch(...)
    {
        incor_n;
        return false;
    }

    return true;
}

bool MainWindow::gets()
{
    std::string s=ui->textEdit_4->toPlainText().toStdString();
    if(s.size()==1)
        c=s[0];
    return s.size()==1;
}

void MainWindow::on_pushButton_clicked()
{
    s1=ui->textEdit->toPlainText().toStdString().c_str();
    update_textes();
}

void MainWindow::on_pushButton_2_clicked()
{
    s2=ui->textEdit_2->toPlainText().toStdString().c_str();
    update_textes();
}

void MainWindow::on_pushButton_3_clicked()
{
    update_textes();
    if(!getn())
    {
        return;
    }

    if(n==s2.size())
        n++;
    my_string::memcpy(s1.data(),s2.data(),n);

    //qDebug()<<s1.data();
    update_textes();
}

void MainWindow::on_pushButton_4_clicked()
{
    update_textes();
    if(!getn())
    {
        return;
    }

    if(n==s2.size())
        n++;
    my_string::memmove(s1.data(),s2.data(),n);

    update_textes();
}

void MainWindow::on_pushButton_5_clicked()
{
    my_string::strcpy(s1.data(),s2.data());
    update_textes();
}

void MainWindow::on_pushButton_6_clicked()
{
    update_textes();
    if(!getn())
    {
        return;
    }

    my_string::strncpy(s1.data(),s2.data(),n);
    update_textes();
}

void MainWindow::on_pushButton_7_clicked()
{
    my_string::strcat(s1.data(),s2.data());

    update_textes();
}

void MainWindow::on_pushButton_8_clicked()
{
    update_textes();
    if(!getn())
    {
        return;
    }

    my_string::strncat(s1.data(),s2.data(),n);
    update_textes();

}

void MainWindow::on_pushButton_9_clicked()
{
    update_textes();

    if(!getn())
    {
        return;
    }

    int r=my_string::memcmp(s1.data(),s2.data(),n);
    if(r==0)
        ui->result->setText("S1 = S2");
    if(r==1)
        ui->result->setText("S1 > S2");
    if(r==-1)
        ui->result->setText("S1 < S2");
}

void MainWindow::on_pushButton_10_clicked()
{
    update_textes();

    int r=my_string::strcmp(s1.data(),s2.data());
    if(r==0)
        ui->result->setText("S1 = S2");
    if(r==1)
        ui->result->setText("S1 > S2");
    if(r==-1)
        ui->result->setText("S1 < S2");
}

void MainWindow::on_pushButton_11_clicked()
{
    update_textes();

    int r=my_string::strcoll(s1.data(),s2.data());
    if(r==0)
        ui->result->setText("S1 = S2");
    if(r==1)
        ui->result->setText("S1 > S2");
    if(r==-1)
        ui->result->setText("S1 < S2");
}

void MainWindow::on_pushButton_12_clicked()
{
    update_textes();

    if(!getn())
    {
        return;
    }

    int r=my_string::strncmp(s1.data(),s2.data(),n);
    if(r==0)
        ui->result->setText("S1 = S2");
    if(r==1)
        ui->result->setText("S1 > S2");
    if(r==-1)
        ui->result->setText("S1 < S2");
}

void MainWindow::on_pushButton_13_clicked()
{
    update_textes();

    if(!getn())
    {
        return;
    }

    int r=my_string::strxfrm(s1.data(),s2.data(),n);

    ui->result->setText(QString::fromStdString(std::to_string(r)));
}

void MainWindow::on_pushButton_14_clicked()
{
    update_textes();

    if(!getn()||!gets())
        return;

    memset(s1.data(), c, n);

    update_textes();
}

void MainWindow::on_pushButton_15_clicked()
{
    std::string s="S1 size: "+std::to_string(my_string::strlen(s1.data()))+"\tS2: size"+std::to_string(my_string::strlen(s2.data()));
    ui->result->setText(QString::fromStdString(s));
}

