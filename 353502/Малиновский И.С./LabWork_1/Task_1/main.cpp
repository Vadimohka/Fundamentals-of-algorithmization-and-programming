#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "face.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Moving Face");

    QVBoxLayout* layout = new QVBoxLayout();

    Face* face = new Face();
    layout->addWidget(face);

    QPushButton* moveButton = new QPushButton("Move Ellipse");
    QObject::connect(moveButton, &QPushButton::clicked, [face]() {
        face->moveEllipse(10, 10);
    });
    layout->addWidget(moveButton);

    QPushButton* openMouthButton = new QPushButton("Open Mouth");
    QObject::connect(openMouthButton, &QPushButton::clicked, face, &Face::openMouth);
    layout->addWidget(openMouthButton);

    QPushButton* closeMouthButton = new QPushButton("Close Mouth");
    QObject::connect(closeMouthButton, &QPushButton::clicked, face, &Face::closeMouth);
    layout->addWidget(closeMouthButton);

    QPushButton* moveEyesButton = new QPushButton("Move Eyes");
    QObject::connect(moveEyesButton, &QPushButton::clicked, [face]() {
        face->moveEyes(5, 0);
    });
    layout->addWidget(moveEyesButton);

    window.setLayout(layout);
    window.show();

    return app.exec();
}
