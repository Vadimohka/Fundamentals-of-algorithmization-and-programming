#ifndef MYBST1
#define MYBST1
#include <QtWidgets>
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <stdexcept>
#include <sys/types.h>
#include <vector>

template<typename T>
class BST
{
public:
    struct Node
    {
        int key;
        T value;
        Node *left, *right;
        Node *parent;
    };

protected:
    Node *root = nullptr;
    int sizeOfTree = 0;

    class nodeRef
    {
        Node *node;

    public:
        const T &operator*() const { return node->value; }
        T &operator*() { return node->value; }
        bool is_valid() { return node != nullptr; }

    private:
        nodeRef(Node *_node = nullptr)
            : node(_node)
        {}
        friend class BST<T>;
    };

private:
    Node *newNode(int key, const T &t, Node *parent)
    {
        Node *node = reinterpret_cast<Node *>(new u_int8_t[sizeof(Node)]);
        node->key = key;
        new (&node->value) T(t);
        node->left = nullptr;
        node->right = nullptr;
        node->parent = parent;
        return node;
    }

    Node *newNode(const Node &node, Node *parent)
    {
        Node *new_node = reinterpret_cast<Node *>(new u_int8_t[sizeof(Node)]);
        new (&new_node->value) T(node.value);
        new_node->key = node.key;
        new_node->parent = parent;
        return new_node;
    }

    Node *fromSortedToBalanced(const std::vector<Node> &sorted, long start, long end)
    {
        if (start > end) {
            return nullptr;
        }

        auto midle = (start + end) / 2;

        Node *node = newNode(sorted[midle], nullptr);
        node->left = fromSortedToBalanced(sorted, start, midle - 1);
        node->right = fromSortedToBalanced(sorted, midle + 1, end);

        if (node->left) {
            node->left->parent = node;
        }
        if (node->right) {
            node->right->parent = node;
        }

        return node;
    }

    void _inOrderTraverse(Node *node, std::vector<Node> &vector)
    {
        if (node != nullptr) {
            _inOrderTraverse(node->left, vector);
            vector.push_back(*node);
            _inOrderTraverse(node->right, vector);
        }
    }

    void release_tree(Node *node)
    {
        if (!node) {
            return;
        }
        if (node->left) {
            release_tree(node->left);
        }
        if (node->right) {
            release_tree(node->right);
        }
        delete node;
    }

    Node *_removeNode(Node *node, int key, bool *isNodeRemoved)
    {
        if (!node) {
            *isNodeRemoved = false;
            return node;
        }

        if (key < node->key) {
            node->left = _removeNode(node->left, key, isNodeRemoved);
        } else if (key > node->key) {
            node->right = _removeNode(node->right, key, isNodeRemoved);
        } else {
            *isNodeRemoved = true;
            if (node->left != nullptr && node->right != nullptr) {
                // 2. two children
                Node *successor = node->right;
                Node *parent = node;
                while (successor->left != nullptr) {
                    parent = successor;
                    successor = successor->left;
                }

                node->key = successor->key;
                node->value = successor->value;

                if (successor == parent->right)
                    parent->right = _removeNode(successor, successor->key, isNodeRemoved);
                else
                    parent->left = _removeNode(successor, successor->key, isNodeRemoved);

            } else {
                // 1. one or no children at node
                if (node->left) {
                    auto temp = node->left;
                    temp->parent = node->parent;
                    delete node;
                    node = temp;
                } else if (node->right) {
                    auto tmp = node->right;
                    tmp->parent = node->parent;
                    delete node;
                    node = tmp;
                } else {
                    delete node;
                    return nullptr;
                }
            }
            --sizeOfTree;
        }

        return node;
    }

public:
    BST() = default;
    ~BST()
    {
        release_tree(root);
        root = nullptr;
    }

