#include "bst.h"

BST::BST() = default;

BST::BST(QPair<QVector<int>, QVector<QString>> pair)
{
    for (int i = 0; i < pair.first.size(); i++) {
        insert(pair.first[i], pair.second[i]);
    }
}

void BST::insert(int key, QString value)
{
    if (root == nullptr) {
        root = new Node(key, value);
    } else {
        insert(root, key, value);
    }
}

QString BST::search(int key)
{
    return search(root, key);
}

void BST::remove(int key)
{
    remove(root, key);
}

void BST::printTree(QPair<QVector<int>, QVector<QString>> &pair)
{
    printTree(root, pair);
}

void BST::reversePrint(QPair<QVector<int>, QVector<QString>> &pair)
{
    reversePrint(root, pair);
}

void BST::directPrint(QPair<QVector<int>, QVector<QString>> &pair)
{
    directPrint(root, pair);
}

void BST::buildTreeWidget(QTreeWidget *treeWidget)
{
    treeWidget->clear();
    treeWidget->setColumnCount(2);
    treeWidget->setHeaderLabels(QStringList() << "Key"
                                              << "Value");
    if (root) {
        addNode(root, nullptr, treeWidget);
    }
    QTreeWidgetItemIterator it(treeWidget);
    while (*it) {
        (*it)->setExpanded(true);
        ++it;
    }
}

QString BST::findMiddleKeyValue()
{
    QPair<QVector<int>, QVector<QString>> pair;
    printTree(pair);
    size_t sum = 0;
    for (int key : pair.first) {
        sum += key;
    }
    sum /= pair.first.size();
    int key = pair.first[0];
    int def = qAbs(sum - key);
    for (int i : pair.first) {
        if (qAbs(i - static_cast<int>(sum)) < def) {
            key = i;
            def = qAbs(i - sum);
        }
    }
    return search(key);
}

void BST::balance()
{
    Node *oldRoot = nullptr;
    do {
        oldRoot = root;
        root = balanceTree(root);
    } while (oldRoot != root);
}

Node *BST::getMin(Node *node)
{
    if (node == nullptr) {
        return nullptr;
    }
    if (node->left == nullptr) {
        return node;
    }
    return getMin(node->left);
}

Node *BST::getMax(Node *node)
{
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right == nullptr) {
        return node;
    }
    return getMax(node->right);
}

void BST::insert(Node *node, int key, QString value)
{
    if (key < node->key) {
        if (node->left == nullptr) {
            node->left = new Node(key, value);
        } else {
            insert(node->left, key, value);
        }
    } else if (key > node->key) {
        if (node->right == nullptr) {
            node->right = new Node(key, value);
        } else {
            insert(node->right, key, value);
        }
    } else {
        node->value = value;
    }
    updateHeight(node);
}

QString BST::search(Node *node, int key)
{
    if (node == nullptr) {
        return "";
    }
    if (node->key == key) {
        return node->value;
    }
    return (key < node->key) ? search(node->left, key) : search(node->right, key);
}

Node *BST::remove(Node *node, int key)
{
    if (node == nullptr) {
        return nullptr;
    } else if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (node->left == nullptr && node->right != nullptr) {
            Node temp = *node->right;
            delete node->right;
            node->right = nullptr;
            *node = temp;
        } else if (node->right == nullptr && node->left != nullptr) {
            Node temp = *node->left;
            delete node->left;
            node->left = nullptr;
            *node = temp;
        } else if (node->left == nullptr && node->right == nullptr) {
            delete node;
            if (node == root) {
                root = nullptr;
            }
            node = nullptr;
        } else {
            Node maxLnLeft = *getMax(node->left);
            node->key = maxLnLeft.key;
            node->value = maxLnLeft.value;
            node->left = remove(node->left, maxLnLeft.key);
        }
    }
    if (node) {
        updateHeight(node);
    }

    return node;
}

void BST::printTree(Node *node, QPair<QVector<int>, QVector<QString>> &pair)
{
    if (node == nullptr) {
        return;
    }
    printTree(node->left, pair);
    pair.second.push_back(node->value);
    pair.first.push_back(node->key);
    printTree(node->right, pair);
}

void BST::reversePrint(Node *node, QPair<QVector<int>, QVector<QString>> &pair)
{
    if (node == nullptr) {
        return;
    }
    reversePrint(node->left, pair);
    reversePrint(node->right, pair);
    pair.first.push_back(node->key);
    pair.second.push_back(node->value);
}

void BST::directPrint(Node *node, QPair<QVector<int>, QVector<QString>> &pair)
{
    if (node == nullptr) {
        return;
    }
    pair.first.push_back(node->key);
    pair.second.push_back(node->value);
    directPrint(node->left, pair);
    directPrint(node->right, pair);
}

void BST::deleteTree(Node *node)
{
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
    node = nullptr;
}

void BST::addNode(Node *node, QTreeWidgetItem *parentItem, QTreeWidget *treeWidget)
{
    QTreeWidgetItem *treeItem = nullptr;
    if (parentItem == nullptr) {
        treeItem = new QTreeWidgetItem(treeWidget);
    } else {
        treeItem = new QTreeWidgetItem(parentItem);
    }
    treeItem->setText(0, QString::number(node->key));
    treeItem->setText(1, node->value);

    if (node->left) {
        addNode(node->left, treeItem, treeWidget);
    }
    if (node->right) {
        addNode(node->right, treeItem, treeWidget);
    }
}

int BST::height(Node *node)
{
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int BST::getBalance(Node *node)
{
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node *BST::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *BST::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *BST::balanceTree(Node *root)
{
    if (root == nullptr) {
        return nullptr;
    }

    int balance = getBalance(root);

    if (balance > 1) {
        if (getBalance(root->left) >= 0) {
            return rightRotate(root);
        } else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    } else if (balance < -1) {
        if (getBalance(root->right) <= 0) {
            return leftRotate(root);
        } else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    root->left = balanceTree(root->left);
    root->right = balanceTree(root->right);

    return root;
}

int BST::updateHeight(Node *node)
{
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = updateHeight(node->left);
    int rightHeight = updateHeight(node->right);

    node->height = 1 + std::max(leftHeight, rightHeight);
    return node->height;
}

Node *BST::getRoot()
{
    return root;
}
