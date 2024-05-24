#include "rect.h"

Rect::Rect(int size, QWidget *parent) : QWidget(parent), m_size(size) {
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    m_color = QColor(r, g, b);
}

void Rect::setPosition(int x, int y) {
    setGeometry(x, y, m_size*10 + 40, 30);

}

void Rect::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    // Устанавливаем кисть с этим цветом
    painter.setBrush(m_color);

    // Устанавливаем перо без цвета (Qt::NoPen), чтобы убрать границу
    painter.setPen(Qt::NoPen);

    // Рисуем прямоугольник
    painter.drawRect(rect());
}
