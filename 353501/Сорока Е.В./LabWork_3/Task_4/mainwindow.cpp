#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);


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

        ui->listik->clear();
        ringsVector.clear();
        solver(ringsCount, 1, 2, 3);

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

    ui->spinRings->setValue(4);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::solver(int n, int source, int aux, int destination)
{
    if(n == 1) move(1, source, destination);
    else
    {
        solver(n - 1, source, destination, aux);
        move(n, source, destination);
        solver(n - 1, aux, source, destination);
    }
}

void MainWindow::animka(int time)
{
    QString moving;
    qreal to_y;


    for(int i = 0; i < ui->listik->count(); i++)
    {
        ui->listik->setCurrentRow(i);
        ui->listik->setCurrentRow(i);
        moving = ui->listik->currentItem()->text();
        int otkuda = moving.mid(0, 1).toInt();
        int kuda = moving.mid(2, 1).toInt();

        Tower *TowerOtkuda, *TowerKuda;

        if(otkuda == 1) TowerOtkuda = tower1;
        if(otkuda == 2) TowerOtkuda = tower2;
        if(otkuda == 3) TowerOtkuda = tower3;

        if(kuda == 1) TowerKuda = tower1;
        if(kuda == 2) TowerKuda = tower2;
        if(kuda == 3) TowerKuda = tower3;

        to_y = ((TowerKuda->top() == nullptr) ? (170) : (TowerKuda->top()->scenePos().y())) - 20;

        QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
        animation->setItem(TowerOtkuda->top());
        QTimeLine *timeLine = new QTimeLine(time);
        timeLine->setUpdateInterval(10);
        timeLine->setFrameRange(0, 120);

        animation->setTimeLine(timeLine);

        animation->setPosAt(0, TowerOtkuda->top()->pos());
        animation->setPosAt(1/3.0, QPointF(TowerOtkuda->top()->pos().x(), -180));
        animation->setPosAt(2/3.0, QPointF(TowerKuda->scenePos().x() - TowerOtkuda->top()->getWidth() / 2.0 + 7.5, -180));
        animation->setPosAt(1, QPointF(TowerKuda->scenePos().x() - TowerOtkuda->top()->getWidth() / 2.0 + 7.5, to_y));

        timeLine->start();

        TowerKuda->addRing(TowerOtkuda->top());
        TowerOtkuda->popRing();

        QEventLoop loop;
        QTimer::singleShot(time, &loop, &QEventLoop::quit);
        loop.exec();
    }
}

void MainWindow::move(int disk, int source, int destination)
{

    ui->listik->addItem(QString::number(source) + "➨" + QString::number(destination));

}

void MainWindow::on_buttonAnimate_clicked()
{
    ui->buttonAnimate->setEnabled(false);
    ui->spinRings->setEnabled(false);
    ui->spinBox->setEnabled(false);
    animka(ui->spinBox->value());
    ui->spinRings->setEnabled(true);
    ui->spinBox->setEnabled(true);




}
