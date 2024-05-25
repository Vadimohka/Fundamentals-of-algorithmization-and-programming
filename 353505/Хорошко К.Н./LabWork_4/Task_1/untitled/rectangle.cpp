#include "rectangle.h"


Rectangle::Rectangle(int x, int y, int w, int h)
{
    this->w = w;
    this->h = h;
    this->x = x;
    this->y = y;
}


void Rectangle::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::blue);

    painter.drawRect(QRect(x, y, w, h));
    Q_UNUSED(event);
    update();
}

void Rectangle::setW(int w){
    this->w = w;
}

void Rectangle::setH(int h){
    this->h = h;
}

void Rectangle::setX(int x){
    this->x = x;
}

void Rectangle::setY(int y){
    this->y = y;
}

void Rectangle::foo(int* arr, int n, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr){
    for (int i = 0; i < rect.size(); i++){
        delete rect[i];
        qDebug() << "s";
    }
    rect.clear();
    for (int i = 0; i < n; i++){
        qDebug() << 700*(double)arr[i]/max;
        Rectangle* buf = new Rectangle(w0 + i*400/n, h0, 400/n, 700*(double)arr[i]/max);
        buf->resize(2000, 2000);
        buf->setParent(mainWindowPtr);
        buf->lower();
        buf->show();
        rect.push_back(buf);
    }
    qDebug() << "fsdfsdf";
}



