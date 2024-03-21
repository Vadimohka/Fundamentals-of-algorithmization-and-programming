#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    this->setCentralWidget(view);
    view->scale(2.0, 2.0);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    lhand = new LeftHandMan();
    rhand = new RightHandMan();

    scene->addItem(lhand);
    scene->addItem(rhand);

    QPen pen1(Qt::black);
    pen1.setWidth(7);
    scene->addLine(100, 80, 100, 150, pen1);
    scene->addLine(100, 150, 130, 200, pen1);
    scene->addLine(100, 150, 70, 200, pen1);
    scene->addEllipse(75, 30, 50, 50, pen1);

    greenButton = new QPushButton("Green");
    greenButton->setGeometry(QRect(-300, 300, 200, 50));
    redButton = new QPushButton("Red");
    redButton->setGeometry(QRect(300, 300, 200, 50));
    midButton = new QPushButton("Mid");
    midButton->setGeometry(QRect(0, 300, 200, 50));

    scene->addWidget(greenButton);
    scene->addWidget(redButton);
    scene->addWidget(midButton);

    timer = new QTimer();

    connect(greenButton,&QPushButton::clicked, this, &MainWindow::ClickedSlotG);
    connect(redButton,&QPushButton::clicked, this, &MainWindow::ClickedSlotR);
    connect(midButton,&QPushButton::clicked, this, &MainWindow::ClickedSlotM);

    timer->start(17);




}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete scene;
    delete view;
    delete lhand;
    delete rhand;
    delete greenButton;
    delete redButton;
    killTimer(timer->timerId());

}

void MainWindow::check1()
{
    if(lhand->rotation()== -60)
         QObject::disconnect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateL);
    if(rhand->rotation()== -20)
         QObject::disconnect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateL);
}

void MainWindow::check2()
{
    if(lhand->rotation()== 20)
         QObject::disconnect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateR);
    if(rhand->rotation()== 60)
         QObject::disconnect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateR);
}

void MainWindow::check3()
{
    if(lhand->rotation() == 0){
         QObject::disconnect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateR);
         QObject::disconnect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateL);
    }
    if(rhand->rotation() == 0){
         QObject::disconnect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateR);
         QObject::disconnect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateL);
    }

}


void MainWindow::ClickedSlotG()
{
    QObject::disconnect(timer, &QTimer::timeout, this, &MainWindow::check3);
    QObject::disconnect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateR);
    QObject::disconnect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateR);
    QObject::disconnect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateL);
    QObject::disconnect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateL);


    QObject::connect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateL);
    QObject::connect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateL);
    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::check1);

}

void MainWindow::ClickedSlotR()
{
    QObject::disconnect(timer, &QTimer::timeout, this, &MainWindow::check3);
    QObject::disconnect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateR);
    QObject::disconnect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateR);
    QObject::disconnect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateL);
    QObject::disconnect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateL);

    QObject::connect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateR);
    QObject::connect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateR);
    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::check2);
}

void MainWindow::ClickedSlotM()
{

    QObject::disconnect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateR);
    QObject::disconnect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateR);
    QObject::disconnect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateL);
    QObject::disconnect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateL);
    QObject::disconnect(timer, &QTimer::timeout, this, &MainWindow::check2);
    QObject::disconnect(timer, &QTimer::timeout, this, &MainWindow::check1);




    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::check3);

    if(rhand->rotation() < 0)
       QObject::connect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateR);
    else if(rhand->rotation() > 0)
            QObject::connect(timer, &QTimer::timeout, rhand, &RightHandMan::rotateL);

    if(lhand->rotation() < 0)
       QObject::connect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateR);
    else if(lhand->rotation() > 0)
       QObject::connect(timer, &QTimer::timeout, lhand, &LeftHandMan::rotateL);


}

