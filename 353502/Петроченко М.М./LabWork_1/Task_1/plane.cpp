//
// Created by acryoz on 10.2.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_plane.h" resolved

#include "../headers/plane.h"
#include "ui_plane.h"


plane::plane(QWidget *parent) :
     Rectangle (parent), ui(new Ui::plane) {
    ui->setupUi(this);
    QPalette plane_color;
    plane_color.setColor(QPalette::Window, Qt::gray);
    QPalette window_color;
    window_color.setColor(QPalette::Window, Qt::blue);
    this->setPalette(plane_color);
    this->setAutoFillBackground(false);
    this->resize(250, 180);

    this->nose.setParent(this);
    this->nose.resize(150,75);
    this->nose.move(100, 75);
    this->nose.setPalette(plane_color);
    this->nose.setAutoFillBackground(true);
    this->nose.show();

    this->body.setParent(this);
    this->body.move(0, 50);
    this->body.resize(200,100);
    this->body.setPalette(plane_color);
    this->body.setAutoFillBackground(true);
    this->body.show();

    this->tail.setParent(this);
    this->tail.resize(50,150);
    this->tail.setPalette(plane_color);
    this->tail.setAutoFillBackground(true);
    this->tail.show();

    this->iluminator.setParent(this);
    this->iluminator.resize(50,15);
    this->iluminator.move(150, 60);
    this->iluminator.setPalette(window_color);
    this->iluminator.setAutoFillBackground(true);
    this->iluminator.show();

    this->chassis1.setParent(this);
    this->chassis1.resize(20,30);
    this->chassis1.move(170, 120);
    this->chassis1.setPalette(plane_color);
    this->chassis1.setAutoFillBackground(true);
    this->chassis1.show();

    this->chassis2.setParent(this);
    this->chassis2.resize(20,30);
    this->chassis2.move(40, 120);
    this->chassis2.setPalette(plane_color);
    this->chassis2.setAutoFillBackground(true);
    this->chassis2.show();
}


void plane::moveSideways(){
    g_clock.start(1000/FPS);
    this->taking_off = true;
    this->retractChassis();
    if(this->pos().y() >= this->parentWidget()->size().height()-this->size().height()){
        this->hspeed = 5;
        this->vspeed = -5;
    }
    else{
        this->vspeed = 0;
    }

    if (this->vspeed != 0){
        this->prev_vspeed = this->vspeed;
    }
    this->hspeed = this->prev_hspeed;
}

void plane::moveUpDown() {
    this->landing = true;
    this->taking_off = false;
    g_clock.start(1000 / FPS);
    this->vspeed = 5;
}

void plane::moveTick() {
    QPoint newpos = this->pos();
    if(this->landing && !this->taking_off && this->pos().y() > this->parentWidget()->size().height() - this->size().height()){
        this->hspeed = 0;
        this->extendChassis();
    }
    if(this->hspeed > 0 && this->pos().x() > this->parentWidget()->size().width() - this->size().width()){
        this->hspeed *= -1;
        this->prev_hspeed = this->hspeed;
    }
    if(this->hspeed < 0 -1 && this->pos().x() < 0){
        this->hspeed *= -1;
        this->prev_hspeed = this->hspeed;
    }
    if(this->vspeed > 0 && this->pos().y() > this->parentWidget()->size().height() - this->size().height()){
        this->vspeed *= 0;
    }
    if(this->vspeed < 0 && this->pos().y() < 0){
        this->vspeed *= 0;
    }
    newpos.setX(newpos.x() + this->hspeed);
    newpos.setY(newpos.y() + this->vspeed);
    qDebug() << this->pos().x() << ' ' << this->pos().y() <<  ' ' << this->hspeed << ' ' << this->prev_hspeed;
    this->move(newpos);
}


void plane::extendChassis() {
    this->chassis1.move(170, 150);
    this->chassis2.move(40, 150);
}


void plane::retractChassis() {
    this->chassis1.move(170, 120);
    this->chassis2.move(40, 120);
}


plane::~plane() {
    delete ui;
}
