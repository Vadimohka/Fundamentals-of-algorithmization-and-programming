#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Сравнение таблиц");

    setCentralWidget(ui->gridLayoutWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testLinHashMap(LinearHashTable a)
{
    for (int i = 0; i < 1000; ++i) {
        a.findItem(QRandomGenerator::global()->bounded(1, 100));
    }
}

void MainWindow::testQuadHashMap(QuadHashTable a)
{
    for (int i = 0; i < 1000; ++i) {
        a.findItem(QRandomGenerator::global()->bounded(1, 100));
    }
}

void MainWindow::fillMaps()
{
    a1 = LinearHashTable(16);
    b1 = LinearHashTable(64);
    c1 = LinearHashTable(128);
    d1 = LinearHashTable(2048);
    a2 = QuadHashTable(16);
    b2 = QuadHashTable(64);
    c2 = QuadHashTable(128);
    d2 = QuadHashTable(2048);
    for (int i = 0; i < 16; ++i) {
        a1.insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    for (int i = 0; i < 64; ++i) {
        b1.insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    for (int i = 0; i < 128; ++i) {
        c1.insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    for (int i = 0; i < 2048; ++i) {
        d1.insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    for (int i = 0; i < 16; ++i) {
        a2.insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    for (int i = 0; i < 64; ++i) {
        b2.insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    for (int i = 0; i < 128; ++i) {
        c2.insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    for (int i = 0; i < 2048; ++i) {
        d2.insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
}

void MainWindow::buildGraphics()
{
    QElapsedTimer timer;

    int resOfa1 = 0;
    timer.start();
    testLinHashMap(a1);
    resOfa1 = timer.nsecsElapsed();

    int resOfb1 = 0;
    timer.start();
    testLinHashMap(b1);
    resOfb1 = timer.nsecsElapsed();

    int resOfc1 = 0;
    timer.start();
    testLinHashMap(c1);
    resOfc1 = timer.nsecsElapsed();

    int resOfd1 = 0;
    timer.start();
    testLinHashMap(d1);
    resOfd1 = timer.nsecsElapsed();

    int resOfa2 = 0;
    timer.start();
    testQuadHashMap(a2);
    resOfa2 = timer.nsecsElapsed();

    int resOfb2 = 0;
    timer.start();
    testQuadHashMap(b2);
    resOfb2 = timer.nsecsElapsed();

    int resOfc2 = 0;
    timer.start();
    testQuadHashMap(c2);
    resOfc2 = timer.nsecsElapsed();

    int resOfd2 = 0;
    timer.start();
    testQuadHashMap(d2);
    resOfd2 = timer.nsecsElapsed();

    QGraphicsView *view = ui->graphicsView;
    QGraphicsScene *scene = new QGraphicsScene(this);
    view->setScene(scene);

    QGraphicsRectItem *bara1 = new QGraphicsRectItem(0, -sqrt(resOfa1), 50, sqrt(resOfa1));
    QGraphicsRectItem *bara2 = new QGraphicsRectItem(55, -sqrt(resOfa2), 50, sqrt(resOfa2));

    QGraphicsRectItem *barb1 = new QGraphicsRectItem(150, -sqrt(resOfb1), 50, sqrt(resOfb1));
    QGraphicsRectItem *barb2 = new QGraphicsRectItem(205, -sqrt(resOfb2), 50, sqrt(resOfb2));

    QGraphicsRectItem *barc1 = new QGraphicsRectItem(350, -sqrt(resOfc1), 50, sqrt(resOfc1));
    QGraphicsRectItem *barc2 = new QGraphicsRectItem(405, -sqrt(resOfc2), 50, sqrt(resOfc2));

    QGraphicsRectItem *bard1 = new QGraphicsRectItem(500, -sqrt(resOfd1), 50, sqrt(resOfd1));
    QGraphicsRectItem *bard2 = new QGraphicsRectItem(555, -sqrt(resOfd2), 50, sqrt(resOfd2));

    scene->addItem(bara1);
    scene->addItem(bara2);

    scene->addItem(barb1);
    scene->addItem(barb2);

    scene->addItem(barc1);
    scene->addItem(barc2);

    scene->addItem(bard1);
    scene->addItem(bard2);
}


void MainWindow::on_pushButton_2_clicked()
{
    fillMaps();
    buildGraphics();
}

