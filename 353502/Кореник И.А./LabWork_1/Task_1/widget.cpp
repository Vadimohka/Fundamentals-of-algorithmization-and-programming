#include "widget.h"
#include "ui_widget.h"
#include "ellipse.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap back("/home/lidskae/Downloads/white-cloud-blue-sky.jpg");

    QPalette palette;


    back = back.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(this->backgroundRole(), back);
    this->setAutoFillBackground(false);
    this->setPalette(palette);

}

Widget::~Widget()
{
    delete ui;
}







