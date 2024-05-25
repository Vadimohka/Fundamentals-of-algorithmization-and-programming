#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000, 1000);

    fund = new Rect(100, 800, 800, 100);
    pal_1 = new Rect(200, 300, 1, 500);
    pal_2 = new Rect(500, 300, 1, 500);
    pal_3 = new Rect(800, 300, 1, 500);

    mas_x[0] = 200;
    mas_x[1] = 500;
    mas_x[2] = 800;

    fund->setParent(this);
    pal_1->setParent(this);
    pal_2->setParent(this);
    pal_3->setParent(this);

    fund->resize(1000, 900);
    pal_1->resize(1000, 900);
    pal_2->resize(1000, 900);
    pal_3->resize(1000, 900);

    max1 = 0;
    max2 = 750;
    max3 = 750;

    for (int i = 0; i < 10; i++){
        Rect* disk = new Rect(150+5*i, 750-50*i, 100-10*i, 50);
        disk->setParent(this);
        disk->resize(1000, 900);
        mas1.push_back(disk);
        max1 = 700-50*i;
    }

    hanoi(10, 1, 2, 3);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::next_cl);
    connect(ui->res, &QPushButton::clicked, this, &MainWindow::build);
}

void MainWindow::hanoi(int n, int f, int l, int m){
    if (n == 1){
        begin.push_back(f);
        end.push_back(l);
    }
    else
    {
        hanoi(n-1, f, m, l);
        begin.push_back(f);
        end.push_back(l);
        hanoi(n-1, m, l, f);
    }
}

void MainWindow::build(){

    ui->pushButton->setEnabled(true);

    for(int i = 0; i < mas1.size(); i++){
        delete mas1[i];
    }

    for(int i = 0; i < mas2.size(); i++){
        delete mas2[i];
    }

    for(int i = 0; i < mas3.size(); i++){
        delete mas3[i];
    }

    mas1.clear();
    mas2.clear();
    mas3.clear();
    begin.clear();
    end.clear();
    index = -1;
    max2 = 750;
    max3 = 750;

    int n = ui->spinBox->value();

    for (int i = 0; i < n; i++){
        Rect* disk = new Rect(150+5*i, 750-50*i, 100-10*i, 50);
        disk->setParent(this);
        disk->resize(1000, 900);
        mas1.push_back(disk);
        qDebug() << "ssdg";
        max1 = 700-50*i;
        disk->show();

    }

    hanoi(n, 1, 2, 3);
}

void MainWindow::next_cl(){
    ui->pushButton->setEnabled(false);
    ui->res->setEnabled(false);
    index++;
    for (int i = 0; i < begin.size(); i++){
        qDebug() << begin[i] << " " << end[i];
    }
    qDebug() << index;
    Rect *res;
    if (begin[index] == 1){
        res = mas1[mas1.size()-1];
        mas1.pop_back();
        max1 += 50;
    }
    if (begin[index] == 2){
        res = mas2[mas2.size()-1];
        mas2.pop_back();
        max2 += 50;
    }
    if (begin[index] == 3){
        res = mas3[mas3.size()-1];
        mas3.pop_back();
        max3 += 50;
    }

    int X = res->X();
    int Y = res->Y();
    int W = res->W();
    int H = res->H();
    int bufer = W;
    qDebug() << "bufer : " << bufer;
    time.setInterval(1);
    time1.setInterval(1);
    time2.setInterval(1);
    time.start();
    bool t1 = false;
    timeConnection = connect(&time, &QTimer::timeout, this, [=]() mutable {
        Y -= 10;
        qDebug()<< "Y: " << Y;
        res->setSize(X, Y, W, H);
        res->update();
        if (Y <= 100) {
            time.stop();
            disconnect(timeConnection);
            t1 = true;
            time1.start();
        }
    });

    Y = 100;

    bool t2 = false;
    timeConnection1 = connect(&time1, &QTimer::timeout, this, [=]() mutable {
        qDebug() << "sasg" << mas_x[begin[index]-1] << " " << mas_x[end[index]-1];
        Y = 100;
        if ((mas_x[begin[index]-1] - mas_x[end[index]-1]) > 0){
            X-= 5;
        }
        else {
            X+= 5;
        }
        qDebug() << X << " " << begin[index] << " " << end[index];
        res->setSize(X, Y, W, H);
        res->update();

        if (X == (mas_x[end[index]-1]-bufer/2)) {
            time1.stop();
            disconnect(timeConnection1);
            t2 = true;
            qDebug()<< ";dh" << t2;
            time2.start();

        }
    });
    int buf = 0;

    qDebug() << buf;

    X = mas_x[end[index]-1] - bufer/2;
    bool t3 = false;
    if (end[index] == 1){
        buf = max1;
    }

    if (end[index] == 2){
        buf = max2;
    }

    if (end[index] == 3){
        buf = max3;
    }

    timeConnection2 = connect(&time2, &QTimer::timeout, this, [=]() mutable {
        qDebug() << "fasdga";
        X = mas_x[end[index]-1]-bufer/2;
        Y += 10;
        res->setSize(X, Y, W, H);
        res->update();

        if (Y == buf){
            time2.stop();
            disconnect(timeConnection2);
            t3 = true;
            if (index < end.size()-1){
            ui->pushButton->setEnabled(true);
            }
            if (index < end.size()){
            ui->res->setEnabled(true);
            }
        }

    });

    Y = buf;

    if (end[index] == 1){
        mas1.push_back(res);
        max1 -= 50;
    }
    if (end[index] == 2){
        mas2.push_back(res);
        max2 -= 50;
    }
    if (end[index] == 3){
        mas3.push_back(res);
        max3 -= 50;
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}


