//
// Created by acryoz on 17.2.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RedactArea.h" resolved

#include "../headers/redactarea.h"
#include "ui_redactarea.h"


RedactArea::RedactArea(QWidget *parent) :
        QFrame(parent), ui(new Ui::RedactArea) {
    ui->setupUi(this);
    this->rotation_slider_box = new QWidget;
    this->scale_slider_box = new QWidget;
    this->rotation_slider_box->setStyleSheet("border: 0px solid black");
    this->scale_slider_box->setStyleSheet("border: 0px solid black");

    this->rotation_slider = new QSlider(Qt::Horizontal);
    this->rotation_slider->setParent(this->rotation_slider_box);
    this->rotation_slider->setRange(0,360);
    this->rotation_slider->setMinimumWidth(180);

    this->scale_slider = new QSlider(Qt::Horizontal);
    this->scale_slider->setParent(this->scale_slider_box);
    this->scale_slider->setRange(1,10);
    this->scale_slider->setMinimumWidth(180);
    this->scale_slider->setValue(5);

    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addWidget(this->rotation_slider_box);
    vbox->addWidget(this->scale_slider_box);
    this->setLayout(vbox);
}




RedactArea::~RedactArea() {
    delete ui;
}
