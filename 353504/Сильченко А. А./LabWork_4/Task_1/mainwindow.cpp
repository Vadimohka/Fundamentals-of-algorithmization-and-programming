#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //QPalette p(ui->centralwidget->palette());
    //p.setColor(QPalette::Window, QColor(162, 243, 141));
    //ui->centralwidget->setAutoFillBackground(true);
    //ui->centralwidget->setPalette(p);

    ui->setupUi(this);

    setFixedSize(1680, 800);
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1600, 600);
    ui->graphicsView->setScene(scene);





    sorter = new SortView(scene);
    ui->spinBox->setMaximum(1000000);
    ui->spinBox->setMinimum(10);
    ui->spinBox_2->setMaximum(1000);
    ui->spinBox_2->setMinimum(0);
    ui->spinBox_3->setMaximum(300);
    ui->spinBox_3->setMinimum(20);
    ui->spinBox_2->setValue(15);
    timer = new QElapsedTimer;

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBox_editingFinished()
{

}


void MainWindow::on_spinBox_valueChanged(int arg1)
{

    sorter->setArrSize(ui->spinBox->value());
    sorter->randArr();
    sorter->showArr();
}


void MainWindow::on_pushButton_clicked()
{


    ui->comboBox->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->spinBox->setEnabled(false);
    ui->spinBox_2->setEnabled(false);

    timer->restart();





    if(ui->comboBox->currentText() == "Quick Sort"){
        sorter->doQSort(0, ui->spinBox->value() - 1);
        ui->label->setText("Time: " + QString::number((qreal)timer->elapsed()/1000));
    }
    else if(ui->comboBox->currentText() == "Merge Sort"){
        sorter->doMergeSort(0, ui->spinBox->value() - 1);
        ui->label->setText("Time: " + QString::number((qreal)timer->elapsed()/1000));

    }
    else if(ui->comboBox->currentText() == "Heap Sort"){
        sorter->doHeapSort();
        ui->label->setText("Time: " + QString::number((qreal)timer->elapsed()/1000));

    }
    else if(ui->comboBox->currentText() == "Interpolation Sort"){
        sorter->doInterpolationSort();
        ui->label->setText("Time: " + QString::number((qreal)timer->elapsed()/1000));
    }
    else if(ui->comboBox->currentText() == "Bin Search")
    {
        long long num = sorter->doBinSearch(ui->spinBox_3->value());
        if (num == -1)
            QMessageBox::critical(nullptr, "Ошибка", "Не нашел(");
        else
        {
            ui->label->setText("Time: " + QString::number((qreal)timer->elapsed()/1000));
            QMessageBox::information(nullptr, "Найден", "Номер в массиве: " + QString::number(num) + "    Binpow result: " +  QString::number(sorter->binpow(num,sorter->getArrSize() ,ui->spinBox_3->value()) ));
        }
    }




    ui->comboBox->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->spinBox->setEnabled(true);
    ui->spinBox_2->setEnabled(true);
}


void MainWindow::on_pushButton_2_clicked()
{

    sorter->setArrSize(ui->spinBox->value());
    sorter->randArr();
    sorter->showArr();
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    sorter->setDelay(arg1);
}

