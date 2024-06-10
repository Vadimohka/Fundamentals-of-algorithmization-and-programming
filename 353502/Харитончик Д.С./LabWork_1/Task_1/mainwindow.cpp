#include "mainwindow.h"

ApplicationWindow::ApplicationWindow(QWidget *pobj) {
    auto *VLayout = new QVBoxLayout;
    auto *HLayout = new QHBoxLayout;

    auto *figureButton = new QPushButton("Rect");
    connect(figureButton, SIGNAL(clicked(bool)), SLOT(handleFigureButtonClicked()));

    auto *carButton = new QPushButton("Car");
    connect(carButton, SIGNAL(clicked(bool)), SLOT(handleCarButtonClicked()));

    auto *closeButton = new QPushButton("Close");
    connect(closeButton, SIGNAL(clicked(bool)), SLOT(handleCloseButtonClicked()));

    VLayout->setAlignment(Qt::AlignCenter);

    HLayout->addWidget(figureButton);
    HLayout->addWidget(carButton);

    VLayout->addLayout(HLayout);
    VLayout->addWidget(closeButton);
    setWindowTitle("Task 1");
    setLayout(VLayout);
}

void ApplicationWindow::handleCloseButtonClicked() {
    close();
}

void ApplicationWindow::handleFigureButtonClicked() {
    figure->setWindowFlags(Qt::Popup);
    figure->resize(300, 300);
    figure->move(400, 400);
    figure->show();
}

void ApplicationWindow::handleCarButtonClicked() {
    car->setWindowFlags(Qt::Popup);
    car->resize(300, 300);
    car->move(400, 400);
    car->show();
}
