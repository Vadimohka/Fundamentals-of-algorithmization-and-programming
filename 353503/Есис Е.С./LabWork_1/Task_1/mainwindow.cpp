#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow() : scene(new QGraphicsScene()), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //House *house = new House();

    scene->addItem(&house);
    scene->addItem(&test);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);


    // connect(ui->windowBox, &QCheckBox::clicked, house, &House::setWindow);
    // connect(ui->doorBox, &QCheckBox::clicked, house, &House::setDoor);

    connect(ui->radioButton, SIGNAL(clicked(bool)), SLOT(onClick()));
}

void MainWindow::onClick() {
    if (ui->radioButton->isChecked()) {
        test.Forward();
    } else {
        test.Back();
    }
}


