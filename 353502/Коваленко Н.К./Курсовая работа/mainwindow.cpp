#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view.h"
#include <QWidget>
#include <QStackedLayout>
#include <QListWidget>


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

//появление сцены
void MainWindow::on_pushButton_clicked()
{
    xSize = this->parentWidget()->width();
    ySize = this->parentWidget()->height();
    //виджет - сцена игры
    View *scene = new View(1);
    scene->scale((ySize/450), (ySize/450));
    this->parentWidget()->layout()->removeWidget(this);
    this->parentWidget()->layout()->addWidget(scene);
    deleteLater();
}


void MainWindow::on_pushButton_2_clicked()
{
    xSize = this->parentWidget()->width();
    ySize = this->parentWidget()->height();
    //виджет - сцена игры
    View *scene = new View(2);
    scene->scale((ySize/450), (ySize/450));
    this->parentWidget()->layout()->removeWidget(this);
    this->parentWidget()->layout()->addWidget(scene);
    deleteLater();
}

void MainWindow::on_pushButton_3_clicked()
{
    xSize = this->parentWidget()->width();
    ySize = this->parentWidget()->height();
    //виджет - сцена игры
    View *scene = new View(3);
    scene->scale((ySize/450), (ySize/450));
    this->parentWidget()->layout()->removeWidget(this);
    this->parentWidget()->layout()->addWidget(scene);
    deleteLater();
}




