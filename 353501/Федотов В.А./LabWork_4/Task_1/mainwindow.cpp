#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <cstdlib>
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>
#include <qlogging.h>
#include <qpoint.h>
#include <qpushbutton.h>
#include <qgraphicsitem.h>
#include <qspinbox.h>
#include <qtablewidget.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    sorter = new Sorter(&array, scene);

    connect(ui->resetButton, &QPushButton::pressed, this, &MainWindow::setArray);
    connect(ui->startButton, &QPushButton::pressed, this, &MainWindow::start);
    connect(ui->searchButton, &QPushButton::pressed, this, &MainWindow::search);
    connect(ui->speedSpinBox, &QSpinBox::valueChanged, this, &MainWindow::changeSpeed);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MainWindow::changeSpeed(int speed) { sorter->setSpeed(speed); }

void MainWindow::setArray(){
    arraySize = ui->arraySizeSpinBox->value();
    
    array.clear();
    array.resize(arraySize);

    for (int &val : array) {
        val = rand() % arraySize + 1;
    }

    sorter->visualize();
}


void MainWindow::start(){
    int selectedSorter = ui->sortersComboBox->currentIndex();
    QString size = QString::number(arraySize);
    QString time;

    switch (selectedSorter) {
        case 0:
            sorter->heapSort(array.size());

            time = QString::number(sorter->getTime(0));
            ui->resultTable->setItem(0, 0, new QTableWidgetItem(size));
            ui->resultTable->setItem(0, 1, new QTableWidgetItem(time));
            break;
        case 1:
            sorter->quickSort(0, array.size() - 1);

            time = QString::number(sorter->getTime(1));
            ui->resultTable->setItem(1, 0, new QTableWidgetItem(size));
            ui->resultTable->setItem(1, 1, new QTableWidgetItem(time));
            break;

        case 2:
            sorter->mergeSort(0, array.size() - 1);

            time = QString::number(sorter->getTime(2));
            ui->resultTable->setItem(2, 0, new QTableWidgetItem(size));
            ui->resultTable->setItem(2, 1, new QTableWidgetItem(time));
            break;

        default:
            break;    

    }
}

void MainWindow::search() {
    int target = ui->searchSpinBox->value();
    int result = sorter->binarySearch(target);

    ui->resultLineEdit->setText(QString::number(result));
}