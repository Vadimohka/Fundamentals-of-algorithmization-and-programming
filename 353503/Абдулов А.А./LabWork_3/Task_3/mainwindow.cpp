#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    ui->pushButton_1->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();

    scene = new QGraphicsScene();
    scene->setSceneRect(100,21, 1050, 699);


    ui->graphicsView->setScene(scene);

    ui->graphicsView->show();


}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_GO_clicked(){
    ui->pushButton_1->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->pushButton_6->show();

    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);


    QPen pen;
    pen.setColor(Qt::white);

    QGraphicsLineItem* l1 = new QGraphicsLineItem(300, 640, 300, 300);
    l1->setPen(pen);
    QGraphicsLineItem* l2 = new QGraphicsLineItem(600, 640, 600, 300);
    l2->setPen(pen);
    QGraphicsLineItem* l3 = new QGraphicsLineItem(900, 640, 900, 300);
    l3->setPen(pen);
    QGraphicsLineItem* l4 = new QGraphicsLineItem(150, 640, 1050, 640);
    pen.setColor(Qt::green);
    pen.setWidth(3);
    l4->setPen(pen);


    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);

    count = ui->spinBox->value();

    ui->GO->hide();
    ui->spinBox->hide();

    std::vector<QPoint> pos_t1;

    int length = 200;
    int wide = 60;

    int x = 100;
    int y = 100;

    for(int i = 1; i <= count; i++){
        QGraphicsRectItem* ring = new QGraphicsRectItem(0,0,length, wide);
        t1.push_back(ring);
        //scene->addItem(ring);



        if(i == 1){
            length -= 2*10;
            x += i*10;
        }else{
            length -= i*10;
            x += i*5;
        }

        y += 60;

        pos_t1.push_back(QPoint(x+100,740-(y+wide)));
    }

    t1[0]->setPos(pos_t1[0]);

    scene->addItem(t1[0]);

}

