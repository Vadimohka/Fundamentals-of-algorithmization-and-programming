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
    MyVector myVector;
    myVector.MakeMyVector( ui -> lineEdit -> text() );
    myVector.setModal( true );
    myVector.exec();
    this -> show();
}
