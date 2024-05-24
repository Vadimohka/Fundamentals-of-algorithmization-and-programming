#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //calculateMedians();
    ui->label->setWordWrap(true);
    ui->label_3->setWordWrap(true);
    ui->pushButton->setDisabled(true);
    calculated = false;
    generated = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateMedians()
{
    int j = 0;
    int sum  = 0;
    for(int i = 0; i < a.size(); i++)
    {
        //count++;
        if(temp.size() != 3)
        {
            temp.push_back(a[i]);
            j++;
        }
        if(temp.size() == 3 || i == a.size() - 1)
        {
            j = 0;
            std::sort(temp.begin(), temp.end());

            if(temp.size() == 3)
            {
                b.push_back(temp[1]);

                temp.clear();
                //temp.push_back(a[i]);
            }
            else
            {
                for(int m = 0; m < temp.size(); m++)
                {
                    sum += temp[m];
                }
                b.push_back(sum/temp.size());

                sum = 0;
                temp.clear();
                //temp.push_back(a[i]);
            }
        }
    }

    calculated =true;
}

void MainWindow::on_pushButton_clicked()
{
    if(!calculated)
    {
        calculateMedians();
        QString string = "{";
        for (int i = 0; i < b.size(); i++) {
            string += QString::number(b[i]);
            string += ", ";
        }
        string.chop(2);
        string += "}";
        ui->label->setText(string);
        b.clear();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    sizeOfArray = ui->spinBox->text().toInt();
    a.resize(sizeOfArray);
    for(int i = 0; i < sizeOfArray; i++)
    {
        a[i] = QRandomGenerator::global()->bounded(100);
        //a.push_back(QRandomGenerator::global()->bounded(100));
    }
    printA();
    if(sizeOfArray != 0 )
    {
        ui->pushButton->setEnabled(true);
    }
    calculated = false;

}

void MainWindow::printA()
{
    //ui->label_3->setText("");
    QString string = "Массив: {";
    for (int i = 0; i < a.size(); i++) {
        string += QString::number(a[i]);
        string += ", ";
    }
    string.chop(2);
    if(sizeOfArray != 0)
    {
        string += "}";
        ui->label_3->setText(string);
    }
    generated = true;

}

