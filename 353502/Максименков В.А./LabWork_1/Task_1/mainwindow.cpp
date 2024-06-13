#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 800, 800, this);
    ui->graphicsView->setScene(scene);

    s = new Segment();
    r0 = new Rocket(0);
    r1 = new Rocket(1);
    scene->addItem(s);
    scene->addItem(r0);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_timeout()
{
    sec++;

    if (sec > 150)
    {
        timer->stop();
        s->setPos(400, 600);
        s->v = 1;
        r1->setPos(400, 600);
        r1->v = 1;
        scene->removeItem(r1);
        scene->addItem(r0);
        r0->setPos(400, 600);
        sec = 0;
        sostoyanie = 0;
    }

    this->scene->update();
}


void MainWindow::on_go_clicked()
{
    if (sostoyanie)
    {
        timer->start(1000/60);
    }
    else
    {
        QMessageBox::warning(this, "WARNING!!!", "Двигатели не запущены!");
    }
}


void MainWindow::on_start_clicked()
{
    if (!sostoyanie)
    {
        sostoyanie = 1;
        scene->removeItem(r0);
        scene->addItem(r1);
        r1->setPos(400, 599);
        this->scene->update();
    }
    else
    {
        QMessageBox::information(this, "INFORMATION", "Двигатели уже запущены!");
    }
}


void MainWindow::on_off_clicked()
{
    if (sostoyanie)
    {
        sostoyanie = 0;
        scene->removeItem(r1);
        scene->addItem(r0);
        r0->setPos(400, 599);
        this->scene->update();
    }
    else
    {
        QMessageBox::information(this, "INFORMATION", "Двигатели не могут быть выключены, так как они не запущены!");
    }
}

