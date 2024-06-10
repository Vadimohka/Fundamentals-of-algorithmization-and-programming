#ifndef BST_H
#define BST_H

#include <QDebug>
#include <QTreeWidget>

template <typename T>
struct Node {
    int key;
    T data;
    Node* left{nullptr};
    Node* right{nullptr};
    int height{1};
    Node(int key, T data) : key(key), data(data) {}
};

template <typename T>
class BST
{
public:
    BST();
    BST(QVector<QPair<int, T>>);

    int getHeight(Node<T> *node);
    void updateHeight(Node<T> *node);
    int getBalanceFactor(Node<T> *node);
    void swap(Node<T> *a, Node<T> *b);
    void rightRotate(Node<T> *&node);
    void leftRotate(Node<T> *&node);
    void balance(Node<T> *&node);
    void balance();
    Node<T>* findMax(Node<T> *node);
    void update(QTreeWidget *tree);

    Node<T>* getRoot() { return root; }

    void insert(Node<T> *&node, int key, T data);
    void insert(int key, T data);
    Node<T>* remove(Node<T> *&node, int key);
    void remove(int key);
    void clear();
    T search(Node<T> *node, int key);
    T search(int key);
    QString preOrder(Node<T> *node);
    QString inOrder(Node<T> *node);
    QString postOrder(Node<T> *node);

    QString countLeavesPerLevel(Node<T> *node);
    void countLeavesPerLevel(Node<T> *node, int level, QVector<int> &counts);

    void addNodeToTree(int key, T data, QTreeWidget *tree);
    void addNodeToTree(Node<T>* node, QTreeWidgetItem *parentItem, QString prefix);

private:
    Node<T>* root{nullptr};
};

template<typename T>
BST<T>::BST() : root(nullptr) {}

template<typename T>
BST<T>::BST(QVector<QPair<int, T>> input) : root(nullptr)
{
    if (input.isEmpty()) return;
    root = new Node<T>(input[0].first, input[0].second);
    for (int i = 1; i < input.size(); ++i) {
        insert(root, input[i].first, input[i].second);
    }
}

template<typename T>
int BST<T>::getHeight(Node<T> *node)
{
    return node == nullptr ? -1 : node->height;
}

template<typename T>
void BST<T>::updateHeight(Node<T> *node)
{
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

template<typename T>
int BST<T>::getBalanceFactor(Node<T> *node)
{
    return (node == nullptr) ? 0 : getHeight(node->right) - getHeight(node->left);
}

template<typename T>
void BST<T>::swap(Node<T> *a, Node<T> *b)
{
    int a_key = a->key;
    a->key = b->key;
    b->key = a_key;
    T a_data = a->data;
    a->data = b->data;
    b->data = a_data;
}

template<typename T>
void BST<T>::rightRotate(Node<T> *&node)
{
    Node<T> *leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;
    node = leftChild;

    updateHeight(node->right);
    updateHeight(node);
}

template<typename T>
void BST<T>::leftRotate(Node<T> *&node)
{
    Node<T> *rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;
    node = rightChild;

    updateHeight(node->left);
    updateHeight(node);
}

template<typename T>
void BST<T>::balance(Node<T> *&node)
{
    if (node == nullptr) return;

    updateHeight(node);

    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor == -2) {
        if (getBalanceFactor(node->left) == 1) leftRotate(node->left);
        rightRotate(node);
    } else if (balanceFactor == 2) {
        if (getBalanceFactor(node->right) == -1) rightRotate(node->right);
        leftRotate(node);
    }

    if (node->left != nullptr) balance(node->left);
    if (node->right != nullptr) balance(node->right);
}

template<typename T>
void BST<T>::balance()
{
    balance(root);
}

template<typename T>
Node<T> *BST<T>::findMax(Node<T> *node)
{
    return node->right == nullptr ? node : findMax(node->right);
}

template<typename T>
void BST<T>::update(QTreeWidget *tree)
{
    balance();
    tree->clear();
    auto* item = new QTreeWidgetItem(tree);
    addNodeToTree(root, item, "");
}

