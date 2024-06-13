#include "mainwindow.h"
#include <QElapsedTimer>
#include <QGraphicsScene>
#include "Array.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTableWidgetItem>

MainWindow::MainWindow() : ui(new Ui::MainWindow), scene(new QGraphicsScene(this)), timer(new QTimer())
{
    ui->setupUi(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    scene->setSceneRect(0, -500, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);

    m_menu = new QMenu(ui->pushButton);
    m_menu->addAction("Heap sort");
    m_menu->addAction("Quick sort");
    m_menu->addAction("Merge sort");

    ui->pushButton->setMenu(m_menu);

    connect(m_menu->actions()[0], &QAction::triggered, this, &MainWindow::HeapSortFunction);
    connect(m_menu->actions()[1], &QAction::triggered, this, &MainWindow::QuickSortFunction);
    connect(m_menu->actions()[2], &QAction::triggered, this, &MainWindow::MergeSortFunction);

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


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::HeapSortFunction()
{
    ui->pushButton->setText("Heap sort");
    sortType = 0;
}

void MainWindow::QuickSortFunction()
{
    ui->pushButton->setText("Quick sort");
    sortType = 1;
}

void MainWindow::MergeSortFunction()
{
    ui->pushButton->setText("Merge sort");
    sortType = 2;
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


void MainWindow::on_pushButton_4_clicked()
{
    array->updateNumber();
}


void MainWindow::on_pushButton_5_clicked()
{
    if (isSearching)
    {
        isSearching = false;
        if (array->isSorted())
        {
            int tmp = array->binarySearch(numberToSearch);
            ui->label_3->setText(QString::number(tmp));
        }
        else
        {
            ui->label_3->setText("Array hasn't been sorted yet.");
        }
        isSearching = true;
    }
}


void MainWindow::on_pushButton_2_clicked()
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
        if (sortType == 0)
        {
            itm = new QTableWidgetItem(QString("Heap"));
            ui->tableWidget->setItem(cnt - 1, 0, itm);
            array->heapSorting();
        }
        if (sortType == 1)
        {
            itm = new QTableWidgetItem(QString("Quick"));
            ui->tableWidget->setItem(cnt - 1, 0, itm);
            array->quickSorting();
        }
        if (sortType == 2)
        {
            itm = new QTableWidgetItem(QString("Merge"));
            ui->tableWidget->setItem(cnt - 1, 0, itm);
            array->mergeSorting();
        }
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
