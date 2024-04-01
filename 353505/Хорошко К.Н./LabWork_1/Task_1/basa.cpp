#include "basa.h"
#include "ui_basa.h"


Basa::Basa(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Basa),
    rect1(new Rectangle()),
    rect2(new Rectangle()),
    rect3(new Rectangle()),
    rect4(new Rectangle()),
    rect5(new Rectangle()),
    rect6(new Rectangle()),
    rect7(new Rectangle()),
    rect8(new Rectangle()),
    trian1(new Triangle()),
    doorButton1(new QPushButton("Открыть дверь")),
    doorButton2(new QPushButton("Закрыть дверь")),
    doorButton3(new QPushButton("Остановить дверь")),
    windowButton1_1(new QPushButton("Открыть окно")),
    windowButton1_2(new QPushButton("Закрыть окно")),
    windowButton1_3(new QPushButton("Остановить окно")),
    windowButton2_1(new QPushButton("Открыть окно на крыше")),
    windowButton2_2(new QPushButton("Закрыть окно на крыше")),
    windowButton2_3(new QPushButton("Остановить окно на крыше")),
    timer1(new QTimer(this)),
    timer2(new QTimer(this)),
    timer3(new QTimer(this))

{
    ui->setupUi(this);
    this->setStyleSheet("Basa {background-color: white; }");
    this->setFixedSize(1000, 800);

    rect1->size(40, 280, 480, 480);
    rect1->color(255, 0, 0);
    rect1->setParent(this);
    rect1->resize(1000, 1000);
    rect1->show();


    rect6->size(160, 480, 120, 280);
    rect6->color(255, 255, 0);
    rect6->setParent(this);
    rect6->resize(1000, 1000);
    rect6->show();

    Max1 = 120;
    W1 = 120;

    rect2->size(160, 480, W1, 280);
    rect2->color(193, 189, 184);
    rect2->setParent(this);
    rect2->resize(1000, 1000);
    rect2->show();


    rect7->size(360, 400, 80, 160);
    rect7->color(255, 255, 0);
    rect7->setParent(this);
    rect7->resize(1000, 1000);
    rect7->show();

    Max2 = 80;
    W2 = 80;

    rect3->size(360, 400, W2, 160);
    rect3->color(152, 218, 243);
    rect3->setParent(this);
    rect3->resize(1000, 1000);
    rect3->show();


    rect4->size(360, 80, 80, 200);
    rect4->color(0, 0, 0);
    rect4->setParent(this);
    rect4->resize(1000, 1000);
    rect4->show();


    trian1->size(40, 280, 280, 40, 520, 280);
    trian1->setParent(this);
    trian1->resize(1000, 1000);
    trian1->show();

    rect8->size(240, 160, 80, 80);
    rect8->color(255, 255, 0);
    rect8->setParent(this);
    rect8->resize(1000, 1000);
    rect8->show();

    Max3 = 80;
    W3 = 80;

    rect5->size(240, 160, W3, 80);
    rect5->color(152, 218, 243);
    rect5->setParent(this);
    rect5->resize(1000, 1000);
    rect5->show();

    timer1->setInterval(15);
    timer2->setInterval(15);
    timer3->setInterval(15);


    doorButton1->setGeometry(700, 50, 200 , 50);
    doorButton1->setParent(this);
    doorButton2->setGeometry(700, 120, 200 , 50);
    doorButton2->setParent(this);
    doorButton3->setGeometry(700, 190, 200 , 50);
    doorButton3->setParent(this);

    windowButton1_1->setGeometry(700, 300, 200, 50);
    windowButton1_1->setParent(this);
    windowButton1_2->setGeometry(700, 370, 200, 50);
    windowButton1_2->setParent(this);
    windowButton1_3->setGeometry(700, 440, 200, 50);
    windowButton1_3->setParent(this);

    windowButton2_1->setGeometry(700, 550, 200, 50);
    windowButton2_1->setParent(this);
    windowButton2_2->setGeometry(700, 620, 200, 50);
    windowButton2_2->setParent(this);
    windowButton2_3->setGeometry(700, 690, 200, 50);
    windowButton2_3->setParent(this);


    connect(doorButton1, &QPushButton::clicked, this, &Basa::openDoor);
    connect(doorButton2, &QPushButton::clicked, this, &Basa::closeDoor);
    connect(doorButton3, &QPushButton::clicked, this, &Basa::stopDoor);

    connect(windowButton1_1, &QPushButton::clicked, this, &Basa::openWindow1);
    connect(windowButton1_2, &QPushButton::clicked, this, &Basa::closeWindow1);
    connect(windowButton1_3, &QPushButton::clicked, this, &Basa::stopWindow1);

    connect(windowButton2_1, &QPushButton::clicked, this, &Basa::openWindow2);
    connect(windowButton2_2, &QPushButton::clicked, this, &Basa::closeWindow2);
    connect(windowButton2_3, &QPushButton::clicked, this, &Basa::stopWindow2);


}

void Basa::open1(int &x, int dx)
{
    if (x > 0){
    x -= dx;
    rect2->size(160, 480, x, 280);
    doorButton1->setGeometry(700, 50, 200 , 50);
    doorButton2->setGeometry(700, 120, 200 , 50);
    doorButton3->setGeometry(700, 190, 200 , 50);
    update();
    }
    else
    {
    doorButton1->setGeometry(0, 0, 0, 0);
    doorButton3->setGeometry(0, 0, 0 , 0);
    update();
    }
}


