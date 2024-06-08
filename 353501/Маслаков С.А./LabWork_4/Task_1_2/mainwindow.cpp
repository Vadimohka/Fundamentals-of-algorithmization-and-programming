#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    scene->setSceneRect(0,0,650,400);
    sort = new Sorter();
    elements = new Elements();
    connect(sort,&Sorter::updatesignal,this,&MainWindow::updateslot);
    scene->addItem(elements);
    ui->frame->hide();
    ui->stopsearchbut->hide();
    ui->textEdit->hide();
    ui->frame_2->hide();
    ui->searchbut->hide();
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}

void MainWindow::updateslot()
{
    scene->update();
    auto endTime = QTime::currentTime().addMSecs(1);
    while(QTime::currentTime() < endTime){
        QApplication::processEvents(QEventLoop::AllEvents);
    }
}

void MainWindow::on_numberofelemspin_valueChanged(int arg1)
{
    elements->setN(arg1);
    update();
    ui->searchbut->hide();
    ui->bubbesortbut->show();
    ui->heapsortbut->show();
    ui->mergesortbut->show();
    ui->quicksortbut->show();
    ui->numberofelemspin->show();
    ui->interpolationsortbut->show();
}


void MainWindow::on_bubbesortbut_clicked()
{
    ui->bubbesortbut->hide();
    ui->heapsortbut->hide();
    ui->mergesortbut->hide();
    ui->quicksortbut->hide();
    ui->numberofelemspin->hide();
    ui->interpolationsortbut->hide();
    sort->bubbleSort(elements->palki);
    ui->numberofelemspin->show();
    ui->searchbut->show();
}


void MainWindow::on_heapsortbut_clicked()
{
    ui->bubbesortbut->hide();
    ui->heapsortbut->hide();
    ui->mergesortbut->hide();
    ui->quicksortbut->hide();
    ui->numberofelemspin->hide();
    ui->interpolationsortbut->hide();
    sort->heapSort(elements->palki);
    ui->numberofelemspin->show();
    ui->searchbut->show();
}


void MainWindow::on_mergesortbut_clicked()
{
    ui->bubbesortbut->hide();
    ui->heapsortbut->hide();
    ui->mergesortbut->hide();
    ui->quicksortbut->hide();
    ui->numberofelemspin->hide();
    ui->interpolationsortbut->hide();
    sort->mergeSort(elements->palki,0,elements->getN() - 1);
    ui->numberofelemspin->show();
    ui->searchbut->show();
}


void MainWindow::on_quicksortbut_clicked()
{
    ui->bubbesortbut->hide();
    ui->heapsortbut->hide();
    ui->mergesortbut->hide();
    ui->quicksortbut->hide();
    ui->numberofelemspin->hide();
    ui->interpolationsortbut->hide();
    sort->quickSort(elements->palki,0,elements->getN() - 1);
    ui->numberofelemspin->show();
    ui->searchbut->show();
}


void MainWindow::on_searchbut_clicked()
{
    ui->textEdit->show();
    QString array;
    for(int i = 0;i < elements->palki.length();++i){
        array += QString::number(elements->palki[i]);
        array += "|";
    }
    ui->textEdit->setText(array);
    ui->frame->show();
    ui->bubbesortbut->hide();
    ui->heapsortbut->hide();
    ui->mergesortbut->hide();
    ui->quicksortbut->hide();
    ui->numberofelemspin->hide();
    ui->searchbut->hide();
    ui->frame->show();
    ui->stopsearchbut->show();
    ui->interpolationsortbut->hide();
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->frame_2->show();
    int index = sort->BinarySearch(elements->palki,0,elements->getN(),arg1);
    ui->spinBox->setMaximum(elements->palki[elements->getN() - 1]);
    elements->SearchedRect = index;
    ui->indexlabel->setText(QString::number(index));
    ui->indexeloutput->setText(QString::number(index));
    ui->numbereloutput->setText(QString::number(elements->getN()));
    if(index != -1){
        int binPowResult = sort->BinPow(index,elements->getN(),elements->palki[index]);
        ui->BinPowanswer->setText(QString::number(binPowResult));
        ui->label_7->setText(QString::number(elements->palki[index]));
    }else{
         ui->BinPowanswer->setText("There is no such element");
    }

    scene->update();
}


void MainWindow::on_stopsearchbut_clicked()
{
    ui->bubbesortbut->show();
    ui->heapsortbut->show();
    ui->mergesortbut->show();
    ui->quicksortbut->show();
    ui->numberofelemspin->show();
    ui->frame->hide();
    ui->stopsearchbut->hide();
    ui->interpolationsortbut->show();
    elements->SearchedRect = 100000;
    ui->textEdit->hide();
    ui->frame_2->hide();
    scene->update();
}


void MainWindow::on_interpolationsortbut_clicked()
{
    ui->bubbesortbut->hide();
    ui->heapsortbut->hide();
    ui->mergesortbut->hide();
    ui->quicksortbut->hide();
    ui->interpolationsortbut->hide();
    ui->numberofelemspin->hide();
    sort->interpolationSort(elements->palki,0,elements->getN() - 1);
    ui->bubbesortbut->show();
    ui->heapsortbut->show();
    ui->mergesortbut->show();
    ui->quicksortbut->show();
    ui->numberofelemspin->show();
    ui->searchbut->show();
    ui->interpolationsortbut->show();
}

