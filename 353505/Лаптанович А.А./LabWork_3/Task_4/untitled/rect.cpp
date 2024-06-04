#include "rect.h"

Rect::Rect(int x, int y, int w, int h) : QWidget()
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    myColor = randomColor();
}

QColor Rect::randomColor()
{
    QRandomGenerator *randomGenerator = QRandomGenerator::global();

    // Генерируем случайные значения для красного, зеленого и синего цветов
    int red = (*randomGenerator).bounded(256);   // От 0 до 255
    int green = (*randomGenerator).bounded(256); // От 0 до 255
    int blue = (*randomGenerator).bounded(256);  // От 0 до 255

    // Создаем и возвращаем случайный цвет
    return QColor(red, green, blue);
}

void Rect::setSize(int x, int y, int w, int h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Rect::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(myColor);

    painter.drawRect(x, y, w, h);

}

int Rect::X(){
    return x;
}

int Rect::Y(){
    return y;
}

int Rect::W(){
    return w;
}

int Rect::H(){
    return h;
}

