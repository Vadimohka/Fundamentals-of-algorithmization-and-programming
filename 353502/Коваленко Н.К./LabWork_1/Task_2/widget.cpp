#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)

{
    ui->setupUi(this);
    timer = new QTimer();
    scene = new QGraphicsScene();
    scene1 = new Shape();
    ui->graphicsView->setScene(scene);
    setEnabled(false);
    pol = new polygon;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_triangle_clicked()
{
    scene->clear();
    item = new Triangle;
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void Widget::on_pushButton_square_clicked()
{
    scene->clear();
    item = new Square;
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void Widget::on_pushButton_rhombus_clicked()
{
    scene->clear();
    item = new Rhombus;
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->update();
}

void Widget::on_pushButton_circle_clicked()
{
    scene->clear();
    item = new Circle;
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void Widget::on_pushButton_star5_clicked()
{
    scene->clear();
    item = new Star5;
    scene->addItem(item);

    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void Widget::on_pushButton_star6_clicked()
{
    scene->clear();
    item = new Star6;
    scene->addItem(item);

    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void Widget::on_pushButton_star8_clicked()
{
    scene->clear();
    item = new Star8;
    scene->addItem(item);

    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void Widget::on_pushButton_rectangle_clicked()
{
    scene->clear();
    item = new rectangle;
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void Widget::on_pushButton_parallel_clicked()
{
    scene->clear();
    item = new Parallelohram;
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);

}

void Widget::on_pushButton_hexagon_clicked()
{
    scene->clear();
    item = new Hexagon;
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void Widget::SetValue()
{
    ui->Area->setText(QString::number(item->area()));
    ui->Perimeter->setText(QString::number(item->perimeter()));
    ui->CenterMass->setText("(" + QString::number(item->getCenter().x()) + ";" + QString::number(item->getCenter().y()) + ")");
}

void Widget::on_pushButton_sizeup_pressed()
{
    item->setItem(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
    timer->start(10);
}

void Widget::on_pushButton_sizeup_released()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
}

void Widget::on_pushButton_sizedown_pressed()
{
    item->setItem(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
    timer->start(10);
}

void Widget::on_pushButton_sizedown_released()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
}

void Widget::size_slot()
{
    SetValue();
    item->getSize();
}

void Widget::on_pushButton_moveup_pressed()//move up
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_up_slot()));
    timer->start(10);
}

void Widget::on_pushButton_moveup_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_up_slot()));
    timer->stop();
}

void Widget::move_up_slot()
{
    SetValue();
    item->move_up();
}

void Widget::on_pushButton_movedown_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_down_slot()));
    timer->start(10);
}

void Widget::on_pushButton_movedown_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_down_slot()));
    timer->stop();
}

void Widget::move_down_slot()
{
    SetValue();
    item->move_down();
}

void Widget::on_pushButton_moveleft_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_left_slot()));
    timer->start(10);
}

void Widget::on_pushButton_moveleft_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_left_slot()));
    timer->stop();
}

void Widget::move_left_slot()
{
    SetValue();
    item->move_left();
}

void Widget::on_pushButton_moveright_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_right_slot()));
    timer->start(10);
}

void Widget::on_pushButton_moveright_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_right_slot()));
    timer->stop();
}

void Widget::move_right_slot()
{
    SetValue();
    item->move_right();
}

void Widget::on_pushButton_rotleft_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot()));
    timer->start(10);
}
void Widget::on_pushButton_rotleft_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot()));
    timer->stop();
}
void Widget::on_pushButton_rotright_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot()));
    timer->start(10);
}
void Widget::on_pushButton_rotright_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot()));
    timer->stop();
}

void Widget::rotate_right_slot()
{
    item->rotate_right();
}

void Widget::rotate_left_slot()
{
    item->rotate_left();
}

void Widget::on_pushButton_drawlineon_clicked()
{
    ui->graphicsView->hide();
    item=new Line;
    setEnabled(false);
    flag=0;
}
void Widget::on_pushButton_drawlineoff_clicked()
{
    ui->graphicsView->show();
    pol->points.resize(0);
    update();
}

void Widget::on_pushButton_moveline_clicked()
{
    flag=1;
}

void Widget::mousePressEvent(QMouseEvent *me)
{
    if(flag)
    {
        pol->mouseMovePressing(me);
        update();
    }
    else
    {
        pol->mouseMoving(me);
        update();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *me)
{
    if(flag)
    {
        pol->mouseMoveMoving(me);
        update();
    }
    else
    {
        pol->mouseMoving(me);
        update();
    }
}

void Widget::timer_slot()
{
    timer->stop();
}

void Widget::setEnabled(bool)
{

}

void Widget::paintEvent(QPaintEvent* )
{
    auto *p = new QPainter(this);
    p->setRenderHint(QPainter::Antialiasing,true);
    p->setPen(Qt::black);
    pol->draw(p,scale);
    p->end();
}

void Widget::changeAngle()
{
    pol->rotate(angle);
    update();
}

void Widget::on_pushButton_sizelineup_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(size_plus_slot()));
    timer->start(10);
}

void Widget::on_pushButton_sizelineup_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_plus_slot()));
    timer->stop();
}

void Widget::on_pushButton_sizelinedown_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(size_minus_slot()));
    timer->start(10);
}
void Widget::on_pushButton_sizelinedown_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_minus_slot()));
    timer->stop();
}

void Widget::rotate_right_slot1()
{
    angle += 0.5;
    if(angle>180)
    {
        angle=180;
    }
    changeAngle();
}

void Widget::rotate_left_slot1()
{
    angle -= 0.5;
    if(angle<-180)
    {
        angle=-180;
    }
    changeAngle();
}

void Widget::on_pushButton_rotliner_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot1()));
    timer->start(10);
}

void Widget::on_pushButton_rotlinel_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot1()));
    timer->start(10);
}

void Widget::on_pushButton_rotliner_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot1()));
    timer->stop();
}

void Widget::on_pushButton_rotlinel_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot1()));
    timer->stop();
}

void Widget::size_plus_slot()
{
    update();
    scale+=0.03;
    auto *p = new QPainter(this);
    p->setPen(Qt::black);
    pol->draw(p,scale);
    p->end();
}

void Widget::size_minus_slot()
{
    update();
    scale-=0.03;
    if(scale<0.04)
    {
        scale=0.04;
    }
    auto *p = new QPainter(this);
    p->setPen(Qt::black);
    pol->draw(p,scale);
    p->end();
}

