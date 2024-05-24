#include <QApplication>
#include <QPainter>
#include <QWidget>
#include <QPushButton>
#include <QTimer>

class BoatWidget : public QWidget {
public:
    BoatWidget(QWidget *parent = nullptr) : QWidget(parent), Raised(false), Position(0), Position1(0){
        // Создаем кнопки для управления
        raiseButton = new QPushButton("Открыть дверь и окно", this);
        raiseButton->setGeometry(800, 800, 160, 50);

        lowerButton = new QPushButton("Закрыть дверь и окно", this);
        lowerButton->setGeometry(800, 900, 160, 50);

        // Подключаем сигналы нажатия кнопок к слотам
        connect(raiseButton, &QPushButton::clicked, this, &BoatWidget::raise);
        connect(lowerButton, &QPushButton::clicked, this, &BoatWidget::lower);

        // Таймер для плавного перемещения
        Timer = new QTimer(this);
        connect(Timer, &QTimer::timeout, this, &BoatWidget::updatePosition);
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Рисуем травку
        QRectF backgroundRect(0, height() / 2, width(), height() / 2);
        painter.fillRect(backgroundRect, Qt::darkGreen);

        qreal sunDiameter = 200.0;
        QRectF sunRect(50, 50, sunDiameter, sunDiameter);
        painter.setBrush(Qt::yellow); // Цвет солнца
        painter.drawEllipse(sunRect); // Рисуем солнце

        qreal topWidth = 400.0; // Верхнее основание
        qreal bottomWidth = 400.0; // Нижнее основание
        qreal height = 500.0; // Высота

        qreal centerX = size().width() / 2.0;
        qreal centerY = size().height() / 2.0;
        qreal topX = centerX - topWidth / 2.0;
        qreal topY = centerY - height / 2.0;
        qreal bottomX = centerX - bottomWidth / 2.0;
        qreal bottomY = centerY + height / 2.0;

        QPolygonF pryamoyg;
        pryamoyg << QPointF(topX, topY) << QPointF(topX + topWidth, topY);
        pryamoyg << QPointF(bottomX + bottomWidth, bottomY) << QPointF(bottomX, bottomY);
        painter.setBrush(Qt::darkRed);
        painter.drawPolygon(pryamoyg);

        qreal rectangleWidth1 = 150.0; // Ширина прямоугольника
        qreal rectangleHeight1 = 200.0; // Высота прямоугольника
        qreal rectangleX1 =  centerX ;
        qreal rectangleY1 = centerY + rectangleHeight1 / 4.0;
        painter.setBrush(Qt::black);
        painter.drawRect(rectangleX1, rectangleY1, rectangleWidth1, rectangleHeight1);

        // Создаем QPolygonF с вершинами треугольника
        QPolygonF triangle;
        triangle << QPointF(rectangleX1- rectangleWidth1*2, rectangleY1-rectangleHeight1) << QPointF(rectangleX1, 50) << QPointF(rectangleX1+rectangleWidth1*2, rectangleY1-rectangleHeight1) ;

        // Заполняем треугольник красным цветом
        painter.setBrush(Qt::red);
        painter.setPen(Qt::NoPen); // Установите нулевую кисть, чтобы не было видимой границы
        painter.drawPolygon(triangle);

        qreal rectangleWidth = 150.0; // Ширина прямоугольника
        qreal rectangleHeight = 200.0; // Высота прямоугольника
        qreal rectangleX =  centerX + Position ;
        qreal rectangleY = centerY + rectangleHeight / 4.0;
        painter.setBrush(Qt::darkYellow);
        painter.drawRect(rectangleX, rectangleY, rectangleWidth, rectangleHeight);

        qreal rectangleWidth3 = 100.0; // Ширина прямоугольника
        qreal rectangleHeight3 = 100.0; // Высота прямоугольника
        qreal rectangleX3 =  centerX +rectangleWidth3/4;
        qreal rectangleY3 = centerY - rectangleHeight3;
        painter.setBrush(Qt::black);
        painter.drawRect(rectangleX3, rectangleY3, rectangleWidth3, rectangleHeight3);

        qreal rectangleWidth2 = 100.0; // Ширина прямоугольника
        qreal rectangleHeight2 = 100.0; // Высота прямоугольника
        qreal rectangleX2 =  centerX +Position1 + rectangleWidth2/4;
        qreal rectangleY2 = centerY - rectangleHeight2;
        painter.setBrush(Qt::blue);
        painter.drawRect(rectangleX2, rectangleY2, rectangleWidth2, rectangleHeight2);
    }

private slots:
    void raise() {
        if (!Raised) {
            Raised = true;
            Timer->start(20); // Запускаем таймер
        }
    }
    void lower() {
        if (Raised) {
            Raised = false;
            Timer->start(20); // Запускаем таймер
        }
    }
    void updatePosition() {

        if (Raised && Position < 150 && Position1 < 100) {
            Position += 3;
            Position1 += 2;
        } else if (!Raised && Position && Position1 > 0) {
            Position -= 3;
            Position1 -=2;// Плавно передвигаем объекты
        } else {
            Timer->stop(); // Останавливаем таймер, если достигнута конечная позиция
        }

        // Перерисовываем виджет
        update();
    }

private:
    QPushButton *raiseButton;
    QPushButton *lowerButton;
    bool Raised;
    int Position;
    int Position1;
    QTimer *Timer; // Таймер для плавного перемещения
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    BoatWidget widget;
    widget.resize(1000, 1000);
    widget.show();
    return app.exec();
}
