#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::outputVec(MyVec<int> &v)
{
    for (int i = 0; i < (int)v.size(); ++i)
    {
        str += QString::number(v.at(i)) + "  ";
    }
    ui->listWidget->addItem(str);
    str.clear();
}

void MainWindow::on_firstPushBtn_clicked()
{
    int a = ui->pushBox->value();
    vec.push_back(a);
    outputVec(vec);
}

void MainWindow::on_popBackBtn_clicked()
{
    if(vec.empty())
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input!");
        return;
    }
    vec.pop_back();
    outputVec(vec);
}

void MainWindow::on_clearBtn_clicked()
{
    vec.clear();
    outputVec(vec);
}

void MainWindow::on_secondInsertBtn_clicked()
{
    int pos = ui->secondIntBox->value();

    if(pos > (int)vec.size())
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input!");
        return;
    }
    int n = ui->secondDblBox->value();
    vec.insert(vec.begin() + pos,n);
    outputVec(vec);
}

void MainWindow::on_pushButton_clicked()
{
    vec.clear();
    for (int i = 0; i < 10; ++i)
    {
        vec.push_back(QRandomGenerator::global()->bounded(0,100));
    }
    outputVec(vec);
}
