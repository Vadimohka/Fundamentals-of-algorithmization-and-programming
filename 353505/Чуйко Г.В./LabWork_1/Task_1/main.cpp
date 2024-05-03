#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QTimer>
#include <QPainter>

class Rectangle : public QGraphicsRectItem {
public:
    explicit Rectangle(QGraphicsRectItem *parent = nullptr);
    virtual ~Rectangle();

    void dviz(int dy) {
        this->setPos(this->x(), dy);
    }
};

class Elevator : public Rectangle {
private:
    qreal m_width;
    qreal m_height;

public:
    Elevator(qreal width, qreal height, Rectangle *parent = nullptr)
        : Rectangle(parent), m_width(width), m_height(height) {}

    QRectF boundingRect() const override {
        return QRectF(0, 0, m_width, m_height);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override {
        // Draw the gray background
        painter->fillRect(boundingRect(), Qt::gray);

        // Draw the line in the middle (parallel to y-axis)
        painter->setPen(QPen(Qt::black, 2)); // Set line color and thickness
        qreal x = m_width / 2.0;
        painter->drawLine(x, 0, x, m_height);
    }

    void setDimensions(qreal width, qreal height) {
        prepareGeometryChange();
        m_width = width;
        m_height = height;
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Create a QGraphicsScene
    QGraphicsScene scene;

    // Create an Elevator object
    Elevator *elevator = new Elevator(50, 100);
    scene.addItem(elevator);

    // Create a QGraphicsView to visualize the scene
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setWindowTitle("Qt Elevator Example");
    view.resize(300, 400);
    view.show();

    // Calculate initial y-coordinate to position the elevator at the bottom
    qreal elX = (view.width() - elevator->boundingRect().width()) / 2.0;
    qreal elY = view.height() - elevator->boundingRect().height();
    elevator->setPos(elX, elY);

    // Create floor buttons
    QPushButton *f3 = new QPushButton("3", &view);
    QPushButton *f2 = new QPushButton("2", &view);
    QPushButton *f1 = new QPushButton("1", &view);

    f1->move(10, 70);
    f2->move(10, 40);
    f3->move(10, 10);

    f1->show();
    f2->show();
    f3->show();

    // Define animation parameters
    int duration = 1000; // Duration of animation in milliseconds
    int steps = 50;      // Number of steps for the animation

    // Create a QTimer for animation
    QTimer timer;
    timer.setInterval(duration / steps); // Set timer interval
    int stepCount = 0;
    int dest = 0; // Destination floor

    // Connect button clicks to elevator movements
    QObject::connect(f1, &QPushButton::clicked, [&]() {
        dest = view.height() - elevator->boundingRect().height(); // Bottom position
        timer.start();
    });

    QObject::connect(f2, &QPushButton::clicked, [&]() {
        dest = (view.height() - elevator->boundingRect().height()) / 2; // Middle position
        timer.start();
    });

    QObject::connect(f3, &QPushButton::clicked, [&]() {
        dest = 0; // Top position
        timer.start();
    });

    // Connect timer to a lambda function for animation
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        qreal currentY = elevator->y();
        qreal diffY = dest - currentY;
        qreal stepY = diffY / steps;
        elevator->dviz(currentY + stepY);
        ++stepCount;
        if (stepCount >= steps) {
            timer.stop();
            stepCount = 0;
        }
    });

    return a.exec();
}
