#ifndef NODE_H
#define NODE_H

#include <QString>
#include <QStringList>
struct Node {
    QString info;
    int key;
    Node* left;
    Node* right;

    Node(const QString& info, int key)
        : info(info), key(key), left(nullptr), right(nullptr) {}
};

#endif // NODE_H
