#ifndef AVLTREE_H
#define AVLTREE_H

#include <memory>

class MainWindow;

template <class T>
class AVLTree {
protected:

    //------------------------------------------------------------------------------------------------//

    struct Node {
        template <class ... Args>
        Node(int key, Args&& ... args) : key(key), value(std::forward<Args>(args)...) {}

        std::shared_ptr<Node> left = nullptr;
        std::shared_ptr<Node> right = nullptr;

        int key;
        T value;

        size_t h = 1;
    };

    std::shared_ptr<Node> _root = nullptr;
    size_t _size = 0;

    //------------------------------------------------------------------------------------------------//



    //------------------------------------------------------------------------------------------------//

    template <class ... Args>
    std::shared_ptr<Node> insert(std::shared_ptr<Node> node, int key, Args&& ... args) {
        if (!node) {
            ++_size;
            return std::make_shared<Node>(key, std::forward<Args>(args)...);
        }
        if (key > node->key) {
            node->right = insert(node->right, key, std::forward<Args>(args)...);
        } else if (key < node->key) {
            node->left = insert(node->left, key, std::forward<Args>(args)...);
        } else {
            return node;
        }

        node->h = std::max(height(node->left), height(node->right)) + 1;
        return balance(node);
    }

    std::shared_ptr<Node> erase(std::shared_ptr<Node> node, int key) {
        if (!node) {
            return node; // there is nothing we can do ~french music~
        }
        if (key < node->key) {
            node->left = erase(node->left, key);
        } else if (key > node->key) {
            node->right = erase(node->right, key);
        } else {
            if (node->left && node->right) {
                auto min = node->right;
                while (min->left) {
                    min = min->left;
                }
                node->key = min->key;
                node->value = min->value;
                node->right = erase(node->right, min->key);
            } else {
                node = (node->left) ? node->left : node->right;
                --_size;
            }
        }

        if (node) {
            node->h = std::max(height(node->left), height(node->right)) + 1;
            return balance(node);
        }
        return nullptr;
    }

    //------------------------------------------------------------------------------------------------//



    //------------------------------------------------------------------------------------------------//

    std::shared_ptr<Node> leftRotate(std::shared_ptr<Node> node) {
        auto retNode = node->right;
        node->right = retNode->left;
        retNode->left = node;
        node->h = std::max(height(node->left), height(node->right)) + 1;
        retNode->h = std::max(height(retNode->left), height(retNode->right)) + 1;
        return retNode;
    }

    std::shared_ptr<Node> rightRotate(std::shared_ptr<Node> node) {
        auto retNode = node->left;
        node->left = retNode->right;
        retNode->right = node;
        node->h = std::max(height(node->left), height(node->right)) + 1;
        retNode->h = std::max(height(retNode->left), height(retNode->right)) + 1;
        return retNode;
    }

    //------------------------------------------------------------------------------------------------//



    //------------------------------------------------------------------------------------------------//

    std::shared_ptr<Node> balance(std::shared_ptr<Node> node) {
        int bf = balanceFactor(node);
        if (bf > 1) {
            if (balanceFactor(node->left) < 0) {
                node->left = leftRotate(node->left);
            }
            return rightRotate(node);
        } else if (bf < -1) {
            if (balanceFactor(node->right) > 0) {
                node->right = rightRotate(node->right);
            }
            return leftRotate(node);
        }
        return node;
    }

    int balanceFactor(std::shared_ptr<Node> node) {
        return height(node->left) - height(node->right);
    }

    size_t height(std::shared_ptr<Node> node) {
        return (node ? node->h : 0);
    }

    //------------------------------------------------------------------------------------------------//

public:

    //------------------------------------------------------------------------------------------------//

    AVLTree() = default;

    AVLTree(AVLTree&& other) noexcept : _root(std::move(other._root)), _size(other._size) {
        other._size = 0;
    }

    AVLTree& operator=(AVLTree&& other) noexcept {
        if (this != &other) {
            _root = std::move(other._root);
            _size = other._size;
            other._size = 0;
        }
        return *this;
    }

    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;

    ~AVLTree() = default;

    //------------------------------------------------------------------------------------------------//



    //------------------------------------------------------------------------------------------------//

    template <class TT>
    void add(int key, TT&& value) {
        emplace(key, std::forward<TT>(value));
    }

    void erase(int key) {
        _root = erase(_root, key);
    }

    template <class ... Args>
    void emplace(int key, Args&& ... args) {
        _root = insert(_root, key, std::forward<Args>(args)...);
    }

    T* find(int key) {
        std::shared_ptr<Node> node = _root;
        while (node) {
            if (key > node->key) {
                node = node->right;
            } else if (key < node->key) {
                node = node->left;
            } else {
                return &node->value;
            }
        }
        return nullptr;
    }

    size_t size() const {
        return _size;
    }

    //------------------------------------------------------------------------------------------------//

    friend MainWindow;
};

#endif // AVLTREE_H
