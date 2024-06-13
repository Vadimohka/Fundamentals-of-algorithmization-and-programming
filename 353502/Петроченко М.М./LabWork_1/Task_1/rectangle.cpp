//
// Created by acryoz on 10.2.24.
//

#include "../headers/rectangle.h"
#include "ui_rectangle.h"



Rectangle::Rectangle(QWidget *parent) :
        QWidget(parent), ui(new Ui::Rectangle) {
    ui->setupUi(this);
    QPalette pal;
    pal.setColor(QPalette::Window, Qt::darkBlue);
    this->resize(200,100);
    this->hspeed = 5;
    this->vspeed = 5;
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    QObject::connect(&this->g_clock, SIGNAL(timeout()), this, SLOT(moveTick()));
    this->show();
}


void Rectangle::moveSideways(){
    g_clock.start(1000/FPS);
    if (this->vspeed != 0){
        this->prev_vspeed = this->vspeed;
    }
    this->vspeed = 0;
    this->hspeed = this->prev_hspeed;
}

void Rectangle::moveUpDown() {
    g_clock.start(1000 / FPS);
    if (this->hspeed != 0){
        this->prev_hspeed = this->hspeed;
    }
    this->hspeed = 0;
    this->vspeed = this->prev_vspeed;
}


void Rectangle::moveTick() {
    QPoint newpos = this->pos();
    if(this->hspeed > 0 && this->pos().x() > this->parentWidget()->size().width() - this->size().width()){
        this->hspeed *= -1;
        this->prev_hspeed = this->hspeed;
    }
    if(this->hspeed < 0 -1 && this->pos().x() < 0){
        this->hspeed *= -1;
        this->prev_hspeed = this->hspeed;
    }
    if(this->vspeed > 0 && this->pos().y() > this->parentWidget()->size().height() - this->size().height()){
        this->vspeed *= -0;
        this->prev_vspeed = this->vspeed;
    }
    if(this->vspeed < 0 && this->pos().y() < 0){
        this->vspeed *= -0;
        this->prev_vspeed = this->vspeed;
    }
    newpos.setX(newpos.x() + this->hspeed);
    newpos.setY(newpos.y() + this->vspeed);
    this->move(newpos);
}


void Rectangle::stop(){
    this->hspeed = 0;
    this->vspeed = 0;
}


Rectangle::~Rectangle() {
    delete ui;
}
