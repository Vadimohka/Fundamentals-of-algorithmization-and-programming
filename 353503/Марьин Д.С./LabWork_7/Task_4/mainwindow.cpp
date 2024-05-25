#include "mainwindow.h"
#include "QtCore/qtimer.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , table_16(16)
    , table_64(64)
    , table_128(128)
    , table_2048(2048)
{
    ui->setupUi(this);
    Fill(table_16,16);
    Fill(table_64,64);
    Fill(table_128,128);
    Fill(table_2048,2048);

    scene = new QGraphicsScene();
    setWindowTitle("Hash Table Graphics: ");
    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    SetChart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Fill(HashTable<int>& HT, size_t size)
{
    int s = QRandomGenerator::global()->bounded(int(size));
    for (int i = 0; i < s; ++i)
    {
        HT.insert(QRandomGenerator::global()->bounded(1000));
    }
}

void MainWindow::SetChart()
{
    const int Tab = 70;
    QGraphicsRectItem *rect1 = scene->addRect(QRectF(0, 0, 40,-(TimeSearch(table_16,16))));
    QGraphicsRectItem *rect2 = scene->addRect(QRectF(Tab, 0, 40,-TimeSearch(table_64,64)));
    QGraphicsRectItem *rect3 = scene->addRect(QRectF(Tab*2, 0, 40,-TimeSearch(table_128,128)));
    QGraphicsRectItem *rect4 = scene->addRect(QRectF(Tab*3, 0, 40,-TimeSearch(table_2048,2048)));

    // Set different colors for the rectangles
    rect1->setBrush(Qt::darkRed);
    rect2->setBrush(Qt::darkCyan);
    rect3->setBrush(Qt::darkMagenta);
    rect4->setBrush(Qt::yellow);

    // Add text to the rectangles
    QGraphicsTextItem *text1 = scene->addText("Table_16");
    QGraphicsTextItem *text2 = scene->addText("Table_64");
    QGraphicsTextItem *text3 = scene->addText("Table_128");
    QGraphicsTextItem *text4 = scene->addText("Table_2048");

    text1->setRotation(90);
    text2->setRotation(90);
    text3->setRotation(90);
    text4->setRotation(90);

    QColor textColor("black");
    text1->setDefaultTextColor(textColor);
    text2->setDefaultTextColor(textColor);
    text3->setDefaultTextColor(textColor);
    text4->setDefaultTextColor(textColor);
    // Position the text items
    text1->setPos(rect1->rect().bottomLeft() - QPointF(0, text1->boundingRect().height()));
    text2->setPos(rect2->rect().bottomLeft() - QPointF(0, text2->boundingRect().height()));
    text3->setPos(rect3->rect().bottomLeft() - QPointF(0, text3->boundingRect().height()));
    text4->setPos(rect4->rect().bottomLeft() - QPointF(0, text4->boundingRect().height()));
}

qreal MainWindow::TimeSearch(HashTable<int> &HT, size_t size)
{
    int val = QRandomGenerator::global()->bounded(int(size));

    auto start = std::chrono::high_resolution_clock::now();
    HT.search(val);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;

    return elapsed.count() * 1e5;
}

void MainWindow::LoadFactor(HashTable<int>& HT)
{   
    if(HT.getLoadFactor() > 1.0)
    {
        ui->progressBar->setValue(100);
        return;
    }
    ui->progressBar->setValue(HT.getLoadFactor()*100);
}

void MainWindow::CollisionFactor(HashTable<int> &HT,int size)
{
    float collision = static_cast<float>(size - HT.getCount())/size;
    ui->progressBar_2->setValue(collision*100);
}

void MainWindow::on_On_LoadFactor_16_clicked()
{
    LoadFactor(table_16);
    CollisionFactor(table_16,16);
}


void MainWindow::on_On_LoadFactor_64_clicked()
{
    LoadFactor(table_64);
    CollisionFactor(table_64,64);
}


void MainWindow::on_On_LoadFactor_128_clicked()
{
    LoadFactor(table_128);
    CollisionFactor(table_128,128);
}


void MainWindow::on_On_LoadFactor_2048_clicked()
{
    LoadFactor(table_2048);
    CollisionFactor(table_2048,2048);
}


