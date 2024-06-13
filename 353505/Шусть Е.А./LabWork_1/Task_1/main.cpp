#include <QApplication>
#include <QPainter>
#include <QWidget>
#include <QPushButton>
#include <QTimer>

class BoatWidget : public QWidget {
public:
    BoatWidget(QWidget *parent = nullptr) : QWidget(parent), flagRaised(false), flagPosition(0) {
        // Создаем кнопки для управления флажком
        raiseButton = new QPushButton("Поднять флаг", this);
        raiseButton->setGeometry(800, 800, 150, 50);

        lowerButton = new QPushButton("Опустить флаг", this);
        lowerButton->setGeometry(800, 900, 150, 50);

        // Подключаем сигналы нажатия кнопок к слотам, которые управляют флажком
        connect(raiseButton, &QPushButton::clicked, this, &BoatWidget::raiseFlag);
        connect(lowerButton, &QPushButton::clicked, this, &BoatWidget::lowerFlag);

        // Таймер для плавного перемещения флажка
        flagTimer = new QTimer(this);
        connect(flagTimer, &QTimer::timeout, this, &BoatWidget::updateFlagPosition);
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Рисуем воду
        QRectF backgroundRect(0, height() / 2, width(), height() / 2);
        painter.fillRect(backgroundRect, QColor(0, 105, 148));


        qreal sunDiameter = 200.0;
        QRectF sunRect(50, 50, sunDiameter, sunDiameter);
        painter.setBrush(Qt::yellow); // Цвет солнца
        painter.drawEllipse(sunRect); // Рисуем солнце

        qreal topWidth = 600.0; // Верхнее основание
        qreal bottomWidth = 400.0; // Нижнее основание
        qreal height = 200.0; // Высота

        qreal centerX = size().width() / 2.0;
        qreal centerY = size().height() / 2.0;
        qreal topX = centerX - topWidth / 2.0;
        qreal topY = centerY - height / 2.0;
        qreal bottomX = centerX - bottomWidth / 2.0;
        qreal bottomY = centerY + height / 2.0;

        // Рисуем трапецию
        QPolygonF trapezoid;
        trapezoid << QPointF(topX, topY) << QPointF(topX + topWidth, topY)
                  << QPointF(bottomX + bottomWidth, bottomY) << QPointF(bottomX, bottomY);
        painter.setBrush(QColor(139, 69, 19));
        painter.drawPolygon(trapezoid);

        // Рисуем палку
        qreal stickWidth = 20.0; // Ширина палки
        qreal stickHeight = height * 1.5;
        qreal stickX = centerX - stickWidth / 2.0;
        qreal stickY = stickHeight-height; // Положение палки внизу трапеции
        painter.setBrush(Qt::black); // Цвет палки темно-серый
        painter.drawRect(stickX, stickY, stickWidth, stickHeight);

        // Рисуем флажок
        qreal flagWidth = 220.0; // Ширина флажка
        qreal flagLength = 80.0; // Длина флажка
        qreal flagX = centerX-10;
        qreal flagY = stickY + stickHeight - flagPosition-flagLength; // Положение флажка над палкой
        painter.setBrush(Qt::red);
        painter.drawRect(flagX, flagY, flagWidth, flagLength);
    }

private slots:
    void raiseFlag() {
        if (!flagRaised) {
            flagRaised = true;
            flagTimer->start(20); // Запускаем таймер для плавного поднятия флажка
        }
    }

    void lowerFlag() {
        if (flagRaised) {
            flagRaised = false;
            flagTimer->start(20); // Запускаем таймер для плавного опускания флажка
        }
    }

    void updateFlagPosition() {
        // Обновляем положение флажка в зависимости от состояния
        if (flagRaised && flagPosition < 220) {
            flagPosition += 1; // Плавно поднимаем флажок
        } else if (!flagRaised && flagPosition > 0) {
            flagPosition -= 1; // Плавно опускаем флажок
        } else {
            flagTimer->stop(); // Останавливаем таймер, если достигнута конечная позиция
        }

        // Перерисовываем виджет
        update();
    }

private:
    QPushButton *raiseButton;
    QPushButton *lowerButton;
    bool flagRaised;
    int flagPosition; // Положение флажка (высота)
    QTimer *flagTimer; // Таймер для плавного перемещения флажка
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    BoatWidget widget;
    widget.resize(1000, 1000);
    widget.show();
    return app.exec();
}
