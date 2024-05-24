#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mystring.h"

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

void MainWindow::on_FirstString_returnPressed()
{
    QString str = ui->FirstString->text();
    if(str.length() != 0)
        str_1 = str;
}

void MainWindow::on_SecondString_returnPressed()
{
    QString str = ui->SecondString->text();
    if(str.length() != 0)
        str_2 = str;
}


void MainWindow::on_Btn_memcpy_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());

    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox->value();
        MyString::memcpy(nonConstStr,str_2.c_str(),n);
    }
    ui->output->clear();
    ui->output->setText(nonConstStr);
}

void MainWindow::on_Btn_memmove_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());

    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox->value();
        MyString::memmove(nonConstStr,str_2.c_str(),n);
    }
    ui->output->clear();
    ui->output->setText(nonConstStr);
}


void MainWindow::on_Btn_strcpy_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());

    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox->value();
        MyString::strcpy(nonConstStr,str_2.c_str());
    }
    ui->output->clear();
    ui->output->setText(nonConstStr);
}


void MainWindow::on_Btn_strcmp_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());
    int t = 0;
    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox->value();
       t = MyString::strcmp(str_1.c_str(),str_2.c_str());
    }
    ui->output->clear();
    ui->output->setText(QString::number(t));
}


void MainWindow::on_Btn_strncmp_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());
    int t = 0;
    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox->value();
        t = MyString::strncmp(str_1.c_str(),str_2.c_str(),n);
    }
    ui->output->clear();
    ui->output->setText(QString::number(t));
}


void MainWindow::on_Btn_strncpy_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());

    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox->value();
        MyString::strncpy(nonConstStr,str_2.c_str(),n);
    }
    ui->output->clear();
    ui->output->setText(nonConstStr);
}


void MainWindow::on_Btn_strcat_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());

    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox->value();
        MyString::strcat(nonConstStr,str_2.c_str());
    }
    ui->output->clear();
    ui->output->setText(nonConstStr);
}


void MainWindow::on_Btn_memcmp_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());

    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox->value();
        MyString::memcmp(nonConstStr,str_2.c_str(),n);
    }
    ui->output->clear();
    ui->output->setText(nonConstStr);
}


void MainWindow::on_Btn_strcoll_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());
    int t = 0;
    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox->value();
        t = MyString::strcoll(str_1.c_str(),str_2.c_str());
    }
    ui->output->clear();
    ui->output->setText(QString::number(t));
}


void MainWindow::on_Btn_strtok_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());

    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox->value();
        ui->output->clear();
        ui->output->setText(MyString::strtok(nonConstStr," "));
    }
}


void MainWindow::on_Btn_strerror_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());

    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox_2->value();
        ui->output->clear();
        ui->output->setText(MyString::strerror(n));
    }
}


void MainWindow::on_Btn_strxfrm_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());

    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox_2->value();
        MyString::strxfrm(nonConstStr,str_2.c_str(),n);
    }
    ui->output->clear();
    ui->output->setText(nonConstStr);
}


void MainWindow::on_Btn_memset_clicked()
{
    char* nonConstStr = const_cast<char*>(str_1.c_str());

    if(str_1.length() != 0 && str_2.length() !=0)
    {
        int n = ui->spinBox_2->value();
        MyString::memset(nonConstStr,n,n);
    }

    ui->output->clear();
    ui->output->setText(nonConstStr);
}


void MainWindow::on_Btn_strLen1_clicked()
{
    int size = strlen(str_1.c_str());
    ui->output->clear();
    ui->output->setText(QString::number(size));
}


void MainWindow::on_Btn_strLen1_2_clicked()
{
    int size = strlen(str_2.c_str());
    ui->output->clear();
    ui->output->setText(QString::number(size));
}

