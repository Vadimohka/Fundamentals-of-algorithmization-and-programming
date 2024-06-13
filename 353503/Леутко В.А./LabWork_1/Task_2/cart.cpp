#include "cart.h"

Cart::Cart(QObject *parent)
    : QObject{parent}, QGraphicsItem()
{
    startTimer(100);
    direction = 1;
    rotationAngle = 0;
    isMoving = false;
}

QRectF Cart::boundingRect() const
{
    return QRectF(-60, 60, 120, 80);
}

void Cart::btnClicked()
{
    isMoving = !isMoving;
}

void Cart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Create the wheels
    qreal wheelWidth = 20;
    qreal wheelHeight = 20; // Объявляем переменную wheelHeight здесь
    qreal wheelY = boundingRect().bottom() - wheelHeight;
    qreal leftWheelX = boundingRect().left() + wheelWidth - 7;
    qreal rightWheelX = boundingRect().right() - wheelWidth * 2 + 7;
    QRectF leftWheelRect(leftWheelX, wheelY, wheelWidth, wheelHeight);
    QRectF rightWheelRect(rightWheelX, wheelY, wheelWidth, wheelHeight);

    // Create the rectangle
    qreal rectWidth = boundingRect().width();
    qreal rectHeight = boundingRect().height() - wheelHeight;
    qreal rectX = boundingRect().left();
    qreal rectY = boundingRect().top();
    QRectF rect(rectX, rectY, rectWidth, rectHeight);

    painter->setPen(Qt::cyan);
    painter->setBrush(Qt::darkCyan);
    painter->drawRect(rect);

    painter->save();
    painter->translate(leftWheelRect.center());
    painter->rotate(rotationAngle * direction);
    painter->translate(-leftWheelRect.center());
    painter->setPen(Qt::green);
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(leftWheelRect);
    painter->restore();

    painter->save();
    painter->translate(rightWheelRect.center());
    painter->rotate(rotationAngle * direction);
    painter->translate(-rightWheelRect.center());
    painter->setPen(Qt::green);
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(rightWheelRect);
    painter->restore();

    // Draw crosses inside the wheels
    qreal crossSize = 8;
    QPointF crossLeftCenter(leftWheelRect.center().x(), leftWheelRect.center().y());
    QPointF crossRightCenter(rightWheelRect.center().x(), rightWheelRect.center().y());

    //painter->setPen(QColor("#FFA500"));
    painter->setPen(Qt::green);
    painter->setBrush(Qt::NoBrush);
    painter->save();
    painter->translate(crossLeftCenter);
    painter->rotate(rotationAngle * direction); // Умножаем на direction
    painter->translate(-crossLeftCenter);
    painter->drawLine(crossLeftCenter + QPointF(-crossSize, 0), crossLeftCenter + QPointF(crossSize, 0));
    painter->drawLine(crossLeftCenter + QPointF(0, -crossSize), crossLeftCenter + QPointF(0, crossSize));
    painter->restore();

    painter->save();
    painter->translate(crossRightCenter);
    painter->rotate(rotationAngle * direction); // Умножаем на direction
    painter->translate(-crossRightCenter);
    painter->drawLine(crossRightCenter + QPointF(-crossSize, 0), crossRightCenter + QPointF(crossSize, 0));
    painter->drawLine(crossRightCenter + QPointF(0, -crossSize), crossRightCenter + QPointF(0, crossSize));
    painter->restore();

    //Draw road line
    painter->setPen(QColor("#FFA500")); // Используем оранжевый цвет
    painter->drawLine(-800, 140, 800, 140);
}

void Cart::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    if (isMoving)
    {
        // Move the cart left or right
        qreal x = pos().x();
        qreal y = pos().y();

        if (x < scene()->width() - boundingRect().width() / 2 && direction == 1) {
            setPos(x + 10, y); // Move to the right
        } else if (x >= scene()->width() - boundingRect().width() / 2 && direction == 1) {
            direction = -1; // Change direction to the left if the right boundary is reached
        } else if (x > boundingRect().width() / 2 && direction == -1) {
            setPos(x - 10, y); // Move to the left
        } else if (x <= boundingRect().width() / 2 && direction == -1) {
            direction = 1; // Change direction to the right if the left boundary is reached
        }

        // Rotate the wheels
        rotationAngle += 30;

        scene()->update(); // Обновляем сцену для перерисовки

        // if(x <scene()->width()-boundingRect().width())
        //     setPos(x + 10, y);
        // else
        //     setPos(0, y);
    }
}





