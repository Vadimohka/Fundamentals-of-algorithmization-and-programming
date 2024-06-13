#include "canva.h"
#include "ui_canva.h"


Canva::Canva(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Canva)
{
    ui->setupUi(this);
    scene = new paintScene;
    ui->graphicsView->setScene(scene);
    scene->addLine(-1000,0,1000,0);
    scene->addLine(0,-1000,0,1000);
}

Canva::~Canva()
{
    delete ui;
}
