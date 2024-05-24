#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow),scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ActiveTower = new towers();
    scene->addItem(ActiveTower);
    ui->RestartBut->hide();
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->table->setColumnCount(3);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ActiveTower;
}
void MainWindow::start(int n, char source, char auxiliary, char target)
{
    if (n == 1)
    {
        moveDisk(n, source, target);
    }
    else
    {
        start(n - 1, source, target, auxiliary);
        moveDisk(n, source, target);
        start(n - 1, auxiliary, source, target);
    }
}

void MainWindow::moveDisk(int number,char source,char target)
{
    ActiveTower->finished = false;
    while(!ActiveTower->finished){
        ActiveTower->animate(10 - number,source,target);
        QCoreApplication::processEvents();
    }
    ui->table->setRowCount(row);
    QTableWidgetItem *itm = new QTableWidgetItem(QString(source));
    ui->table->setItem(row - 1, 0, itm);
    itm = new QTableWidgetItem(QString("goes to"));
    ui->table->setItem(row - 1, 1, itm);
    itm = new QTableWidgetItem(QString(target));
    ui->table->setItem(row - 1, 2, itm);
    ui->table->scrollToBottom();
    row++;
    if (source == 'A') ActiveTower->lastEmptyPositionA += 20;
    if (source == 'B') ActiveTower->lastEmptyPositionB += 20;
    if (source == 'C') ActiveTower->lastEmptyPositionC +=20;
    update();
}

void MainWindow::on_StartButton_clicked()
{
    ui -> table -> clear();
    ActiveTower->isChanging = false;
    ActiveTower->lastEmptyPositionA -= ActiveTower->posN[ActiveTower->n - 1];
    ActiveTower->lastEmptyPositionB -= ActiveTower->posN[ActiveTower->n - 1];
    ActiveTower->lastEmptyPositionC -= ActiveTower->posN[ActiveTower->n - 1];
    ui->StartButton->hide();
    ui->label->hide();
    ui->spinBox->hide();
    start(ActiveTower->n, 'A', 'B', 'C');
    ui->RestartBut->show();
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ActiveTower->changeNumberOfRings(arg1);
    int minSteps = pow(2, arg1) - 1;
    ui->stepsLabel->setText(QString::number(minSteps));
    update();
}


void MainWindow::on_RestartBut_clicked()
{
    delete ActiveTower;
    ui -> table -> clear();
    ActiveTower = new towers();
    scene->addItem(ActiveTower);
    ui->label->show();
    ui->RestartBut->hide();
    ui->StartButton->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
}
