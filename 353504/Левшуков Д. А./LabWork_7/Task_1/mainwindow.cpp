#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->list->setEditTriggers(QAbstractItemView::NoEditTriggers);
/*
    q1.push(1);
    q1.push(2);
    q1.push(3);

    q2.push(4);
    q2.push(5);
    q2.push(6);
*/
    showQueue();

    gen.seed(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showQueue(int index_of_max)
{
    long long mx=q1.size();
    if(mx<q2.size())
    mx=q2.size();

    ui->list->clearContents();
    ui->list->setRowCount(mx);

    queue<int>temp;
    int i=0;
    while(!q1.empty())
    {
        temp.push(q1.front());
        QTableWidgetItem *it=new QTableWidgetItem ();
        it->setTextAlignment(Qt::AlignCenter);
        it->setText(QString::fromStdString(std::to_string(q1.front())));
        if(index_of_max==i)
        {
            it->setBackground(Qt::red);
        }
        ui->list->setItem(i,0,it);
        q1.pop();
        i++;
    }

    while(!temp.empty())
    {
        q1.push(temp.front());
        temp.pop();
    }

    i=0;
    while(!q2.empty())
    {
        temp.push(q2.front());
        QTableWidgetItem *it=new QTableWidgetItem ();
        it->setTextAlignment(Qt::AlignCenter);
        //qDebug()<<q2.front();
        it->setText(QString::fromStdString(std::to_string(q2.front())));
        ui->list->setItem(i,1,it);
        q2.pop();
        i++;
    }

    while(!temp.empty())
    {
        q2.push(temp.front());
        temp.pop();
    }


    ui->Back2->clear();
    ui->Back1->clear();
    ui->Front2->clear();
    ui->Front1->clear();
    if(q2.size()>0)
    ui->Back2->setText(QString::fromStdString(std::to_string(q2.back())));

    if(q1.size()>0)
    ui->Back1->setText(QString::fromStdString(std::to_string(q1.back())));

    if(q2.size()>0)
    ui->Front2->setText(QString::fromStdString(std::to_string(q2.front())));
    if(q1.size()>0)
    ui->Front1->setText(QString::fromStdString(std::to_string(q1.front())));

    ui->Size2->setText(QString::fromStdString(std::to_string(q2.size())));
    ui->Size1->setText(QString::fromStdString(std::to_string(q1.size())));

    if(q2.empty())
        ui->Empty2->setText("True");
    else
        ui->Empty2->setText("False");

        if(q1.empty())
        ui->Empty1->setText("True");
    else
        ui->Empty1->setText("False");
}

void MainWindow::on_gen1_clicked()
{
    while(!q1.empty())
        q1.pop();

    while(!q2.empty())
        q2.pop();

    int size=gen()%30+1;
    for(int i=0;i<size;i++)
    {
        q1.push(gen());
        q2.push(gen());
    }
    showQueue();
}


void MainWindow::on_pop_clicked()
{
    int num=ui->spinBox->value();
    if(num==1)
    {
        if(q1.size()==0)
        {
            QMessageBox::warning(this,"Error","Firstly you should add element");
        }
        else
            q1.pop();

    }
    else
    {
        if(q2.size()==0)
        {
            QMessageBox::warning(this,"Error","Firstly you should add element");
        }
        else
            q2.pop();
    }
    showQueue();
}


void MainWindow::on_push_clicked()
{
    int num=ui->spinBox->value();
    if(num==1)
    {
        q1.push(gen());

    }
    else
    {
        q2.push(gen());
    }
    showQueue();
}


void MainWindow::on_clear_clicked()
{
    int num=ui->spinBox->value();
    if(num==1)
    {
        q1.clear();

    }
    else
    {
        q2.clear();
    }
    showQueue();
}


void MainWindow::on_pushButton_clicked()
{
    if(q1.size()==0)
    {
        QMessageBox::warning(this,"Error","First queue is empty");
    }

    int i=0,mx=-INT_MIN,ind=0;
    queue<int>temp,temp2;
    while(!q1.empty())
    {
        temp.push(q1.front());
        if(q1.front()>mx)
        {
            ind=i;
            mx=q1.front();
        }
        //qDebug()<<q1.front()<<" "<<mx;
        q1.pop();
        i++;
    }
    i=ind+1;
    while(!temp.empty()&&i--)
    {
        q1.push(temp.front());
        temp.pop();
    }


    while(!q2.empty())
    {
        temp2.push(q2.front());
        q2.pop();
    }

    while(!temp2.empty())
    {
        q2.push(temp2.front());
        q1.push(temp2.front());
        temp2.pop();
    }
    while(!temp.empty())
    {
        q1.push(temp.front());
        temp.pop();
    }

    showQueue(ind);
}

