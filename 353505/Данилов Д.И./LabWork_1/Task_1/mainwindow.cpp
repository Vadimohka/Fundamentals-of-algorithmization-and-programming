#include "mainwindow.h"

MovingWheel::MovingWheel(QGraphicsItem* parent) : QGraphicsItemGroup(parent), speed(5), paused(false) {
    // Создаем шину
    tire = new QGraphicsEllipseItem(-50, -50, 100, 100, this);
    tire->setBrush(Qt::black);

    // Создаем диск и устанавливаем его в центр шины
    wheel = new QGraphicsEllipseItem(-40, -40, 80, 80, this);
    wheel->setBrush(Qt::gray);

    // Создаем полоски на диске
    for (int i = 0; i < 6; ++i) {
        QGraphicsRectItem* stripe = new QGraphicsRectItem(-2.5, -40, 5, 80, wheel);
        stripe->setBrush(Qt::black);
        stripe->setRotation(60 * i);
    }

    // Устанавливаем начальную позицию группы
    //setPos(0, 250);
    setPos(0, 285);

    // Настраиваем таймер для вращения колеса
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MovingWheel::rotate);
    timer->start(59); // Запуск таймера для вращения колеса каждые 100 миллисекунд
}

void MovingWheel::rotate() {
    if (!paused) {
        qreal newX = x() + speed; // Увеличение координаты x на текущую скорость
        if (newX > 500) // Если колесо достигло правого края сцены
            newX = 0;    // Сбросить позицию колеса в начало
        setPos(newX, y()); // Установка новой позиции

        // Вращаем всю группу вокруг ее центра
        setTransformOriginPoint(boundingRect().center());
        setRotation(rotation() + speed); // Увеличение угла вращения на текущую скорость
    }
}

void MovingWheel::togglePause() {
    paused = !paused;
    if (paused) {
        timer->stop(); // Остановка таймера при паузе
        pauseButton->setText("Resume");
    } else {
        timer->start(); // Возобновление таймера при снятии паузы
        pauseButton->setText("Pause");
    }
}

void MovingWheel::increaseSpeed() {
    if (speed < 30)
        speed++; // Увеличение скорости на 1 единицу
    updateSpeedDisplay();
}

void MovingWheel::decreaseSpeed() {
    if (speed > 1)
        speed--; // Уменьшение скорости на 1 единицу, но не менее 0
    updateSpeedDisplay();
}

void MovingWheel::updateSpeedDisplay() {
    speedDisplay->setText(QString::number(speed)); // Обновление отображения текущей скорости
}
