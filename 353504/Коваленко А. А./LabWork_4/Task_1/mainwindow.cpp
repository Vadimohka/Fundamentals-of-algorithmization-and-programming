#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

    QRectF sceneSize = {0, 0, (qreal)ui->graphicsView->width(), (qreal)ui->graphicsView->height()};
    visuals.reset(new SortVisuals(sceneSize, ui->graphicsView));
    ui->graphicsView->scale(1, -1);
    ui->graphicsView->setScene(visuals.data());

    connect(&array, &SVector::valueChange, visuals.data(), &SortVisuals::updateItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    sorted = false;
    ui->lcdNumber->display(-1);
    ui->pushButton_3->setEnabled(false);
    size = ui->spinBox->value();
    array.clear();
    for(int i = 0; i < size; i++)
    {
        array.push_back((int)rand() % 1001);
    }
    visuals->reset(&array);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (array.empty())
    {
        QMessageBox::information(this, tr("Info"), tr("Array is empty!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    if (sorted)
    {
        QMessageBox::information(this, tr("Info"), tr("Array is already sorted!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    clock_t start, end;
    double seconds;

    start = clock();
    switch (ui->comboBox->currentIndex())
    {
    case 0:
        Sorts::quickSort(array, 0, size - 1);
        break;
    case 1:
        Sorts::heapSort(array);
        break;
    case 2:
        Sorts::mergeSort(array, 0, size - 1);
        break;
    default:
        break;
    }
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    ui->label_4->setText(QString::number(seconds) + " ms");
    sorted = !sorted;

    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}


void MainWindow::on_pushButton_3_clicked()
{
    if (array.empty())
    {
        QMessageBox::information(this, tr("Info"), tr("Array is empty!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    int digit = ui->spinBox_2->value();
    ui->lcdNumber->display(Sorts::binsearch(array, digit));
    if (ui->lcdNumber->value() != -1)
    {
        visuals->updateSearch(ui->lcdNumber->value());
    }
}
