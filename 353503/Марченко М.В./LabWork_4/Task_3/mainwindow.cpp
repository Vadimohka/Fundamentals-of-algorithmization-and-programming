#include "mainwindow.h"
#include "ui_mainwindow.h"

const int LIMITOFSIZE = 100;

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

void MainWindow::GenerateArray(std::vector<int> &arr)
{
    srand(time(0));

    for(auto index{0}; index < size; ++index)
    {
        arr[index] = rand() % LIMITOFSIZE;
    }
}

void MainWindow::PrintArray(const std::vector<int> &arr)
{
    for(auto index{0}; index < arr.size(); ++index)
    {
        Output += QString().setNum(arr[index]) + " ";
    }

    ui->TE_Generated->setText(Output);
}

void MainWindow::PrintArray_(const std::vector<int> &arr)
{
    for(auto index{0}; index < arr.size(); ++index)
    {
        Result += QString().setNum(arr[index]) + " ";
    }

    ui->TE_Result->setText(Result);
}

void MainWindow::FillMedian(const std::vector<int> &arr)
{
    for(int index{0}; index < size; index += 3){
        std::vector<int> temp(3);
        int amount = 0;

        for(int j{0}; j < 3; ++j)
        {
            if(j + index < size)
            {
                temp[j] = arr[index + j];
                amount++;
            }
            else{
                break;
            }
        }

        if(amount != 3){
            if(amount == 1){
                temp[2] = temp[3] = temp[1];
            }
            else if(amount == 2){
                temp[3] = (temp[1] + temp[2]) / 2;
            }
        }

        int min = temp[0];
        int max = temp[0];

        for(int i = 0; i < 3; ++i)
        {
            if(temp[i] > max){
                max = temp[i];
            }
            if(temp[i] < min){
                min = temp[i];
            }
        }

        if(min != temp[0] && temp[0] != max){
            temp[1] = temp[0];
            temp[0] = min;
            temp[2] = max;
        }
        if(min == temp[0] && max != temp[2]){
            temp[1] = temp[2];
            temp[2] = max;
        }
        if(min != temp[0] && max == temp[2]){
            temp[1] = temp[0];
            temp[0] = min;
        }

        mediana.push_back(temp[1]);
    }
}

void MainWindow::on_SizeButton_clicked()
{
    Output = "";
    Result = "";

    mediana.resize(0);

    ui->TE_Generated->clear();
    ui->TE_Result->clear();

    size = ui->lineSize->text().toInt();

    if(!size)
    {
        return;
    }

    array.resize(size);
    GenerateArray(array);
    PrintArray(array);

    FillMedian(array);
    PrintArray_(mediana);
}
