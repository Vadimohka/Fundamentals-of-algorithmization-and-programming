#include "widget.h"
#include "ui_widget.h"
#include "rectangle.h"
#include "samosval.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    QPalette p,p1;
    p.setBrush(this->backgroundRole(),Qt::green);
    this->setPalette(p);
    QLabel *l= new QLabel(this);
    l->setGeometry(0,0,1950,445);
    l->setStyleSheet("QLabel {color: gray; background: WhiteSmoke;}");
    Rectangle *pramoygol= new Rectangle(this);
    pramoygol->setGeometry(100,100,600,600);
    QPushButton* Up = new QPushButton("Up",this);
    QPushButton* Down = new QPushButton("Down",this);
    QPushButton* Left = new QPushButton("Left",this);
    QPushButton* Right = new QPushButton("Right",this);
    Up->setGeometry(650,480,40,40);
    Down->setGeometry(650,520,40,40);
    Left->setGeometry(610,500,40,40);
    Right->setGeometry(690,500,40,40);
    Samosval *vodila = new Samosval(pramoygol);
    vodila->setGeometry(0,0,600,600);
    QObject::connect(Up,&QPushButton::clicked,pramoygol,&Rectangle::moveUp);
    QObject::connect(Down,&QPushButton::clicked,pramoygol,&Rectangle::moveDown);
    QObject::connect(Left,&QPushButton::clicked,pramoygol,&Rectangle::moveLeft);
    QObject::connect(Right,&QPushButton::clicked,pramoygol,&Rectangle::moveRight);
}

Widget::~Widget()
{
    delete ui;
}
