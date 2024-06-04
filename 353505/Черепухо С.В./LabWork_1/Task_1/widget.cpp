#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(860, 600);

    scene = new QGraphicsScene(0, 0, 800, 600, this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->addItem(mvr);
    scene->addItem(slr);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(aniTimer()));
    timer->start(10);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked() //create rect
{
    std::string x, y, w, h;
    x = (ui->lineEdit->text()).toStdString();
    y = (ui->lineEdit_2->text()).toStdString();
    w = (ui->lineEdit_3->text()).toStdString();
    h = (ui->lineEdit_4->text()).toStdString();

    if((x == "") || (y == "") || (w == "") || (h == ""))
        return;

    int xx = stoi(x), yy = stoi(y), ww = stoi(w), hh = stoi(h);

    mvr->x = xx; mvr->y = yy; mvr->w = ww; mvr->h = hh;
    scene->update();

}

void Widget::aniTimer()
{
    mvr->move();
    slr->move();
    slr->salute();
    scene->update();
}


void Widget::on_pushButton_2_clicked() // up rect
{
    if (mvr->my == 0)
        mvr->my = -1;
    else
        mvr->my = 0;
}


void Widget::on_pushButton_3_clicked() // left rect
{
    if (mvr->mx == 0)
        mvr->mx = -1;
    else
        mvr->mx = 0;
}


void Widget::on_pushButton_5_clicked() // down rect
{
    if (mvr->my == 0)
        mvr->my = 1;
    else
        mvr->my = 0;
}


void Widget::on_pushButton_4_clicked() // right rect
{
    if (mvr->mx == 0)
        mvr->mx = 1;
    else
        mvr->mx = 0;
}


void Widget::on_pushButton_6_clicked() // create soldier
{
    std::string x, y, w, h;
    x = (ui->lineEdit_8->text()).toStdString();
    y = (ui->lineEdit_6->text()).toStdString();
    w = (ui->lineEdit_7->text()).toStdString();
    h = (ui->lineEdit_5->text()).toStdString();

    if((x == "") || (y == "") || (w == "") || (h == ""))
        return;

    int xx = stoi(x), yy = stoi(y), ww = stoi(w), hh = stoi(h);

    slr->x = xx; slr->y = yy; slr->w = ww; slr->h = hh;
    scene->update();
}


void Widget::on_pushButton_9_clicked() // up soldier
{
    if (slr->my == 0)
        slr->my = -1;
    else
        slr->my = 0;
}


void Widget::on_pushButton_8_clicked() // left soldier
{
    if (slr->mx == 0)
        slr->mx = -1;
    else
        slr->mx = 0;
}


void Widget::on_pushButton_7_clicked() // down soldier
{
    if (slr->my == 0)
        slr->my = 1;
    else
        slr->my = 0;
}


void Widget::on_pushButton_10_clicked() // right soldier
{
    if (slr->mx == 0)
        slr->mx = 1;
    else
        slr->mx = 0;
}


void Widget::on_pushButton_11_clicked() // salut
{
    slr->st = true;
}


void Widget::on_lineEdit_textChanged(const QString &arg1) // rect.x
{
    for (long long i = 0; i < arg1.length(); i++)
    {
        if (arg1[i] < '0' || arg1[i] > '9')
        {
            ui->lineEdit->setText("");
            return;
        }
    }
}


void Widget::on_lineEdit_2_textChanged(const QString &arg1) //rect.y
{
    for (long long i = 0; i < arg1.length(); i++)
    {
        if (arg1[i] < '0' || arg1[i] > '9')
        {
            ui->lineEdit_2->setText("");
            return;
        }
    }
}


void Widget::on_lineEdit_3_textChanged(const QString &arg1) //rect.w
{
    if (arg1.length() > 4)
    {
        ui->lineEdit_3->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]));
        return;
    }

    for (long long i = 0; i < arg1.length(); i++)
    {
        if (arg1[i] < '0' || arg1[i] > '9')
        {
            ui->lineEdit_3->setText("");
            return;
        }
    }
}


void Widget::on_lineEdit_4_textChanged(const QString &arg1) //rect.h
{
    if (arg1.length() > 4)
    {
        ui->lineEdit_4->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]));
        return;
    }

    for (long long i = 0; i < arg1.length(); i++)
    {
        if (arg1[i] < '0' || arg1[i] > '9')
        {
            ui->lineEdit_4->setText("");
            return;
        }
    }
}


void Widget::on_lineEdit_8_textChanged(const QString &arg1) //sold.x
{
    for (long long i = 0; i < arg1.length(); i++)
    {
        if (arg1[i] < '0' || arg1[i] > '9')
        {
            ui->lineEdit_8->setText("");
            return;
        }
    }
}


void Widget::on_lineEdit_6_textChanged(const QString &arg1) //sold.y
{
    for (long long i = 0; i < arg1.length(); i++)
    {
        if (arg1[i] < '0' || arg1[i] > '9')
        {
            ui->lineEdit_6->setText("");
            return;
        }
    }
}


void Widget::on_lineEdit_7_textChanged(const QString &arg1) //sold.w
{
    if (arg1.length() > 4)
    {
        ui->lineEdit_7->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]));
        return;
    }

    for (long long i = 0; i < arg1.length(); i++)
    {
        if (arg1[i] < '0' || arg1[i] > '9')
        {
            ui->lineEdit_7->setText("");
            return;
        }
    }
}


void Widget::on_lineEdit_5_textChanged(const QString &arg1) //sold.h
{
    if (arg1.length() > 4)
    {
        ui->lineEdit_5->setText(QString(arg1[0]) + QString(arg1[1]) + QString(arg1[2]) + QString(arg1[3]));
        return;
    }

    for (long long i = 0; i < arg1.length(); i++)
    {
        if (arg1[i] < '0' || arg1[i] > '9')
        {
            ui->lineEdit_5->setText("");
            return;
        }
    }
}

