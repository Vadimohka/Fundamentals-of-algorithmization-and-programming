#include "item.h"

Item::Item(long double x,long double y,long double w,long double h, int number) : QObject(), QGraphicsItem()
{
    timer = new QTimer(this);
    setPos((x - w)/2, y - h);
    this->w = w;
    this->h = h;
    num = number;


}

void Item::up()
{
    connect(timer, &QTimer::timeout, this, &Item::mup);
    timer->start(10);
}

void Item::mB(int n)
{
    this->n = n;
    timer->stop();
    connect(timer, &QTimer::timeout, this, &Item::mup);
    timer->start(10);
    if(pos().x() < -w/2){
        connect(this, &Item::mupFinished, this, &Item::rB);
        connect(this, &Item::mrFinished, this, &Item::mDown);
    }
    else if(pos().x() > -w/2){
        connect(this, &Item::mupFinished, this, &Item::lB);
        connect(this, &Item::mlFinished, this, &Item::mDown);
    }

}

void Item::mC(int n)
{
    this->n = n;
    timer->stop();
    connect(timer, &QTimer::timeout, this, &Item::mup);
    timer->start(10);
    connect(this, &Item::mupFinished, this, &Item::rC);
    connect(this, &Item::mrFinished, this, &Item::mDown);
}

void Item::mA(int n)
{
    this->n = n;
    timer->stop();
    connect(timer, &QTimer::timeout, this, &Item::mup);
    timer->start(10);
    connect(this, &Item::mupFinished, this, &Item::lA);
    connect(this, &Item::mlFinished, this, &Item::mDown);
}
void Item::lA()
{
       qDebug()<<"la";
    ml(-800);
}

void Item::rB()
{
    qDebug()<<"rb";
    mr(0);
}

void Item::lB()
{
    qDebug()<<"lb";
    ml(0);
}

void Item::rC()
{
    qDebug()<<"rc";
    mr(800);
}
void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QLinearGradient gradient(rect.topLeft(), rect.bottomRight());
    gradient.setColorAt(0, Qt::green);
    gradient.setColorAt(1, Qt::gray);
    painter->setBrush(gradient);

    qreal cornerRadius = 10.0;
    painter->drawRoundedRect(rect, cornerRadius, cornerRadius);

    painter->setPen(Qt::black);
    QFont font("Arial", 12);
    painter->setFont(font);
    QString number = QString::number(num);
    QPointF textPosition = rect.center() - QPointF(font.pointSizeF() * number.length() / 2, 0);
    painter->drawText(textPosition, number);

}

QRectF Item::boundingRect() const
{
    return QRectF(0,0, w, h);
}

void Item::mup()
{
    if (pos().y() <= -300)
    {
        disconnect(timer, &QTimer::timeout, this, &Item::mup);

        emit mupFinished();
    }
    this->setPos(this->pos().rx(),this->pos().ry() - difcord);
}



void Item::md(int n)
{
    connect(timer, &QTimer::timeout, this, [this, n]() {
        if (pos().y() >= 300 - n * h - h) {
            disconnect(timer, &QTimer::timeout, this, nullptr);

            disconnect(this, &Item::mrFinished, this, &Item::mDown);
            disconnect(this, &Item::mlFinished, this, &Item::mDown);
            if(pos().x()==(800 - w) / 2){
                emit mCFinished();
                     qDebug()<<"Cf";
            }
            if(pos().x()== (-800 - w) / 2){
                emit mAFinished();
                qDebug()<<"af";
            }
            if(pos().x()==(0 - w) / 2){
                emit mBFinished();
                qDebug()<<"bf";
            }
            emit mdFinished();
        }
        else {
            this->setPos(this->pos().rx(),this->pos().ry() + difcord);
        }
    });
}

void Item::ml(double x)
{

    connect(timer, &QTimer::timeout, this, [this, x]() {
        if (pos().x() <= (x - w)/2) {
            disconnect(this, &Item::mupFinished, this, &Item::lB);
            disconnect(this, &Item::mupFinished, this, &Item::lA);
            disconnect(timer, &QTimer::timeout, this, nullptr);
            emit mlFinished();

        }
        else {
            this->setPos(this->pos().rx() - difcord, this->pos().ry());
        }
    });

}

void Item::mr(double x)
{
    connect(timer, &QTimer::timeout, this, [this, x]() {
        if (pos().x() >= (x - w) / 2) {
            disconnect(this, &Item::mupFinished, this, &Item::rC);
            disconnect(this, &Item::mupFinished, this, &Item::rB);
            disconnect(timer, &QTimer::timeout, this, nullptr);
            emit mrFinished();
        }
        else {
            this->setPos(this->pos().rx() + difcord, this->pos().ry());
        }
    });

}

void Item::mDown()
{
    md(n);
}
