#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <cstdlib>
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qpoint.h>
#include <qpushbutton.h>
#include <qgraphicsitem.h>
#include <qspinbox.h>
#include <qtablewidget.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);

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

    Sorter::setSpeed(ui->speedSpinBox->value());
    Sorter::visualize(&array, scene);
}


void MainWindow::start(){
    int selectedSorter = ui->sortersComboBox->currentIndex();
    QString size = QString::number(arraySize);
    QString time;

    switch (selectedSorter) {
        case 0:
            sorter->interpolationSort(&array, scene);
            break;

        default:
            break;    

    }
}

void MainWindow::search() {
    int target = ui->searchSpinBox->value();
    int result = Sorter::binarySearch(&array, scene, target);

    ui->resultLineEdit->setText(QString::number(result));
    ui->binpowLineEdit->setText(QString::number(Sorter::binpow(result, array.length(), ui->searchSpinBox->value())));
}