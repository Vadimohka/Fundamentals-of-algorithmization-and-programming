#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QTableWidgetItem>
#include <QRandomGenerator>
#include <QApplication>

MainWindow::MainWindow() : ui(new Ui::MainWindow), scene(new QGraphicsScene(this))
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    scene->setSceneRect((ui->graphicsView->width() - 20) / -2, -20, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    ui->spinBox->setRange(1, 10);
   connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::on_spinBox_valueChanged);
    drawTowers();

    towers = new HanoiTowers();
    scene->addItem(towers);
}

MainWindow::~MainWindow()
{
}

void MainWindow::hanoi(int n, char source, char auxiliary, char target)
{
    if (n == 1)
    {
        moveDisk(n, source, target);
    }
    else
    {
        hanoi(n - 1, source, target, auxiliary);
        moveDisk(n, source, target);
        hanoi(n - 1, auxiliary, source, target);
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    N = arg1;
    towers->setN(arg1);
    QCoreApplication::processEvents();
    update();
}

void MainWindow::on_pushButton_clicked()
{
   towers->isChanging = false;
   towers->minA -= towers->posN[N - 1];
   towers->minB -= towers->posN[N - 1];
   towers->minC -= towers->posN[N - 1];

    hanoi(N, 'A', 'B', 'C');
}
void MainWindow::on_pushButton_2_clicked()
{
 QApplication::quit();
}

void MainWindow::drawTowers()
{
    scene->addRect(-305, 20, 10, 250 - 10);
    scene->addRect(-5, 20, 10, 250 - 10);
    scene->addRect(295, 20, 10, 250 - 10);
    scene->addRect(-430, 250, 260, 25);
    scene->addRect(-130, 250, 260, 25);
    scene->addRect(+170, 250, 260, 25);
}

void MainWindow::moveDisk(int n, char source, char target)
{
    int row = ui->tableWidget->rowCount();

    ui->tableWidget->insertRow(row);
    QTableWidgetItem* diskItem = new QTableWidgetItem(QString::number(n));
    QTableWidgetItem* fromItem = new QTableWidgetItem(QString(source));
    QTableWidgetItem* toItem = new QTableWidgetItem(QString(target));
    ui->tableWidget->setItem(row, 0, diskItem);
    ui->tableWidget->setItem(row, 1, fromItem);
    ui->tableWidget->setItem(row, 2, toItem);

    QString step = QString("Move disk %1 from %2 to %3").arg(n).arg(source).arg(target);
    qDebug() << step;

        towers->finished = 0;
    while(!towers->finished) {
        towers->animateDisk(10 - n, source, target);
        QCoreApplication::processEvents();
    }
    if (source == 'A') towers->minA += 20; else if (source == 'B') towers->minB += 20; else towers->minC += 20;

    QCoreApplication::processEvents();
    update();
}

