#include "mainwindow.h"
#include "ui_mainwindow.h"

#define er QMessageBox::warning(this,"Error","Incorrect input")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    b=new bitset(1);
    ui->setupUi(this);
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    ui->textBrowser->clear();
    ui->bits->setPlainText(QString::fromStdString(b->to_string()));
}

bool MainWindow::get_ch()
{
    std::string s=ui->lineEdit->text().toStdString();

    if(s=="")
        return false;

    for(int i=0;i<s.size();i++)
    {
        if(!(s[i]>='0'&&s[i]<='9'))
            return false;
    }

    try
    {
        ch=stoi(s);
    }
    catch(...)
    {
        return false;
    }
    return true;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->setPlainText(b->all()==1? "All 1" : "Not all 1");
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->setPlainText(b->any()==1? "Have 1" : "Have not 1");
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->textBrowser->setPlainText(QString::fromStdString(std::to_string(b->count())));
}


void MainWindow::on_pushButton_4_clicked()
{
    b->flip();
    update();
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->textBrowser->setPlainText(b->none()==1? "No 1" : "Have 1");
}


void MainWindow::on_pushButton_9_clicked()
{
    if(!get_ch()||ch<0||ch>=b->size())
    {
        er;
        return;
    }

    ui->textBrowser->setPlainText(b->test(ch)==1? "1" : "0");
}


void MainWindow::on_pushButton_6_clicked()
{
    if(ui->lineEdit->text()=="")
    {
        b->reset();
        update();
        return;
    }
    if(!get_ch()||ch<0||ch>=b->size())
    {
        er;
        return;
    }

    b->reset(ch);
    update();
}


void MainWindow::on_pushButton_7_clicked()
{
    if(ui->lineEdit->text()=="")
    {
        b->set();
        update();
        return;
    }
    if(!get_ch()||ch<0||ch>=b->size())
    {
        er;
        return;
    }

    b->set(ch);
    update();
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->textBrowser->setPlainText(QString::fromStdString(std::to_string(b->size())));
}


void MainWindow::on_pushButton_10_clicked()
{
    if(!get_ch()||ch<0)
    {
        er;
        return;
    }
    b->resize(ch);
    update();
}

