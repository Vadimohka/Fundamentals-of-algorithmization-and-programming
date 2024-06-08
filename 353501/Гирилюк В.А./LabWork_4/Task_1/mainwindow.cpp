#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graphicSort = new GraphicSort();
    graphicSort->setSceneRect(0, 0, 766, 460);
    ui->graphicsView->setScene(graphicSort);
    graphicSort->setSize(10);
    ui->spinBoxSearchNumber->setMaximum(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSort_clicked()
{
    if(graphicSort->isSorted()){
        QMessageBox::information(this, "Info", "The array is already sorted.");
    }
    else if(!graphicSort->running){
        graphicSort->running = true;
        QElapsedTimer timer;
        timer.start();
        switch (ui->comboBoxSort->currentIndex()){
        case 0:
            graphicSort->quickSort(0, ui->spinBoxSize->value()-1);
            break;
        case 1:
            graphicSort->heapSort(ui->spinBoxSize->value());
            break;
        case 2:
            graphicSort->mergeSort(0, ui->spinBoxSize->value()-1);
            break;
        }
        graphicSort->running = false;
        double elapsed = timer.elapsed();
        ui->labelTime->setText(QString::number(elapsed) + " ms");
    }
    else{
        QMessageBox::warning(this, "Warning!", "Array sorting now.\nPlease, try again after finish of processing");
    }
}


void MainWindow::on_pushButtonReset_clicked()
{
    if(graphicSort->running){
        QMessageBox::warning(this, "Warning!", "Array sorting now.\nPlease, try again after finish of processing");
    }
    else{
        graphicSort->setSize(ui->spinBoxSize->value());
        ui->labelTime->setText("0 ms");
    }
}


void MainWindow::on_pushButtonSearch_clicked()
{
    if(graphicSort->isSorted()){
        if(graphicSort->binSearch(ui->spinBoxSearchNumber->value()) == -1){
            QMessageBox::information(this, "Search", "Element was not founded");
        }
        else{
            ui->labelPosition->setText(QString::number(graphicSort->binSearch(ui->spinBoxSearchNumber->value())));
            QMessageBox::information(this, "Search", "Element founded in position: " + QString::number(graphicSort->binSearch(ui->spinBoxSearchNumber->value())));
        }
    }
    else{
        QMessageBox::warning(this, "Warning!", "Array isn't sorted yet!\nPlease, sort array.");
    }
}


void MainWindow::on_spinBoxSize_valueChanged(int arg1)
{   if(graphicSort->running){
        ui->spinBoxSize->setValue(graphicSort->array.size());
        QMessageBox::warning(this, "Warning!", "Array sorting now.\nPlease, try again after finish of processing");
    }
    else{
        graphicSort->setSize(arg1);
        ui->spinBoxSearchNumber->setMaximum(arg1);
        ui->labelTime->setText("0 ms");
    }
}

