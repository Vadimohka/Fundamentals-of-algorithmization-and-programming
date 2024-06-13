#include "mainwindow.h"
#include "./ui_mainwindow.h"

//I am booored
const int64_t MAX_SIZE = 20;
const int64_t MAX_VALUE = 10;

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

void MainWindow::on_pushButton_clicked()
{
    int64_t seed = ui->textEdit_4->toPlainText().toInt();

    std::mt19937 rng(seed);


    {
        int64_t size = rng()%MAX_SIZE + 1;

        int64_t* arr = new int64_t[size];

        for (int i = 0;i<size;i++)
        {
            arr[i] = rng()%MAX_VALUE + 1;
        }

        Sorter::HeapSort(arr, size);

        QString text = "";

        for (int i = 0;i<size;i++)
        {
            text.append(QString::number(arr[i]));
            text.append(' ');
        }

        int64_t valueToFind = rng()%MAX_VALUE + 1;

        text.append('\n');
        text.append(QString::number(valueToFind));
        text.append(" : ");
        text.append(QString::number(Algorithms::BinSearch(arr, size, valueToFind)));

        ui->textEdit->setPlainText(text);

        delete[] arr;
    }

    {
        int64_t size = rng()%MAX_SIZE + 1;

        int64_t* arr = new int64_t[size];

        for (int i = 0;i<size;i++)
        {
            arr[i] = rng()%MAX_VALUE + 1;
        }

        Sorter::QuickSort(arr, size);

        QString text = "";

        for (int i = 0;i<size;i++)
        {
            text.append(QString::number(arr[i]));
            text.append(' ');
        }

        int64_t valueToFind = rng()%MAX_VALUE + 1;

        text.append('\n');
        text.append(QString::number(valueToFind));
        text.append(" : ");
        text.append(QString::number(Algorithms::BinSearch(arr, size, valueToFind)));

        ui->textEdit_2->setPlainText(text);

        delete[] arr;
    }

    {
        int64_t size = rng()%MAX_SIZE + 1;

        int64_t* arr = new int64_t[size];

        for (int i = 0;i<size;i++)
        {
            arr[i] = rng()%MAX_VALUE + 1;
        }

        Sorter::MergeSort(arr, size);

        QString text = "";

        for (int i = 0;i<size;i++)
        {
            text.append(QString::number(arr[i]));
            text.append(' ');
        }

        int64_t valueToFind = rng()%MAX_VALUE + 1;

        text.append('\n');
        text.append(QString::number(valueToFind));
        text.append(" : ");
        text.append(QString::number(Algorithms::BinSearch(arr, size, valueToFind)));

        ui->textEdit_3->setPlainText(text);

        delete[] arr;
    }

    {
        int64_t size = rng()%MAX_SIZE + 1;

        int64_t* arr = new int64_t[size];

        for (int i = 0;i<size;i++)
        {
            arr[i] = rng()%MAX_VALUE + 1;
        }

        Sorter::InterpolationSort(arr, size);

        QString text = "";

        for (int i = 0;i<size;i++)
        {
            text.append(QString::number(arr[i]));
            text.append(' ');
        }

        int64_t valueToFind = rng()%MAX_VALUE + 1;

        text.append('\n');
        text.append(QString::number(valueToFind));
        text.append(" : ");
        text.append(QString::number(Algorithms::BinPower(Algorithms::BinSearch(arr, size, valueToFind), size, valueToFind)));

        ui->textEdit_5->setPlainText(text);

        delete[] arr;
    }

    {
        int64_t size = rng()%MAX_SIZE + 1;

        int64_t* arr = new int64_t[size];

        QString text = "";

        for (int i = 0;i<size;i++)
        {
            arr[i] = rng()%MAX_VALUE + 1;
        }

        for (int i = 0;i<size;i++)
        {
            text.append(QString::number(arr[i]));
            text.append(' ');
        }

        text.append('\n');

        int64_t* curr_pos = arr;

        for (int64_t i = 0;i<size;i+=3)
        {
            curr_pos+=3;
            if (i + 3 <= size)
            {
                Sorter::MergeSort(curr_pos, 3);
                text.append(QString::number(arr[i+1]));
                text.append(' ');
            }
            else
            {
                int64_t sum = 0, cnt = 0;

                while (i < size)
                {
                    sum += arr[i++];
                    cnt++;
                }

                text.append(QString::number(sum / cnt));
            }
        }

        ui->textEdit_6->setPlainText(text);

        delete[] arr;
    }
}
