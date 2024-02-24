#include "cart.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;
    QGraphicsView *view = new QGraphicsView(&window);
    QGraphicsScene *scene = new QGraphicsScene();
    view->setScene(scene);
    Cart *cart = new Cart();
    scene->addItem(cart);
    window.setCentralWidget(view);

    QDockWidget *dock = new QDockWidget("Controls", &window);
    window.addDockWidget(Qt::RightDockWidgetArea, dock);
    QPushButton *moveLeftButton = new QPushButton("Move Left");
    QPushButton *moveRightButton = new QPushButton("Move Right");
    QObject::connect(moveLeftButton, &QPushButton::clicked, cart, &Cart::moveLeft);
    QObject::connect(moveRightButton, &QPushButton::clicked, cart, &Cart::moveRight);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(moveLeftButton);
    vbox->addWidget(moveRightButton);

    QWidget *widget = new QWidget;
    widget->setLayout(vbox);
    dock->setWidget(widget);
    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setSceneRect(-200, -200, 400, 400);
    window.show();
    return a.exec();
}
