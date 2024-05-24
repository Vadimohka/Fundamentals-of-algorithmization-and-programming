//
// Created by u on 09.03.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "../src/waggon.h"
#include "ui_main_window.h"
#include "../src/background.h"

main_window::main_window(QWidget *parent) : QWidget(parent), ui(new Ui::main_window)
{
    this->scene = new QGraphicsScene(this);
    ui->setupUi(this);
    ui->graphicsView->setScene(this->scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    auto *bground = new background();
    scene->addItem(bground);

    auto *w = new waggon(-400, 0, 800, 200);
    w->setFlag(QGraphicsObject::ItemIsMovable);
    scene->addItem(w);


    auto *timerL = new QTimer(this);
    timerL->setInterval(1);

    connect(ui->Left, SIGNAL(pressed()), timerL, SLOT(start()));
    connect(ui->Left, SIGNAL(released()), timerL, SLOT(stop()));

    connect(timerL, SIGNAL(timeout()), w, SLOT(moveLeft()));

    auto *timerR = new QTimer(this);
    timerR->setInterval(1);

    connect(ui->Right, SIGNAL(pressed()), timerR, SLOT(start()));
    connect(ui->Right, SIGNAL(released()), timerR, SLOT(stop()));

    connect(timerR, SIGNAL(timeout()), w, SLOT(moveRight()));

    auto *decTimer = new QTimer(this);
    decTimer->setInterval(30);
    connect(decTimer, SIGNAL(timeout()), w, SLOT(decreaseSpeed()));
    decTimer->start();

    auto *timer = new QTimer(this);
    timer->setInterval(1);
    connect(timer, SIGNAL(timeout()), w, SLOT(moveRect()));
    timer->start();
}

main_window::~main_window()
{
    delete ui;
}