template<typename T>
void BST<T>::insert(Node<T> *&node, int key, T data)
{
    if (key < node->key) {
        if (node->left == nullptr) {
            node->left = new Node<T>(key, data);
        } else {
            insert(node->left, key, data);
        }
    } else if (key >= node->key) {
        if (node->right == nullptr) {
            node->right = new Node<T>(key, data);
        } else {
            insert(node->right, key, data);
        }
    }

    // updateHeight(node);
    // balance(node);
}

template<typename T>
void BST<T>::insert(int key, T data)
{
    if (root == nullptr) {
        root = new Node<T>(key, data);
    } else {
        insert(root, key, data);
    }
}

template<typename T>
Node<T>* BST<T>::remove(Node<T> *&node, int key)
{
    if (node == nullptr) return nullptr;
    else if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            node = (node->left == nullptr) ? node->right : node->left;
        } else {
            Node<T>* maxInLeft = findMax(node->left);
            node->key = maxInLeft->key;
            node->data = maxInLeft->data;
            node->left = remove(node->left, maxInLeft->key);
        }
    }

    if (node != nullptr) {
        updateHeight(node);
        balance(node);
    }
    return node;
}

template<typename T>
void BST<T>::remove(int key)
{
    root = remove(root, key);
}

template<typename T>
void BST<T>::clear()
{
    while (root != nullptr) {
        root = remove(root, root->key);
    }
}

template<typename T>
T BST<T>::search(Node<T> *node, int key)
{
    if (node == nullptr) return T();
    if (key == node->key) return node->data;
    if (key < node->key) return search(node->left, key);
    return search(node->right, key);
}

template<typename T>
T BST<T>::search(int key)
{
    return search(root, key);
}

template<typename T>
QString BST<T>::preOrder(Node<T> *node)
{
    if (node == nullptr) return "";
    QString result;
    QTextStream stream(&result);
    stream << node->key << " ";
    stream << preOrder(node->left);
    stream << preOrder(node->right);
    return result;
}

template<typename T>
QString BST<T>::inOrder(Node<T> *node)
{
    if (node == nullptr) return "";
    QString result;
    QTextStream stream(&result);
    stream << inOrder(node->left);
    stream << node->key << " ";
    stream << inOrder(node->right);
    return result;
}

template<typename T>
QString BST<T>::postOrder(Node<T> *node)
{
    if (node == nullptr) return "";
    QString result;
    QTextStream stream(&result);
    stream << postOrder(node->left);
    stream << postOrder(node->right);
    stream << node->key << " ";
    return result;
}

template<typename T>
QString BST<T>::countLeavesPerLevel(Node<T> *node)
{
    QVector<int> counts;
    countLeavesPerLevel(node, 0, counts);

    QString result;
    QTextStream stream(&result);
    for (int i = 0; i < counts.size(); ++i) {
        stream << "Уровень " << i << ": " << counts[i] << " листьев\n";
    }
    return result;
}

template<typename T>
void BST<T>::countLeavesPerLevel(Node<T>* node, int level, QVector<int>& counts)
{
    if (node == nullptr) {
        return;
    }
    if (level == counts.size()) {
        counts.push_back(0);
    }
    if (node->left == nullptr && node->right == nullptr) {
        ++counts[level];
    }
    countLeavesPerLevel(node->left, level + 1, counts);
    countLeavesPerLevel(node->right, level + 1, counts);
}

template<typename T>
void BST<T>::addNodeToTree(int key, T data, QTreeWidget *tree)
{
    insert(key, data);
    tree->clear();
    auto* item = new QTreeWidgetItem(tree);
    addNodeToTree(root, item, "");
}

template<typename T>
void BST<T>::addNodeToTree(Node<T> *node, QTreeWidgetItem *parentItem, QString prefix)
{
    if (node != nullptr) {
        if (node == root) {
            prefix = "Root: ";
        }
        if (parentItem != nullptr) {
            parentItem->setText(0, prefix + QString::number(node->key));
        }

        if (node->left != nullptr) {
            QTreeWidgetItem *leftItem = new QTreeWidgetItem();
            parentItem->addChild(leftItem);
            addNodeToTree(node->left, leftItem, "Left: ");
        }

        if (node->right != nullptr) {
            QTreeWidgetItem *rightItem = new QTreeWidgetItem();
            parentItem->addChild(rightItem);
            addNodeToTree(node->right, rightItem, "Right: ");
        }
    }
}

#endif // BST_H
