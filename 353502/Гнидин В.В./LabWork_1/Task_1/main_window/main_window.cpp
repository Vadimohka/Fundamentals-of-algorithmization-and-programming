//
// Created by volodya-petarda on 3/3/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include <QTimer>
#include "main_window.h"
#include "../face.h"
#include "ui_main_window.h"
#include "../background.h"

main_window::main_window(QWidget *parent) :
        QWidget(parent), ui(new Ui::main_window) {
    this->scene = new QGraphicsScene(this);
    ui->setupUi(this);
    ui->graphicsView->setScene(this->scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    auto *back = new background();
    scene->addItem(back);

    face *f = new face(-250, -250, scene);
    scene->addItem(f);
    connect(ui->mouthButton, SIGNAL(clicked()), f, SLOT(scaleMouth()));
    connect(ui->eyesButton, SIGNAL(clicked()), f, SLOT(moveEyes()));
}

main_window::~main_window() {
    delete ui;
}
