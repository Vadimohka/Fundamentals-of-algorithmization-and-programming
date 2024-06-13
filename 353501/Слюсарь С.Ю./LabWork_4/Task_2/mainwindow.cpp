#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->in->setValidator(new QRegularExpressionValidator(QRegularExpression("[1-9]{7}"),this));

    for (int i = 0; i < 50; ++i)
    {
        arr.push_back(rg->bounded(1, 450));
    }
    sorter = new Sorter(arr);
    scene->addItem(sorter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sort_clicked()
{
    QElapsedTimer timer;
    timer.start();
    sorter->interpolationSort();
    ui->label->setText("Время работы - " + QString::number(timer.elapsed() / 1000.0));
    ui->sort->setEnabled(false);
    ui->find->setEnabled(true);

}


void MainWindow::on_find_clicked()
{

    if (ui->in->text().isEmpty())   ui->out->setText("Неверный ввод");
    else
    {
        int num = ui->out->text().toInt();
        int pos = sorter->binSearch(50, num);
        if (pos == -1)  ui->out->setText("В массиве нет этого элемента");
        else            ui->out->setText("Ответ: " + QString::number(sorter->binpow(pos, 50, num)));
    }
}
