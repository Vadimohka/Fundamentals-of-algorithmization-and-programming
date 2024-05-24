#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), visuals(new HanoiVisuals())
{
    ui->setupUi(this);

    ui->graphicsView->setScene(visuals->scene);
    ui->spinBox_2->setMaximum(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    list = HanoiSelver::Execute(ui->spinBox->value());

    ui->tableWidget->setRowCount(list.size());
    for (int i = 0; i < list.size(); ++i)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(list[i].first)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(list[i].second)));
    }
    ui->tableWidget->clearSelection();
    visuals->reset(ui->spinBox->value(), &list);
}

void MainWindow::on_tableWidget_itemSelectionChanged()
{
    auto selection = ui->tableWidget->selectedItems();
    if (selection.count() > 0)
    {
        visuals->setSelection(selection.first()->row());
    }
    else
    {
        visuals->setSelection(-1);
    }
}

void MainWindow::on_spinBox_2_valueChanged(int value)
{
    visuals->setSpeed(value);
}
