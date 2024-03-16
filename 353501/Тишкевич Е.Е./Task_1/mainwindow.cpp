#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <baloon.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    this->setCentralWidget(view);



    Balloon *balloon = new Balloon(-200, 260, 150, 100);
    slider = new QSlider();
    pushButton = new QPushButton("Reset the balloon");
    pushButton->resize(130,80);
    pushButton->move(130,400);
    pushButton->setStyleSheet("font-size: 16px; padding: 0px;");

    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    scene->addItem(balloon);
    scene->addWidget(slider);
    scene->addWidget(pushButton);

    slider->resize(20,500);
    slider->setMaximum(400);

    connect(slider, &QSlider::valueChanged, balloon, &Balloon::updatePosition);
    connect(slider, &QSlider::valueChanged, this, &MainWindow::changeSliderColor);
    connect(slider, &QSlider::valueChanged, balloon, &Balloon::shake);
    connect(pushButton, &QPushButton::pressed, balloon, &Balloon::reset);
    connect(pushButton, &QPushButton::pressed, this, &MainWindow::obnul);

    scene->update();


}

void MainWindow::changeSliderColor(int value)
{
    QSlider* slider = qobject_cast<QSlider*>(sender());
    if (!slider) return;

    int percentage = (value * 100) / slider->maximum();

    if (percentage <= 50)
        slider->setStyleSheet("QSlider::handle:vertical {background: green;}");
    else if (percentage > 50 && percentage <= 80)
        slider->setStyleSheet("QSlider::handle:vertical {background: yellow;}");
    else
        slider->setStyleSheet("QSlider::handle:vertical {background: red;}");
    scene->update();
}

void MainWindow::obnul()
{
    slider->setValue(0);
}



MainWindow::~MainWindow()
{
    delete ui;

}
