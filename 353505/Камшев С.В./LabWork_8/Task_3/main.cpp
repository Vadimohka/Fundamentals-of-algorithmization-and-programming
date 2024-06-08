#include "mainwindow.h"

#include <QApplication>
//#include <QDebug>
//#include "map.h"
//#include "set.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*Map<int, QString> rbTree;

    // Insert some key-value pairs into the tree
    rbTree.insert(10, "ten");
    rbTree.insert(20, "twenty");
    rbTree.insert(30, "thirty");
    rbTree.insert(40, "forty");
    rbTree.insert(50, "fifty");
    rbTree.insert(60, "sixty");

    // Print the tree in-order using an iterator
    for (auto it = rbTree.begin(); it != rbTree.end(); ++it) {
        qDebug() << "Key:" << it->data.first << ", Value:" << it->data.second;
    }

    // Check if certain keys are in the tree
    qDebug() << "Contains key 30:" << rbTree.containsKey(30);
    qDebug() << "Contains key 70:" << rbTree.containsKey(70);

    // Get and print the value of a specific key
    qDebug() << "Value for key 40:" << rbTree.get(40);
    qDebug() << "Value for key 60:" << rbTree.get(60);

    // Erase a key from the tree
    rbTree.erase(50);

    // Print the tree again to show the result of the deletion
    qDebug() << "After deleting key 20:";
    for (auto it = rbTree.begin(); it != rbTree.end(); ++it) {
        qDebug() << "Key:" << it->data.first << ", Value:" << it->data.second;
    }

    // Clear the tree
    rbTree.clear();

    // Check if the tree is empty
    qDebug() << "Tree is empty:" << (rbTree.begin() == rbTree.end());

    Set <int> set;
    set.insert(10);
    set.insert(20);
    set.insert(30);
    set.insert(40);
    set.insert(50);
    set.insert(60);
    set.insert(70);
    set.insert(80);
    for (auto it = set.begin(); it != set.end(); ++it) {
        qDebug() << "Key:" << it->data.first;
    }
    set.erase(10);
    set.erase(20);
    set.erase(30);
    set.erase(40);
    set.erase(50);
    set.erase(80);
    for (auto it = set.begin(); it != set.end(); ++it) {
        qDebug() << "Key:" << it->data.first;
    }*/
    return a.exec();
}
