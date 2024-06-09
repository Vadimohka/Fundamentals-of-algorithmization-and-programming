#ifndef TASKTREE_H
#define TASKTREE_H

#include <AVLTree.h>

#include <QString>
#include <QtMath>
#include <QVector>

class MainWindow;

const uint8_t RESIZE_STEP = 2;

template <class T>
class TaskTree : public AVLTree<T> {

    using node_ptr = std::shared_ptr<typename AVLTree<T>::Node>;

public:

    //------------------------------------------------------------------------------------------------//

    QVector<T> preorderTraversal() {
        QVector<QPair<int, T>> vect;
        preorderTraversal(AVLTree<T>::_root, vect);
        return vect;
    }

    QVector<T> postorderTraversal() {
        QVector<QPair<int, T>> vect;
        postorderTraversal(AVLTree<T>::_root, vect);
        return vect;
    }

    QVector<T> inorderTraversal() {
        QVector<QPair<int, T>> vect;
        inorderTraversal(AVLTree<T>::_root, vect);
        return vect;
    }

    //------------------------------------------------------------------------------------------------//



    //------------------------------------------------------------------------------------------------//

    QVector<size_t> leaves() {
        QVector<size_t> leaves;
        leaves.resize(qLn(AVLTree<T>::_size));
        countLeaves(-1, AVLTree<T>::_root, leaves);
        return leaves;
    }

    //------------------------------------------------------------------------------------------------//



    //------------------------------------------------------------------------------------------------//

    T* addTree(const TaskTree& other) {
        for (const auto& now : other.inorderTraversal()) {
            this->add(now.key(), now.value());
        }
    }

    T* eraseTree(const TaskTree& other) {
        for (const auto& now : other.inorderTraversal()) {
            this->erase(now.key());
        }
    }

    //------------------------------------------------------------------------------------------------//



    //------------------------------------------------------------------------------------------------//

    T* commonParent(int key1, int key2) {
        QVector<node_ptr> first;
        getPath(AVLTree<T>::_root, key1, first);
        QVector<node_ptr> second;
        getPath(AVLTree<T>::_root, key2, second);

        T* parent = nullptr;
        int minSize = std::min(first.size(), second.size());

        for (int i = 0; i < minSize; ++i) {
            if (first[i]->key == second[i]->key) {
                parent = &first[i]->value;
            } else {
                break;
            }
        }
        return parent;
    }


private:

    void getPath(node_ptr node, int key, QVector<node_ptr>& path) {
        if (!node) {
            return;
        }

        path.push_back(node->left);

        if (key < node->key) {
            getPath(node->left, path);
        } else if (key > node->key) {
            getPath(node->right, path);
        }
    }

    //------------------------------------------------------------------------------------------------//



    //------------------------------------------------------------------------------------------------//

    void countLeaves(size_t lvl, std::shared_ptr<typename AVLTree<T>::Node> node, QVector<size_t>& leaves) {
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

    //------------------------------------------------------------------------------------------------//



    //------------------------------------------------------------------------------------------------//

    void preorderTraversal(std::shared_ptr<typename AVLTree<T>::Node> node, QVector<QPair<int, T>>& vect) {
        if (node) {
            vect.emplaceBack(node->key, node->value);
            preorderTraversal(node->left, vect);
            preorderTraversal(node->right, vect);
        }
    }

    void postorderTraversal(std::shared_ptr<typename AVLTree<T>::Node> node, QVector<T>& vect) {
        if (node) {
            postorderTraversal(node->left, vect);
            postorderTraversal(node->right, vect);
            vect.emplaceBack(node->key, node->value);
        }
    }

    void inorderTraversal(std::shared_ptr<typename AVLTree<T>::Node> node, QVector<T>& vect) {
        if (node) {
            inorderTraversal(node->left, vect);
            vect.emplaceBack(node->key, node->value);
            inorderTraversal(node->right, vect);
        }
    }

    //------------------------------------------------------------------------------------------------//

    friend MainWindow;
};

#endif // TASKTREE_H
