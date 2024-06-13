#include <QApplication>
#include <QPushButton>
#include "QDebug"
#include "Deque/Deque.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    Deque<int> deque;
    int u = 1;
    deque.push_back(u);
    deque.push_back(3);
    deque.push_back(7);
    deque.push_back(10);
    deque.push_back(13);
    deque.push_back(12);
    deque.push_back(14);
    deque.push_back(5);
    deque.push_back(100);
    deque.push_front(52);
    auto i = deque.begin();
    for (i = deque.begin(); i != deque.end(); i++) {
    qDebug() << *i;
    }
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
