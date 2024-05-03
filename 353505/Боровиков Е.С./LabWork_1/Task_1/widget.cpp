#include "widget.h"
#include "ui_widget.h"

Widget::Widget()//QWidget *parent
    :  ui(new Ui::Widget) //QWidget(parent),
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,1000,600,this);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());
    scene->addItem(circle.smalic);
    scene->addItem(circle.Osnova_glaz1);
    scene->addItem(circle.Osnova_glaz2);
    scene->addItem(object.glaz1);
    scene->addItem(object.glaz2);
    scene->addItem(object.zrachok1);
    scene->addItem(object.zrachok2);
    scene->addItem(object.bel_kysok1);
    scene->addItem(object.bel_kysok2);

    gyba1 = new QGraphicsEllipseItem(200,390,190,30);
    gyba1->setBrush(Qt::black);
    scene->addItem(gyba1);

    gyba2 = new QGraphicsEllipseItem(200,400,190,30);
    gyba2->setBrush(Qt::black);
    scene->addItem(gyba2);

    time_rot1 = new QTimer(this);
    connect(time_rot1,SIGNAL(timeout()),this,SLOT(on_open_rot_clicked()));

    time_rot2 = new QTimer(this);
    connect(time_rot2,SIGNAL(timeout()),this,SLOT(on_close_rot_clicked()));

    up_date = new QTimer(this);
    connect(up_date,&QTimer::timeout,this,[=](){
        if(object.proverka == 0){
            ui->glaza_in_left->setEnabled(true);
            ui->glaza_in_right->setEnabled(true);

            ui->glaza_in_left->setStyleSheet("background-color : white;");
            ui->glaza_in_right->setStyleSheet("background-color : white;");
        }else{
            ui->glaza_in_left->setEnabled(false);
            ui->glaza_in_right->setEnabled(false);
            ui->glaza_in_left->setStyleSheet("background-color : gray;");
            ui->glaza_in_right->setStyleSheet("background-color : gray;");

        }
        if(vadb == -1){
            ui->close_rot->setEnabled(false);
            ui->open_rot->setEnabled(false);
            ui->close_rot->setStyleSheet("background-color : gray;");
            ui->open_rot->setStyleSheet("background-color : gray;");
        }
        else{
            if (vadb == 0){
                ui->close_rot->setEnabled(false);
                ui->open_rot->setEnabled(true);
                ui->close_rot->setStyleSheet("background-color : gray;");
                ui->open_rot->setStyleSheet("background-color : white;");

            }else{
                ui->close_rot->setEnabled(true);
                ui->open_rot->setEnabled(false);
                ui->close_rot->setStyleSheet("background-color : white;");
                ui->open_rot->setStyleSheet("background-color : gray;");
            }
        }


    });
    up_date->start(30);


}

void Widget::myOpenRot()
{
    static int x = 0 ,y = 0 ,j = 0;
    vadb = -1;
    gyba1->setPos(0,y);
    gyba2->setPos(0,x);
    if(j >= 25){
        time_rot1->stop();
        x = 0;
        y = 0;
        j = 0;
        vadb = 1;
    }
    j++;
    x++;
    y--;
}

void Widget::myCloseRot()
{
    static int x1 = -25,y1 = 25,j1 = 0;
    vadb  = -1;
    gyba1->setPos(0,x1);
    gyba2->setPos(0,y1);
    if(j1 == 25){
        time_rot2->stop();
        j1 = 0;
        x1 = -25;
        y1 = 25;
        vadb = 0;
    }
    j1++;
    x1++;
    y1--;
}

void Widget::on_glaza_in_right_clicked(){
   object.myTimerEllipse1();
}

void Widget::on_glaza_in_left_clicked(){
    object.myTimerEllipse2();
}

void Widget::on_open_rot_clicked()
{
    time_rot1->start(30);
    Widget::myOpenRot();
}

void Widget::on_close_rot_clicked()
{
    time_rot2->start(30);
    Widget::myCloseRot();
}

Widget::~Widget(){
    delete ui;
}




