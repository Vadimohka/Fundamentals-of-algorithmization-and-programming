#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow),scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    htowers = new hanoi();
    scene->addItem(htowers);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->table->setColumnCount(3);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete htowers;
}
void MainWindow::start(int n, char source, char auxiliary, char target)
{
    if (n == 1)
    {
        move_disc(n, source, target);
    }
    else
    {
        start(n - 1, source, target, auxiliary);
        move_disc(n, source, target);
        start(n - 1, auxiliary, source, target);
    }

}

void MainWindow::move_disc(int number,char source,char target)
{
    htowers->finished = false;
    while(!htowers->finished){
        htowers->animate(10 - number,source,target);
        QCoreApplication::processEvents();
    }
    ui->table->setRowCount(row);
    QTableWidgetItem *itm = new QTableWidgetItem(QString(source));
    ui->table->setItem(row - 1, 0, itm);
    itm = new QTableWidgetItem(QString("->"));
    ui->table->setItem(row - 1, 1, itm);
    itm = new QTableWidgetItem(QString(target));
    ui->table->setItem(row - 1, 2, itm);
    ui->table->scrollToBottom();
    row++;
    if (source == 'A') htowers->lastEmptyPositionA += 20;
    if (source == 'B') htowers->lastEmptyPositionB += 20;
    if (source == 'C')htowers->lastEmptyPositionC +=20;
    update();
}

void MainWindow::on_StartButton_clicked()
{
    htowers->isChanging = false;
    htowers->lastEmptyPositionA -= htowers->posN[htowers->n - 1];
    htowers->lastEmptyPositionB -= htowers->posN[htowers->n - 1];
    htowers->lastEmptyPositionC -= htowers->posN[htowers->n - 1];
    ui->StartButton->hide();
    ui->label->hide();
    ui->spinBox->hide();
    start(htowers->n, 'A', 'B', 'C');
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    htowers->changeNumberOfRings(arg1);
    update();
}


void MainWindow::on_RestartBut_clicked()
{
    delete htowers;
    htowers = new hanoi();
    scene->addItem(htowers);
    ui->label->show();
    ui->StartButton->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
}
