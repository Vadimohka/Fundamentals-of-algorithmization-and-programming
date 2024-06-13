#include <QApplication>
#include <QPushButton>
#include "RedBlack/Node.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    Node *test = new Node(4, BLACK);
    test = test->insert(test, 10);
    test = test->insert(test, 2);
    test = test->insert(test, 12);
    test = test->insert(test, 101);
    test = test->insert(test, 1);
    test = test->insert(test, 6);
    test = test->insert(test, 7);
    test = test->insert(test, 3);
    test->inorderTraverse(test);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
