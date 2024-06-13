#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../headers/plane.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget main_window;
    main_window.setFixedSize(1200, 800);

    QWidget draw_area(&main_window);
    draw_area.resize(1200, 750);

    plane rect(&draw_area);

    QPushButton fly_button("Fly", &main_window);
    fly_button.setMinimumSize(200, 100);
    QPushButton land_button("Land", &main_window);
    land_button.setMinimumSize(200, 100);

    QHBoxLayout* hbox = new QHBoxLayout;
    hbox->addWidget(&fly_button);
    hbox->addWidget(&land_button);

    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addWidget(&draw_area);
    vbox->addLayout(hbox);

    QObject::connect(&fly_button, SIGNAL(clicked()), &rect, SLOT(moveSideways()));
    QObject::connect(&land_button, SIGNAL(clicked()), &rect, SLOT(moveUpDown()));

    main_window.setLayout(vbox);
    main_window.show();
    return QApplication::exec();
}
