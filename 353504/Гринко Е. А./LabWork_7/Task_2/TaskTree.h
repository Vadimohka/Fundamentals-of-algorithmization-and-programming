#ifndef TASKTREE_H
#define TASKTREE_H

#include <AVLTree.h>

#include <QString>
#include <QtMath>
#include <QVector>

class MainWindow;

const uint8_t RESIZE_STEP = 2;

class TaskTree : public AVLTree<QString> {
public:
    QString preorderTraversal() {
        QString str;
        preorderTraversal(_root, str);
        return str;
    }

    QString postorderTraversal() {
        QString str;
        postorderTraversal(_root, str);
        return str;
    }

    QString inorderTraversal() {
        QString str;
        inorderTraversal(_root, str);
        return str;
    }

    QVector<size_t> leaves() {
        QVector<size_t> leaves;
        leaves.resize(qLn(_size));
        countLeaves(-1, _root, leaves);
        return leaves;
    }

private:
    void countLeaves(size_t lvl, std::shared_ptr<Node> node, QVector<size_t>& leaves) {
        if (!node) {
            return;
        }

        ++lvl;
        if (leaves.size() <= lvl) {
            leaves.resize(lvl + RESIZE_STEP);
        }
        ++leaves[lvl];
        countLeaves(lvl, node->left, leaves);
        countLeaves(lvl, node->right, leaves);
        --lvl;
    }

    void preorderTraversal(std::shared_ptr<Node> node, QString& str) {
        if (node) {
            str += "\n" + QString::number(node->key) + " " + node->value;
            preorderTraversal(node->left, str);
            preorderTraversal(node->right, str);
        }
    }

    void postorderTraversal(std::shared_ptr<Node> node, QString& str) {
        if (node) {
            postorderTraversal(node->left, str);
            postorderTraversal(node->right, str);
            str += "\n" + QString::number(node->key) + " " + node->value;
        }
    }

    void inorderTraversal(std::shared_ptr<Node> node, QString& str) {
        if (node) {
            inorderTraversal(node->left, str);
            str += "\n" + QString::number(node->key) + " " + node->value;
            inorderTraversal(node->right, str);
        }
    }

    friend MainWindow;
};

#endif // TASKTREE_H
