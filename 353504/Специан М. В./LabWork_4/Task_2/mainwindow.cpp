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

    connect(&vec, &SVector::valueChange, visuals.data(), &SortVisuals::updateItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    sorted = false;
    ui->pushButton_3->setEnabled(false);
    vec.clear();
    for(int i = 0; i < ui->spinBox->value(); i++)
    {
        vec.push_back((int)rand() % 1001);
    }
    visuals->reset(&vec);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (sorted)
    {
        QMessageBox::information(this, tr("Info"), tr("Array is already sorted!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    ui->lcdNumber->display(-1);
    ui->lcdNumber_2->display(-1);
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    clock_t start, end;
    double seconds;

    start = clock();
    Sorts::interpolationSort(vec, 0, vec.size());
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
    if (vec.empty())
    {
        QMessageBox::information(this, tr("Info"), tr("Array is empty!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    int digit = ui->spinBox_2->value();
    int cha = Sorts::binsearch(vec, digit);
    ui->lcdNumber->display(Sorts::binsearch(vec, digit));
    if (ui->lcdNumber->value() != -1)
    {
        visuals->updateSearch(ui->lcdNumber->value());
    }

    ui->lcdNumber_2->display(Sorts::binpow(cha, vec.size(), ui->spinBox_3->value()));
}