    void insert(int key, const T &t)
    {
        if (!root) {
            root = newNode(key, t, nullptr);
            ++sizeOfTree;
        } else {
            Node *cur = root;
            while (true) {
                if (key > cur->key) {
                    if (cur->right)
                        cur = cur->right;
                    else {
                        cur->right = newNode(key, t, cur);
                        ++sizeOfTree;
                        return;
                    }
                } else if (key < cur->key) {
                    if (cur->left)
                        cur = cur->left;
                    else {
                        cur->left = newNode(key, t, cur);
                        ++sizeOfTree;
                        return;
                    }
                } else {
                    cur->value = t;
                    return;
                }
            }
        }
    }

    void merge(const BST<T> &other)
    {
        auto vector1 = this->in_order_traverse();
        auto vector2 = other.in_order_traverse();
        vector1.insert(vector1.end(), vector2.begin(), vector2.end());
        std::sort(vector1.begin(), vector1.end());
        release_tree(root);
        root = fromSortedToBalanced(vector1, 0, vector1.size() - 1);
    }

    nodeRef search(int key)
    {
        if (!root) {
            return nodeRef();
        }
        Node *currentNode = root;
        while (currentNode->left != nullptr || currentNode->right != nullptr) {
            if (key > currentNode->key) {
                if (currentNode->right)
                    currentNode = currentNode->right;
                else
                    return nodeRef();
            } else if (key < currentNode->key) {
                if (currentNode->left)
                    currentNode = currentNode->left;
                else
                    return nodeRef();
            } else {
                return nodeRef(currentNode);
            }
        }

        if (currentNode->key == key) {
            return nodeRef(currentNode);
        } else {
            return nodeRef(nullptr);
        }
    }

    std::vector<Node> in_order_traverse()
    {
        std::vector<Node> res;
        _inOrderTraverse(root, res);
        return std::move(res);
    }

    void balance()
    {
        if (!root) {
            return;
        }

        std::vector<Node> traverse;
        traverse.reserve(sizeOfTree);

        _inOrderTraverse(root, traverse);
        release_tree(root);
        root = fromSortedToBalanced(traverse, 0, traverse.size() - 1);
        root->parent = nullptr;
    }

    bool remove(int key)
    {
        bool is_removed;
        root = _removeNode(root, key, &is_removed);
        return is_removed;
    }

    int size() { return sizeOfTree; }
};

template<typename T>
class BSTWithDepth : public BST<T>
{
private:
    long _depth(BST<T>::Node *node)
    {
        if (!node) {
            return 0;
        }
        return std::max(1 + _depth(node->left), 1 + _depth(node->right));
    }

public:
    long depth() { return _depth(BST<T>::root); }
};

class BSTGui : public BSTWithDepth<QString>
{
public:
    static const int max_size = 50;

    QTreeWidgetItem *myNodeToTreeItem(BSTWithDepth<QString>::Node *nd)
    {
        auto item = new QTreeWidgetItem;
        item->setText(0, QString("%1: %2").arg(nd->key).arg(nd->value));

        if (nd->left) {
            item->addChild(myNodeToTreeItem(nd->left));
        }
        if (nd->right) {
            item->addChild(myNodeToTreeItem(nd->right));
        }

        return item;
    }

    void setUpTreeWidget(QTreeWidget *tree)
    {
        tree->clear();
        if (root) {
            tree->insertTopLevelItem(0, myNodeToTreeItem(root));
        }
        tree->expandAll();
    }

    char generateRandomLetter()
    {
        // Список доступных букв
        const std::string letters = "abcdefghijklmnopqrstuvwxyz";

        // Генерируем случайный индекс в диапазоне от 0 до 25
        int randomIndex = std::rand() % letters.length();

        // Возвращаем букву по случайному индексу
        return letters[randomIndex];
    }

    void initializeRand()
    {
        BSTWithDepth<QString>::~BSTWithDepth();
        for (int i = 0; i < max_size; ++i) {
            insert(QRandomGenerator::global()->bounded(50),
                   QString("").append(generateRandomLetter()).append(generateRandomLetter()));
        }
    }
};
#endif /* MYBST1 */
