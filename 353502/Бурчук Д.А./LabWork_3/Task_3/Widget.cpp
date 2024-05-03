#include "Widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {
    qDebug() << 1;
    QPushButton *closeButton = new QPushButton("close",this);
    closeButton->setGeometry(10,10,90,30);
    connect(closeButton, SIGNAL(clicked(bool)), SLOT(close()));
    QPushButton *solveButton = new QPushButton("solve",this);
    solveButton->setGeometry(10,50,90,30);
    connect(solveButton, SIGNAL(clicked(bool)), SLOT(solve()));
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(10,90,90,30);
    label = new QLabel(this);
    label->setGeometry(10,130,90,30);
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter *painter = new QPainter();
    painter->begin(this);
    painter->setBrush(Qt::lightGray);
    painter->drawRect(10,130,90,30);
    painter->end();
}

uint Widget::coup(uint num1, uint num2 = 0) {
    qDebug() << 2;
    if(!num1) { return num2; }
    else return coup(num1 / 10, num2 * 10 + num1 % 10);
}

void Widget::solve() {
    qDebug() << 3;
    label->setText(QString::number(coup(lineEdit->text().toInt())));
}
