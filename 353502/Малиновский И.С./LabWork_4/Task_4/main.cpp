#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "Vector.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Vector Example");

    QVBoxLayout *layout = new QVBoxLayout();

    QLabel *label = new QLabel("Vector Elements:");
    layout->addWidget(label);

    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        layout->addWidget(new QLabel(QString::number(*it)));
    }

    window.setLayout(layout);
    window.show();

    return app.exec();
}
