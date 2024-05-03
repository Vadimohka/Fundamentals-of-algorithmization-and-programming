#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->graphicsView->setBackgroundBrush(QColor(225, 137, 137, 100));
    this->setStyleSheet(R"(
        QPushButton:disabled {
            background-color: #cccccc;
        }

        QSpinBox:disabled {
            background-color: #cccccc;
        }
    )");

    scene = new QGraphicsScene(this);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setAlignment(Qt::AlignmentFlag::AlignBottom);

    ui->graphicsView->setScene(scene);

    tower1 = new Tower();
    tower2 = new Tower();
    tower3 = new Tower();

    scene->addItem(tower1);
    scene->addItem(tower2);
    scene->addItem(tower3);

    tower1->setPos(-250, 0);
    tower2->setPos(0, 0);
    tower3->setPos(250, 0);


    connect(ui->spinRings, &QSpinBox::valueChanged, [=](){

        int ringsCount = ui->spinRings->value();

        ui->listWidget->clear();
        ringsVector.clear();
        hanoiTowerSolving(ringsCount, 1, 2, 3);

        tower1->clear();
        tower2->clear();
        tower3->clear();

        for(int i = 0; i < ringsCount; i++)
        {
            ringsVector.push_back(new Ring((ringsCount - i) * 30));
            tower1->createRing(ringsVector.back());

            scene->addItem(ringsVector.back());
        }

        ui->buttonAnimate->setEnabled(true);
    });

    ui->spinRings->setValue(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hanoiTowerSolving(int n, int source, int auxiliary, int destination)
{
    if(n == 1) moveDisk(1, source, destination);
    else
    {
        hanoiTowerSolving(n - 1, source, destination, auxiliary);
        moveDisk(n, source, destination);
        hanoiTowerSolving(n - 1, auxiliary, source, destination);
    }
}

void MainWindow::hanoiTowerAnimation(int time)
{
    QString moving;
    qreal toY;


    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        ui->listWidget->setCurrentRow(i);
        moving = ui->listWidget->currentItem()->text();
        int from = moving.mid(0, 1).toInt();
        int to = moving.mid(2, 1).toInt();

        Tower *TowerFrom, *TowerTo;

        if(from == 1) TowerFrom = tower1;
        if(from == 2) TowerFrom = tower2;
        if(from == 3) TowerFrom = tower3;

        if(to == 1) TowerTo = tower1;
        if(to == 2) TowerTo = tower2;
        if(to == 3) TowerTo = tower3;

        toY = ((TowerTo->top() == nullptr) ? (170) : (TowerTo->top()->scenePos().y())) - 20;

        QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
        animation->setItem(TowerFrom->top());
        QTimeLine *timeLine = new QTimeLine(time);
        timeLine->setUpdateInterval(10);
        timeLine->setFrameRange(0, 120);

        animation->setTimeLine(timeLine);

        animation->setPosAt(0, TowerFrom->top()->pos());
        animation->setPosAt(1/3.0, QPointF(TowerFrom->top()->pos().x(), -180));
        animation->setPosAt(2/3.0, QPointF(TowerTo->scenePos().x() - TowerFrom->top()->getWidth() / 2.0 + 7.5, -180));
        animation->setPosAt(1, QPointF(TowerTo->scenePos().x() - TowerFrom->top()->getWidth() / 2.0 + 7.5, toY));

        timeLine->start();

        TowerTo->addRing(TowerFrom->top());
        TowerFrom->popRing();

        QEventLoop loop;
        QTimer::singleShot(time, &loop, &QEventLoop::quit);
        loop.exec();
    }
}

void MainWindow::moveDisk(int disk, int source, int destination)
{
    ui->listWidget->addItem(QString::number(source) + "→" + QString::number(destination));
}

void MainWindow::on_buttonAnimate_clicked()
{
    ui->buttonAnimate->setEnabled(false);
    ui->spinRings->setEnabled(false);

    hanoiTowerAnimation(650);

    QMessageBox::information(this, "Ура!", "Вот так вот, короче :)");

    ui->spinRings->setEnabled(true);
}
