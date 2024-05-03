#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include "wheel.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Wheel *wheel = new Wheel;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(wheel);

    QPixmap bkgnd("/home/vediz/Downloads/grass.jpg");

    bkgnd = bkgnd.scaled(1500, 840, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);

    QWidget window;
    window.setPalette(palette);
    window.setLayout(layout);
    window.resize(800, 600);

    window.show();

    return app.exec();
}
