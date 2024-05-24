#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsItem>
#include <QTimeLine>

QList<QGraphicsRectItem*> rods;
QList<QGraphicsRectItem*> disks;
int n = 7;
QQueue<QTimeLine*> queue;
int currentStep = 0;
QList<QPair<int, QPair<char, char>>> steps;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hanoi_towers = new hanoi();

    QGraphicsScene *scene = new QGraphicsScene(this);

    /*QGraphicsRectItem *rod0 = new QGraphicsRectItem(0, 0, 10, 400);
    rod0->setPos(-350, 0);
    rods.append(rod0);
    QGraphicsRectItem *rod1 = new QGraphicsRectItem(0, 0, 10, 400);
    rod1->setPos(0, 0);
    rods.append(rod1);
    QGraphicsRectItem *rod2 = new QGraphicsRectItem(0, 0, 10, 400);
    rod2->setPos(350, 0);
    rods.append(rod2);*/

    QGraphicsRectItem *rod;
    for(int i = 0; i < 3; i++) {
        rod = new QGraphicsRectItem(0, 0, 10, 400);
        rod->setPos((i - 1) * 350, 0);
        rods.append(rod);
    }

    for (QGraphicsRectItem *rod : rods) {
        rod->setBrush(QBrush(Qt::black));
        scene->addItem(rod);
    }

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Move(QGraphicsRectItem *disk, QGraphicsRectItem *fromRod, QGraphicsRectItem *toRod)
{
    QTimeLine *timeLine = new QTimeLine(1000);
    timeLine->setFrameRange(0, 100);
    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;

    animation->setTimeLine(timeLine);
    animation->setItem(disk);

    animation->setPosAt(0, QPointF(fromRod->pos().x(), disk->pos().y()));
    animation->setPosAt(0.33, QPointF(fromRod->pos().x(), -40));
    animation->setPosAt(0.66, QPointF(toRod->pos().x(), -40));////////////////////////////////////////////
    int height = (toRod->childItems().count() - 1) * 10 - 390;
    int width = (toRod->childItems().count() - 1) * 5;
    animation->setPosAt(1, QPointF(toRod->pos().x() + width  - 45, toRod->pos().y() - height - 10));


    queue.enqueue(timeLine);
    if (queue.count() == 1) {
        connect(queue.head(), &QTimeLine::finished, this, &MainWindow::nextAnimation);
        queue.head()->start();
    }

    QApplication::processEvents();
}


void MainWindow::nextAnimation() {
    queue.dequeue();
    if (!queue.isEmpty()) {
        connect(queue.head(), &QTimeLine::finished, this, &MainWindow::nextAnimation);
        queue.head()->start();
    }
}

void MainWindow::start(int n, char _start, char _temp, char _finish)
{
    if (n > 1) {
        start(n - 1, _start, _finish, _temp);
    }
    moveDisk(n, _start, _finish);
    if (n > 1) {
        start(n - 1, _temp, _start, _finish);
    }
}


/*void MainWindow::start(int n, char _start, char _temp, char _finish)
{
    if (n == 1) {
        moveDisk(n, _start, _finish);
    } else {
        start(n - 1, _start, _finish, _temp);
        moveDisk(n, _start, _finish);
        start(n - 1, _temp, _start, _finish);
    }
}*/


/*void MainWindow::start(int n, char _start, char _temp, char _finish)
{
    if (n == 1) {
        moveDisk(n, _start, _finish);
    } else {
        start(n - 1, _start, _finish, _temp);
        moveDisk(n, _start, _finish);
        start(n - 1, _temp, _start, _finish);
    }
}*/

void MainWindow::moveDisk(int number,char _start,char _finish)
{
    steps.append(qMakePair(number, qMakePair(_start, _finish))); // Добавляем эту строку
    ui->table->setRowCount(row);
    QTableWidgetItem *p = new QTableWidgetItem(QString(_start));
    ui->table->setItem(row - 1, 0, p);
    p = new QTableWidgetItem(QString("переходит"));
    ui->table->setItem(row - 1, 1, p);
    p = new QTableWidgetItem(QString(_finish));
    ui->table->setItem(row - 1, 2, p);
    row++;
}

/*void MainWindow::on_startButton_clicked() {
    for (QGraphicsRectItem *disk : disks) {
        delete disk;
    }
    disks.clear();

    for (int i = 0; i < n; ++i) {
        QGraphicsRectItem *disk = new QGraphicsRectItem(-350, 0, 100 - i * 10, 10);
        disk->setPos(-45 + 350 + i * 5, 390 - i * 10);
        disk->setBrush(QColor::fromHsv((i * 255) / 5, 255, 255));
        disk->setParentItem(rods[0]);
        ui->graphicsView->scene()->addItem(disk);
        disks.append(disk);
    }

    start(n, 'A', 'B','C');
}*/

void MainWindow::on_startButton_clicked() {
    for (QGraphicsRectItem *disk : disks) {
        delete disk;
    }
    disks.clear();

    for (int i = n - 1; i >= 0; --i) {
        QGraphicsRectItem *disk = new QGraphicsRectItem(-350, 0, 100 - i * 10, 10);
        disk->setPos(-45 + 350 + i * 5, 390 - i * 10);
        disk->setBrush(QColor::fromHsv((i * 255) / 5, 255, 255));
        disk->setParentItem(rods[0]);
        ui->graphicsView->scene()->addItem(disk);
        disks.prepend(disk);
    }

    start(n, 'A', 'B','C');
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    n = arg1;
    hanoi_towers->changeNumberOfRings(arg1);
}

void MainWindow::on_backButton_clicked()
{
    if (currentStep > 0) {
        currentStep--;
        QPair<int, QPair<char, char>> step = steps[currentStep];
        this->Move(disks[step.first - 1], rods[step.second.second - 'A'], rods[step.second.first - 'A']);
    }
}

void MainWindow::on_forwardButton_clicked()
{
    if (currentStep < steps.size()) {
        QPair<int, QPair<char, char>> step = steps[currentStep];
        this->Move(disks[disks.size() - step.first], rods[step.second.first - 'A'], rods[step.second.second - 'A']);
        currentStep++;
    }
}




