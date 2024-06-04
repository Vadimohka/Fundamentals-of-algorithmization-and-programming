#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Создание сцены и виджета для отображения
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);

    QGraphicsRectItem* road = new QGraphicsRectItem(0, 300, 500, 100);
    road->setBrush(Qt::darkGray);
    scene.addItem(road);

    // Добавление белых полос на дороге
    for (int i = 0; i < 500; i += 50) {
        QGraphicsRectItem* line = new QGraphicsRectItem(i, 345, 30, 10, road);
        line->setBrush(Qt::white);
    }

    // Добавление колеса на сцену
    MovingWheel* movingWheel = new MovingWheel();
    scene.addItem(movingWheel);

    // Создание кнопок для управления скоростью
    QPushButton pauseButton("Pause", &view);
    pauseButton.move(225, 10);
    QObject::connect(&pauseButton, &QPushButton::clicked, movingWheel, &MovingWheel::togglePause);
    movingWheel->pauseButton = &pauseButton;

    QPushButton increaseSpeedButton("+", &view);
    increaseSpeedButton.move(345, 40);
    QObject::connect(&increaseSpeedButton, &QPushButton::clicked, movingWheel, &MovingWheel::increaseSpeed);

    QPushButton decreaseSpeedButton("-", &view);
    decreaseSpeedButton.move(110, 40);
    QObject::connect(&decreaseSpeedButton, &QPushButton::clicked, movingWheel, &MovingWheel::decreaseSpeed);

    // Создание текстового поля для отображения текущей скорости
    QLineEdit speedDisplay(&view);
    speedDisplay.move(195, 40);
    speedDisplay.setReadOnly(true);
    movingWheel->speedDisplay = &speedDisplay; // Сохраняем указатель на текстовое поле для обновления скорости
    movingWheel->updateSpeedDisplay(); // Обновляем начальное значение скорости

    // Отображение виджета
    view.setSceneRect(0, 0, 500, 500); // Установка размеров виджета
    view.setFixedSize(510, 510); // Запрещаем изменение размера окна
    view.show();

    return app.exec();
}
