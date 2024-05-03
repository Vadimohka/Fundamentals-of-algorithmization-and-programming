#include "widget.h"
#include "./ui_widget.h"

bool speedBoxval = 0;
int speedVal=0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    graphicsView = new QGraphicsView;
    scene = new QGraphicsScene;
    cart = new Cart;
    group = new QGraphicsItemGroup;
    group = cart->returnCartGroup(group);
    ui->graphicsView->setScene(scene);

    scene->setSceneRect(0,0,800,600);
    scene->addItem(group);

    connect(cart->animationTimer,SIGNAL(timeout()),scene,SLOT(advance()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Stop_clicked()
{
    speedBoxval=0;
    cart->stop(); 
}

void Widget::on_Go_clicked()
{
    cart->speed(speedVal);
    speedBoxval=0;
}

void Widget::on_speedBox_valueChanged(int arg1)
{
    speedVal=arg1;
    if(speedBoxval && arg1)
    {
        cart->speed(speedVal);
    }
    else
    {
        cart->stop();
    }
}

