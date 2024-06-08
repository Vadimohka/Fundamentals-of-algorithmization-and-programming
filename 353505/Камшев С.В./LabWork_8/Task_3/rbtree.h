#ifndef RBTREE_H
#define RBTREE_H

#include "node.h"
#include "iterator.h"
#include "treeiterator.h"
#include <memory>

template <typename K, typename V>
class RBTree {
public:
    RBTree() : root(nullptr) {}

    ~RBTree() {
        clear();
    }

    Iterator<K, V> begin() {
        return Iterator<K, V>(root);
    }

    Iterator<K, V> end() {
        return Iterator<K, V>(nullptr);
    }

    void clear() {
        clear(root);
        root = nullptr;
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    V& get(const K& key) {
        auto node = findNode(key);
        return node->data.second;
    }

    K getMax() const {
        return maximum(root)->data.first;
    }

    std::shared_ptr<Node<K, V>> getRoot() const {
        return root;
    }

    bool containsKey(const K& key) const {
        return findNode(key) != nullptr;
    }

    void traverse(TreeIterator<K, V>* ins) {
        traverseTree(ins, root);
    }

    void insert(const K& key, const V& value) {
        std::shared_ptr<Node<K, V>> currentNode = root;
        std::shared_ptr<Node<K, V>> parentNode = nullptr;

        // Поиск места для нового узла
        while (currentNode) {
            parentNode = currentNode;
            if (key < currentNode->data.first) {
                currentNode = currentNode->left;
            } else if (key > currentNode->data.first) {
                currentNode = currentNode->right;
            } else {
                // Если ключ уже существует, обновляем значение
                currentNode->data.second = value;
                return;
            }
        }

        // Создание нового узла
        std::shared_ptr<Node<K, V>> newNode = std::make_shared<Node<K, V>>(key, value);
        newNode->parent = parentNode;

        // Вставка нового узла
        if (parentNode) {
            if (key < parentNode->data.first) {
                parentNode->left = newNode;
            } else {
                parentNode->right = newNode;
            }
        } else {
            root = newNode;
        }

        // Балансировка дерева после вставки
        insertFixup(newNode);
    }

    void erase(const K& key) {
        auto nodeToDelete = findNode(key);
        if (!nodeToDelete) return;

        // Если у узла два ребенка, ищем предшественника
        if (nodeToDelete->left && nodeToDelete->right) {
            auto predecessorNode = maximum(nodeToDelete->left);
            swapNodeData(nodeToDelete, predecessorNode);
            nodeToDelete = predecessorNode;
        }

        auto childNode = nodeToDelete->left ? nodeToDelete->left : nodeToDelete->right;

        // Если удаляемый узел и его ребенок черные, требуется балансировка
        bool bothBlack = (!nodeToDelete->color && (!childNode || !childNode->color));
        replaceNodeInTree(nodeToDelete, childNode);

        if (childNode) {
            childNode->parent = nodeToDelete->parent;
            if (bothBlack) {
                deleteFixup(childNode);
            } else {
                childNode->color = true; // Черный цвет
            }
        } else if (bothBlack) {
            deleteFixup(nodeToDelete);
        }

        nodeToDelete->left = nullptr;
        nodeToDelete->right = nullptr;
        nodeToDelete->parent.reset();
    }

protected:
    std::shared_ptr<Node<K, V>> root;

    void clear(std::shared_ptr<Node<K, V>> node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        node.reset();
    }

    std::shared_ptr<Node<K, V>> findNode(const K& key) const {
        auto cur = root;
        while (cur) {
            if (key == cur->data.first) return cur;
            if (key < cur->data.first) cur = cur->left;
            else cur = cur->right;
        }
        return nullptr;
    }

    // Балансировка дерева после вставки
    void insertFixup(std::shared_ptr<Node<K, V>> node) {
        while (node->parent.lock() && !node->parent.lock()->color) {
            auto parent = node->parent.lock();
            auto grandparent = parent->parent.lock();
            if (parent == grandparent->left) {
                auto uncle = grandparent->right;
                // Случай 1: Дядя красный
                if (uncle && !uncle->color) {
                    parent->color = true;
                    uncle->color = true;
                    grandparent->color = false;
                    node = grandparent;
                } else {
                    // Случай 2: Узел - правый ребенок
                    if (node == parent->right) {
                        performLeftRotation(parent);
                        node = parent;
                    }
                    // Случай 3: Узел - левый ребенок
                    parent = node->parent.lock();
                    grandparent = parent->parent.lock();
                    parent->color = true;
                    grandparent->color = false;
                    performRightRotation(grandparent);
                }
            } else {
                auto uncle = grandparent->left;
                // Случай 1: Дядя красный
                if (uncle && !uncle->color) {
                    parent->color = true;
                    uncle->color = true;
                    grandparent->color = false;
                    node = grandparent;
                } else {
                    // Случай 2: Узел - левый ребенок
                    if (node == parent->left) {
                        performRightRotation(parent);
                        node = parent;
                    }
                    // Случай 3: Узел - правый ребенок
                    parent = node->parent.lock();
                    grandparent = parent->parent.lock();
                    parent->color = true;
                    grandparent->color = false;
                    performLeftRotation(grandparent);
                }
            }
        }
        root->color = true;
    }

    // Балансировка дерева после удаления
    void deleteFixup(std::shared_ptr<Node<K, V>> node) {
        while (node != root && node->color) {
            auto parent = node->parent.lock();
            if (node == parent->left) {
                auto sibling = parent->right;
                // Случай 1: Брат красный
                if (!sibling->color) {
                    sibling->color = true;
                    parent->color = false;
                    performLeftRotation(parent);
                    sibling = parent->right;
                }
                // Случай 2: Оба ребенка брата черные
                if ((!sibling->left || sibling->left->color) && (!sibling->right || sibling->right->color)) {
                    sibling->color = false;
                    node = parent;
                } else {
                    // Случай 3: Правый ребенок брата черный
                    if (!sibling->right || sibling->right->color) {
                        sibling->left->color = true;
                        sibling->color = false;
                        performRightRotation(sibling);
                        sibling = parent->right;
                    }
                    // Случай 4: Правый ребенок брата красный
                    sibling->color = parent->color;
                    parent->color = true;
                    sibling->right->color = true;
                    performLeftRotation(parent);
                    node = root;
                }
            } else {
                auto sibling = parent->left;
                // Случай 1: Брат красный
                if (!sibling->color) {
                    sibling->color = true;
                    parent->color = false;
                    performRightRotation(parent);
                    sibling = parent->left;
                }
                // Случай 2: Оба ребенка брата черные
                if ((!sibling->left || sibling->left->color) && (!sibling->right || sibling->right->color)) {
                    sibling->color = false;
                    node = parent;
                } else {
                    // Случай 3: Левый ребенок брата черный
                    if (!sibling->left || sibling->left->color) {
                        sibling->right->color = true;
                        sibling->color = false;
                        performLeftRotation(sibling);
                        sibling = parent->left;
                    }
                    // Случай 4: Левый ребенок брата красный
                    sibling->color = parent->color;
                    parent->color = true;
                    sibling->left->color = true;
                    performRightRotation(parent);
                    node = root;
                }
            }
        }
        node->color = true;
    }

    void performLeftRotation(std::shared_ptr<Node<K, V>> x) {
        auto y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;
        if (!x->parent.lock()) root = y;
        else if (x == x->parent.lock()->left) x->parent.lock()->left = y;
        else x->parent.lock()->right = y;
        y->left = x;
        x->parent = y;
    }

    void performRightRotation(std::shared_ptr<Node<K, V>> x) {
        auto y = x->left;
        x->left = y->right;
        if (y->right) y->right->parent = x;
        y->parent = x->parent;
        if (!x->parent.lock()) root = y;
        else if (x == x->parent.lock()->left) x->parent.lock()->left = y;
        else x->parent.lock()->right = y;
        y->right = x;
        x->parent = y;
    }

    std::shared_ptr<Node<K, V>> sibling(const std::shared_ptr<Node<K, V>>& node) const {
        auto parent = node->parent.lock();
        if (!parent) return nullptr;
        return node == parent->left ? parent->right : parent->left;
    }

    void replaceNodeInTree(const std::shared_ptr<Node<K, V>>& oldNode, const std::shared_ptr<Node<K, V>>& newNode) {
        if (!oldNode->parent.lock()) {
            root = newNode;
        } else {
            if (oldNode == oldNode->parent.lock()->left) {
                oldNode->parent.lock()->left = newNode;
            } else {
                oldNode->parent.lock()->right = newNode;
            }
        }
        if (newNode) newNode->parent = oldNode->parent;
    }

    void swapNodeData(const std::shared_ptr<Node<K, V>>& node1, const std::shared_ptr<Node<K, V>>& node2) {
        std::swap(const_cast<K&>(node1->data.first), const_cast<K&>(node2->data.first));
        std::swap(node1->data.second, node2->data.second);
    }

    std::shared_ptr<Node<K, V>> maximum(const std::shared_ptr<Node<K, V>>& node) const {
        auto current = node;
        while (current->right) {
            current = current->right;
        }
        return current;
    }

    void traverseTree(TreeIterator<K, V>* ins, const std::shared_ptr<Node<K, V>>& node) const {
        if (!node) return;
        traverseTree(ins, node->left);
        ins->visit(node);
        traverseTree(ins, node->right);
    }
};

#endif // RBTREE_H
