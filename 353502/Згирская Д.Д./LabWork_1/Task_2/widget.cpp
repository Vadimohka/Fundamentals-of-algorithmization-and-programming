#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    figures.emplace_back(nullptr);

    figures[0] = new Rectangle(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter *painter = new QPainter;

    painter->begin(this);

    figures[0]->draw(painter);

    painter->end();
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
    figures[0]->drawMoveEvent(event);
}

void Widget::mousePressEvent(QMouseEvent *event) {
    figures[0]->drawPressEvent(event);
}
