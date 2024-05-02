#include "mainwindow.h"


MainWindow::MainWindow(QWidget *pobj) {
    this->setFixedSize(500, 1000);

    // auto *buttonFigure = new QPushButton("show Figure \nor \nclose previous widget", this);
    // connect(buttonFigure, SIGNAL(clicked(bool)), SLOT(on_figureButton_clicked()));
    // buttonFigure->setGeometry(10,10,480,100);

    auto *buttonSoldier = new QPushButton("show Soldier  \nor \nclose widget if it active", this);
    connect(buttonSoldier, SIGNAL(clicked(bool)), SLOT(on_soldierButton_clicked()));
    buttonSoldier->setGeometry(10,10,480,100);

    auto *buttonClose = new QPushButton("Close", this);
    connect(buttonClose, SIGNAL(clicked(bool)), SLOT(on_closeButton_clicked()));
    buttonClose->setGeometry(10,120,480,100);

    setWindowTitle("Lab 1 Task 1");
}
void MainWindow::on_closeButton_clicked(
)
{
    close();
}

void MainWindow::on_figureButton_clicked() {
    figure->setWindowFlags(Qt::Popup);
    figure->resize(500, 500);
    figure->move(0, 300);
    figure->show();
}

void MainWindow::on_soldierButton_clicked() {
    soldier->setWindowFlags(Qt::Popup);
    soldier->resize(500, 500);
    soldier->move(0, 300);
    soldier->show();
}

