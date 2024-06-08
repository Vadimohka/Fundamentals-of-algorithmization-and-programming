#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gen.seed(time(NULL));
    table=new mht(8000);
    size=table->size();
    ui->tableWidget->setRowCount(size);
    for(int i=0;i<table->size();i++)
    {
        table->insert(i,gen());
        table->insert(i,gen());
        names2.push_back(QString::number(i));
        //names.push_back("Value "+QString::number(i+1));
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->tableWidget->setHorizontalHeaderLabels(names);
    ui->tableWidget->setVerticalHeaderLabels(names2);
    //int i=names.size();
    //qDebug()<<i;
    showTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTable()
{
    //QVector<stack<int>> t=table->getTable();

    ui->tableWidget->clear();

    ui->tableWidget->setHorizontalHeaderLabels(names);
    ui->tableWidget->setVerticalHeaderLabels(names2);
    int col=0;

    for(int i=0;i<size;i++)
        col=std::max((long long)col,table->at(i).size());

    if(col==0)return;
    if(ui->tableWidget->columnCount()!=col)
        ui->tableWidget->setColumnCount(col);




    //names.push_back("Key");
    if(names.size()<=col)
    {
        for(int i=names.size();i<=col;i++)
        {
            names.push_back("Value "+QString::number(i+1));
        }
        ui->tableWidget->setHorizontalHeaderLabels(names);
    }
    //names.clear();
    for(int i=0;i<table->size();i++)
    {
        QVector<int> st=table->at(i).to_QVec();
        int j=0;
        for(auto& v:st)
        {
            QTableWidgetItem *it=new QTableWidgetItem ();
            it->setTextAlignment(Qt::AlignCenter);
            it->setText(QString::fromStdString(std::to_string(v)));
            ui->tableWidget->setItem(i,j,it);
            j++;
            //t[i].pop();
        }

    }


}

bool MainWindow::check_key()
{
    std::string s=ui->textEdit->toPlainText().toStdString();
    for(auto& i:s)
    {
        if(!(i>='0'&&i<='9'))
            return false;
    }
    try
    {
        key=stoi(s);
    }catch(...)
    {
        return false;
    }

    if(key<0)
        return false;
    return true;
}

bool MainWindow::check_value()
{
    std::string s=ui->textEdit_2->toPlainText().toStdString();
    for(auto& i:s)
    {
        //qDebug()<<i;
        if(!(i>='0'&&i<='9'))
            return false;
    }
    try
    {
        value=stoi(s);
    }catch(...)
    {
        return false;
    }
    return true;
}



void MainWindow::on_pushButton_clicked()
{
    table->solveTask();
    showTable();
}


void MainWindow::on_pushButton_3_clicked()
{
    if(check_key())
    {
        table->remove(key);
    }
    else
        QMessageBox::warning(this,"Error","Wrong input. Value should be int");
    showTable();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(check_key()&&check_value())
    {
        table->insert(key,value);
    }
    else
        QMessageBox::warning(this,"Error","Wrong input. Key should be int and > 0. Value should be int");
    showTable();
}
