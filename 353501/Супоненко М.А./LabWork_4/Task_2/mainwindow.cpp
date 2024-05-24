#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QTimer>
#include "RectArray.h"
#include <QElapsedTimer>
#include <QTableWidgetItem>

MainWindow::MainWindow()
    : ui(new Ui::MainWindow), scene(new QGraphicsScene(this)), timer(new QTimer())
{
    ui->setupUi(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    scene->setSceneRect(0, -500, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);

    timer->start(500);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateScene);

    array = new RectArray();
    scene->addItem(array);
    array->width = ui->graphicsView->width() - 20;
    array->height = ui->graphicsView->height() - 20;

    sortType = 0;
    numberToSearch = 0;

    ui->tableWidget->setColumnCount(3);
    cnt = 1;
    number = 1;

    ui->spinBox->setValue(100);
    ui->spinBox_3->setValue(1000007);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if (array->allowUpdateNumber)
    {
        array->number = arg1;
        number = arg1;
        array->updateNumber();
    }
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    numberToSearch = arg1;
}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    mod = arg1;
}

void MainWindow::on_refresh_clicked()
{
    array->updateNumber();
}

void MainWindow::on_search_clicked()
{
    if (isSearching)
    {
        isSearching = false;
        if (array->isSorted())
        {
            int tmp = array->binarySearch(numberToSearch);
            ui->label_2->setText(QString::number(tmp));
            ui->label_3->setText(QString::number(binpow(tmp, number, mod)));
        }
        else
        {
            ui->label_2->setText("Array not sorted yet.");
            ui->label_3->setText("Array not sorted yet.");
        }
        isSearching = true;
    }
}

void MainWindow::on_sort_clicked()
{
    if (sortAllowed)
    {
        sortAllowed = false;

        QElapsedTimer timer;
        timer.start();
        ui->tableWidget->setRowCount(cnt);
        QTableWidgetItem *itm = new QTableWidgetItem(QString::number(number));
        ui->tableWidget->setItem(cnt - 1, 1, itm);
        ui->tableWidget->scrollToBottom();

        QString sortTypeName;
        switch (sortType)
        {
            case 0:
                sortTypeName = "Heap";
                array->heapSorting();
                break;
            case 1:
                sortTypeName = "Quick";
                array->quickSorting();
                break;
            case 2:
                sortTypeName = "Merge";
                array->mergeSorting();
                break;
            case 3:
                sortTypeName = "Interpolation";
                array->interpolationSorting();
                break;
            default:
                break;
        }

        itm = new QTableWidgetItem(sortTypeName);
        ui->tableWidget->setItem(cnt - 1, 0, itm);

        ui->tableWidget->scrollToBottom();

        itm = new QTableWidgetItem(QString::number(timer.elapsed()));
        ui->tableWidget->setItem(cnt - 1, 2, itm);

        ui->tableWidget->scrollToBottom();

        cnt++;
        sortAllowed = true;
    }
}

void MainWindow::updateScene()
{
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    sortType = index;
}

long long MainWindow::binpow(int digit, int powder, int mod)
{
    if (powder == 0)
    {
        return 1;
    }
    if (powder % 2 == 1)
    {
        return (binpow(digit, powder - 1, mod) * digit) % mod;
    }
    else
    {
        long long halfPow = binpow(digit, powder / 2, mod);
        return (halfPow * halfPow) % mod;
    }
}
