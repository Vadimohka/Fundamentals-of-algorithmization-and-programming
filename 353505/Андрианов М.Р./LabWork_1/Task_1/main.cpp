
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>

class MovingWheel : public QObject, public QGraphicsItemGroup {
    Q_OBJECT
public:
    MovingWheel(QGraphicsItem* parent = nullptr) : QGraphicsItemGroup(parent), speed(5), paused(false) {
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

public slots:
    void rotate() {
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

    void togglePause() {
        paused = !paused;
        if (paused) {
            timer->stop(); // Остановка таймера при паузе
            pauseButton->setText("Resume");
        } else {
            timer->start(); // Возобновление таймера при снятии паузы
            pauseButton->setText("Pause");
        }
    }

    void increaseSpeed() {
        if (speed < 30)
            speed++; // Увеличение скорости на 1 единицу
        updateSpeedDisplay();
    }

    void decreaseSpeed() {
        if (speed > 1)       //
            speed--; // Уменьшение скорости на 1 единицу, но не менее 0
        updateSpeedDisplay();
    }

    void updateSpeedDisplay() {
        speedDisplay->setText(QString::number(speed)); // Обновление отображения текущей скорости
    }

public:
    int speed;
    QLineEdit* speedDisplay;
    QPushButton* pauseButton;
private:
    QGraphicsEllipseItem* tire;
    QGraphicsEllipseItem* wheel;
    QTimer* timer;
    bool paused;
};

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
    pauseButton.move(225, 10);              //
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

#include "main.moc"

