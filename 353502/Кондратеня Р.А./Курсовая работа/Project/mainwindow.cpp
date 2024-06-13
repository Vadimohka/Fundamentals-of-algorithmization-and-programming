#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    SheetWidget* widget = new SheetWidget();
    widget->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    SheetWidget* widget = new SheetWidget();
    widget->getModel()->loadTableFromFile(widget);
    widget->show();
}

