#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    array = new ArrayObj[70]();
    for (int i = 0; i < 70; ++i) {
        array[i].index = i + 1;
    }
    generator = new QRandomGenerator;
    ArrayObj::arr = new int[70];
    for (int i = 0; i < 70; ++i) {
        ArrayObj::arr[i] = generator->bounded(100, 800);
    }
    for (int i = 0; i < 70; ++i) {
        scene->addItem(&array[i]);
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(update()));
    timer->start(50);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] array;
    array = nullptr;
}

void MainWindow::on_comboBox_activated(int index)
{
    if (index == 0) {
        typeOfSort = 0;
    }
    if (index == 1) {
        typeOfSort = 1;
    } else {
        typeOfSort = 2;
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->comboBox->setEnabled(false);
    if (typeOfSort == 0) {

        QElapsedTimer timer;
        timer.start();
        Sort::HeapSort(ArrayObj::arr, 70);
        ui->label_3->setText(QString::number(timer.elapsed()));
    }
    else if (typeOfSort == 1) {
        QElapsedTimer timer;
        timer.start();
        Sort::QuickSort(ArrayObj::arr, 0, 69);
        ui->label_3->setText(QString::number(timer.elapsed()));
    }
    else if (typeOfSort == 2) {
        QElapsedTimer timer;
        timer.start();
        Sort::MergeSort(ArrayObj::arr, 0, 69);
        ui->label_3->setText(QString::number(timer.elapsed()));
    }
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->comboBox->setEnabled(true);
}


void MainWindow::on_pushButton_2_clicked()
{
    for (int i = 0; i < 70; ++i) {
        ArrayObj::arr[i] = generator->bounded(100, 800);
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0) {
        typeOfSort = 0;
    }
    if (index == 1) {
        typeOfSort = 1;
    } else {
        typeOfSort = 2;
    }
}

