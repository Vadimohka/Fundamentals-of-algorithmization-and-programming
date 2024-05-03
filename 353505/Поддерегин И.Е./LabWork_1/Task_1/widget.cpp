#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    scene->setSceneRect(-350,-300,700,500);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsView->setScene(scene);
    Soldat *item = new Soldat;
    scene->addItem(item);
    item->setPos(0,0);

    animation = new QTimer(this);
    connect(animation,SIGNAL(timeout()), scene,SLOT(advance()));

    animation->start(10);

}

Widget::~Widget()
{
    delete ui;
}

