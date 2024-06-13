#include <QApplication>
#include <QPushButton>
#include "QDebug"
#include "AWL/Node.h"
#include "AVL_MainWindow/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto test = new Node(4);
    QPushButton button("Hello world!", nullptr);
    auto test2 = new Node(7);
    auto test3 = new Node(1);
    auto test4 = new Node(56);
    test = test->insert(test, test2->key);
    test = test->insert(test, test3->key);
    test = test->insert(test, test4->key);
    test = test->insert(test, test5->key);
    test = test->insert(test, test6->key);
    test = test->pop(test, 56);
    test->preorderTraverse(test);
    auto Main = new MainWindow(test);
    return QApplication::exec();
}