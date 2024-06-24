#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButtonInput_clicked()
{

    this -> hide();
    MidVector midVector;
    midVector.MakeMidVector( ui -> lineEdit -> text() );
    midVector.setModal( true );
    midVector.exec();
    this -> show();

}

