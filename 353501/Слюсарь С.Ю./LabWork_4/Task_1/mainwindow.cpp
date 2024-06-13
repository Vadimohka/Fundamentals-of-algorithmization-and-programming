#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[1-9]{7}"),this));

    for (int i = 0; i < 50; ++i)
    {
        arr[i] = rg->bounded(1, 450);
    }
    sorter = new Sorter(arr, 50);
    scene->addItem(sorter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sort_clicked()
{
    if (!done)
    {
        QElapsedTimer timer;
        switch (numOfSort)
        {
        case 0:
            timer.start();
            sorter->heapSort(50);
            ui->label->setText("Время работы - " + QString::number(timer.elapsed() / 1000.0));
            break;
        case 1:
            timer.start();
            sorter->mergeSort(0, 50);
            ui->label->setText("Время работы - " + QString::number(timer.elapsed() / 1000.0));
                break;
        case 2:
            timer.start();
            sorter->quickSort(0, 50);
            ui->label->setText("Время работы - " + QString::number(timer.elapsed() / 1000.0));
            break;
        }
        done = true;
    }
    else
    {
        ui->num->setText("Массив отсортирован");
    }
}


void MainWindow::on_comboBox_activated(int index)
{
    ui->label->clear();
    numOfSort = index;
    for (int i = 0; i < 50; ++i)
    {
        arr[i] = rg->bounded(1, 450);
    }
    sorter = new Sorter(arr, 50);
    scene->addItem(sorter);
    done = false;
}


void MainWindow::on_pushButton_clicked()
{
    if (done && !ui->lineEdit->text().isEmpty())
    {
        int num = ui->lineEdit->text().toInt();
        int pos = sorter->binSearch(50, num);
        if (pos == -1)
        {
            ui->num->setText("В массиве нет этого элемента");
        }
        else
        {
            ui->num->setText("Номер элемента - " + QString::number(pos));
        }
    }
    else if (ui->lineEdit->text().isEmpty())
    {
        ui->num->setText("Неверный ввод");
    }
    else
    {
        ui->num->setText("Сначала отсортируйте массив");
    }
}
