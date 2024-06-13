#include "mainwindow.h"
#include "./ui_mainwindow.h"
const int SecInMil = 100;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Q_UNUSED(parent);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShuffleArray()
{
    scene->clear();
    delete[] _arr;
    _arr = new int [_size];
    srand(time(nullptr));
    for (int i = 0; i < _size; ++i)
    {
        _arr[i] = QRandomGenerator::global()->bounded(-200,0);
    }
    IsSorted = false;
}

void MainWindow::EnableClck()
{
    ui->pushButton_HeapSort->setEnabled(!IsProcess);
    ui->pushButton_MergeSort->setEnabled(!IsProcess);
    ui->pushButton_QuickSort->setEnabled(!IsProcess);
    ui->pushButton_Shuffle->setEnabled(!IsProcess);
    ui->line_search->setEnabled(!IsProcess);
}

void MainWindow::on_pushButton_Shuffle_clicked()
{
    IsProcess = true;
    if(IsArr)
    {
        ShuffleArray();
        auto* visualSort = new VisualiseSort(_arr,_size,'s',*scene);
    }
    else
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input!");
        return;
    }
}

void MainWindow::on_line_size_returnPressed()
{
    bool Ok = true;
    int n = ui->line_size->text().toInt(&Ok);
    if(!Ok || n <= 0)
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input!");
        IsArr = false;
        return;
    }
    _size = n;
    IsArr = true;
    _arr = new int [_size];
    ShuffleArray();
    auto* visualSort = new VisualiseSort(_arr,_size,'s',*scene);
}

void MainWindow::on_pushButton_QuickSort_clicked()
{
    IsProcess = true;
    EnableClck();
    if(IsArr)
    {
        scene->clear();
        auto* visualSort = new VisualiseSort(_arr,_size,'q',*scene);
        visualSort->startVisualisation();
        ui->labelTime->clear();
        ui->labelTime->setText(QString::number(visualSort->getTime()/SecInMil));
    }
    IsProcess = false;
    IsSorted = true;
    EnableClck();
}

void MainWindow::on_pushButton_HeapSort_clicked()
{
    IsProcess = true;
    EnableClck();
    if(IsArr)
    {
        scene->clear();
        auto* visualSort = new VisualiseSort(_arr,_size,'h',*scene);
        visualSort->startVisualisation();
        ui->labelTime->clear();
        ui->labelTime->setText(QString::number(visualSort->getTime()/SecInMil));
    }
    IsProcess = false;
    IsSorted = true;
    EnableClck();
}

void MainWindow::on_pushButton_MergeSort_clicked()
{
    IsProcess = true;
    EnableClck();
    if(IsArr)
    {
        scene->clear();
        auto* visualSort = new VisualiseSort(_arr,_size,'m',*scene);
        visualSort->startVisualisation();
        ui->labelTime->clear();
        ui->labelTime->setText(QString::number(visualSort->getTime()/SecInMil));
    }
    IsProcess = false;
    IsSorted = true;
    EnableClck();
}

void MainWindow::on_line_search_returnPressed()
{
    bool Ok = false;
    ui->label_answer->clear();
    int n = ui->line_search->text().toInt(&Ok);
    if(!Ok || !IsArr)
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input!");
        return;
    }
    if(n >= 1000)
    {
        QMessageBox::warning(nullptr,"Error","Array is too big for me!");
        return;
    }
    if(!IsSorted)
    {
        QMessageBox::warning(nullptr,"Error","Array is not sorted!");
        return;
    }

    auto* visualSort = new VisualiseSort(_arr,_size,'b',*scene);
    int answer = visualSort->BinarySearch(_arr,0,_size - 1,n);
    ui->label_answer->setText(answer == -1 ? "Item is not found!" : QString::number(answer) );
}