void Basa::close1(int &x, int max, int dx){
    if (x < max){
    x += dx;
    rect2->size(160, 480, x, 280);
    doorButton2->setGeometry(700, 120, 200 , 50);
    doorButton1->setGeometry(700, 50, 200 , 50);
    doorButton3->setGeometry(700, 190, 200 , 50);
    update();
    }
    else {
    doorButton2->setGeometry(0, 0, 0, 0);
    doorButton3->setGeometry(0, 0, 0 , 0);
    update();
    }
}

void Basa::open2(int &x, int dx)
{
    if (x > 0){
    x -= dx;
    rect3->size(360, 400, x, 160);
    windowButton1_1->setGeometry(700, 300, 200, 50);
    windowButton1_2->setGeometry(700, 370, 200, 50);
    windowButton1_3->setGeometry(700, 440, 200, 50);
    update();
    }
    else
    {
    windowButton1_1->setGeometry(0, 0, 0, 0);
    windowButton1_3->setGeometry(0, 0, 0, 0);
    }
}


void Basa::close2(int &x, int max, int dx){
    if (x < max){
    x += dx;
    rect3->size(360, 400, x, 160);
    windowButton1_1->setGeometry(700, 300, 200, 50);
    windowButton1_2->setGeometry(700, 370, 200, 50);
    windowButton1_3->setGeometry(700, 440, 200, 50);
    update();
    }
    else
    {
    windowButton1_2->setGeometry(0, 0, 0, 0);
    windowButton1_3->setGeometry(0, 0, 0, 0);
    update();
    }
}

void Basa::open3(int &x, int dx)
{
    if (x > 0){
    x -= dx;
    rect5->size(240, 160, x, 80);
    windowButton2_1->setGeometry(700, 550, 200, 50);
    windowButton2_2->setGeometry(700, 620, 200, 50);
    windowButton2_3->setGeometry(700, 690, 200, 50);
    update();
    }
    else
    {
    windowButton2_1->setGeometry(0, 0, 0, 0);
    windowButton2_3->setGeometry(0, 0, 0, 0);
    update();
    }
}


void Basa::close3(int &x, int max, int dx){
    if (x < max){
    x += dx;
    rect5->size(240, 160, x, 80);
    windowButton2_2->setGeometry(700, 620, 200, 50);
    windowButton2_1->setGeometry(700, 550, 200, 50);
    windowButton2_3->setGeometry(700, 690, 200, 50);
    update();
    }
    else
    {
    windowButton2_2->setGeometry(0, 0, 0, 0);
    windowButton2_3->setGeometry(0, 0, 0, 0);
    update();
    }
}

void Basa::openDoor(){
    disconnect(timer1, &QTimer::timeout, nullptr, nullptr);
    connect(timer1, &QTimer::timeout, this, [=](){
        Basa::open1(W1, 1);
    });
    timer1->start();
}

void Basa::closeDoor(){
    disconnect(timer1, &QTimer::timeout, nullptr, nullptr);
    connect(timer1, &QTimer::timeout, this, [=](){
        Basa::close1(W1, Max1, 1);
    });
    timer1->start();
}

void Basa::stopDoor(){
    disconnect(timer1, &QTimer::timeout, nullptr, nullptr);
    timer1->stop();
    doorButton3->setGeometry(0, 0, 0 , 0);
}

void Basa::openWindow1(){
    disconnect(timer2, &QTimer::timeout, nullptr, nullptr);
    connect(timer2, &QTimer::timeout, this, [=](){
        Basa::open2(W2, 1);
    });
    timer2->start();
}

void Basa::closeWindow1(){
    disconnect(timer2, &QTimer::timeout, nullptr, nullptr);
    connect(timer2, &QTimer::timeout, this, [=](){
        Basa::close2(W2, Max2, 1);
    });
    timer2->start();
}

void Basa::stopWindow1(){
    disconnect(timer2, &QTimer::timeout, nullptr, nullptr);
    timer2->stop();
    windowButton1_3->setGeometry(0, 0, 0, 0);
}

void Basa::openWindow2(){
    disconnect(timer3, &QTimer::timeout, nullptr, nullptr);
    connect(timer3, &QTimer::timeout, this, [=](){
        Basa::open3(W3, 1);
    });
    timer3->start();
}

void Basa::closeWindow2(){
    disconnect(timer3, &QTimer::timeout, nullptr, nullptr);
    connect(timer3, &QTimer::timeout, this, [=](){
        Basa::close3(W3, Max3, 1);
    });
    timer3->start();
}

void Basa::stopWindow2(){
    disconnect(timer3, &QTimer::timeout, nullptr, nullptr);
    timer3->stop();
    windowButton2_3->setGeometry(0, 0, 0, 0);
}

Basa::~Basa()
{
    delete ui;

    delete rect1;
    delete rect2;
    delete rect3;
    delete rect4;
    delete rect5;
    delete trian1;
    delete doorButton1;
    delete doorButton2;
    delete doorButton3;
    delete windowButton1_1;
    delete windowButton1_2;
    delete windowButton1_3;
    delete windowButton2_1;
    delete windowButton2_2;
    delete windowButton2_3;
    delete timer1;
    delete timer2;
    delete timer3;
}

