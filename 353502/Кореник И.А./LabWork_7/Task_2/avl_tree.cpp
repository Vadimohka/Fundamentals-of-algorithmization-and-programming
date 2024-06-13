#include "avl_tree.h"

AVL_Tree::AVL_Tree(QVector<QPair<int, QString>> initial)
{
    for (auto elem : initial){
        this->insert(elem.first, elem.second);
    }
    //balance();
}

AVL_Tree::AVL_Tree() {}

void AVL_Tree::insert(int key, QString info)
{
    if (find(key) == "")
        insertInTree(key, info, root);
}

void AVL_Tree::erase(int key)
{
    Node* a = nullptr;
    eraseFromTree(key, root, a, 1);
}

QString AVL_Tree::find(int key)
{
    return findInTree(key, root);
}

void AVL_Tree::balance()
{
    //while(!isBalanced(root))
    balanceTreeHelper(root);
    QCoreApplication::processEvents();
    QThread::msleep(100);
}

void AVL_Tree::insertInTree(int key, QString info, Node *&node)
{
    if (node == nullptr) node = new Node(info, key);
    else if (key <= node->key) insertInTree(key, info, node->leftSon);
    else insertInTree(key, info, node->rightSon);
}

void AVL_Tree::eraseFromTree(int key, Node *node, Node *&parent, int side)
{
    if (node == nullptr) return;

    if (key < node->key) {
        eraseFromTree(key, node->leftSon, node, -1);
    } else if (key > node->key) {
        eraseFromTree(key, node->rightSon, node, 1);
    } else {

        if (node->leftSon == nullptr && node->rightSon == nullptr) {
            if (parent == nullptr) {
                delete node;
                root = nullptr;
            } else {
                if (side == -1) parent->leftSon = nullptr;
                else if (side == 1) parent->rightSon = nullptr;
                delete node;
            }
        }

        else if (node->leftSon == nullptr) {
            Node* temp = node;
            if (parent == nullptr) {
                root = node->rightSon;
                delete temp;
            } else {
                if (side == -1) parent->leftSon = node->rightSon;
                else if (side == 1) parent->rightSon = node->rightSon;
                delete temp;
            }
        } else if (node->rightSon == nullptr) {
            Node* temp = node;
            if (parent == nullptr) {
                root = node->leftSon;
                delete temp;
            } else {
                if (side == -1) parent->leftSon = node->leftSon;
                else if (side == 1) parent->rightSon = node->leftSon;
                delete temp;
            }
        }

        else {
            Node* successor = findMin(node->rightSon);
            node->key = successor->key;
            node->data = successor->data;
            eraseFromTree(successor->key, node->rightSon, node, 1);
        }
    }
}

QString AVL_Tree::findInTree(int key, Node *node)
{
    if (node == nullptr) return "";
    if (node->key == key) return node->data;
    if (key > node->key) return findInTree(key, node->rightSon);
    else return findInTree(key, node->leftSon);
}

Node *AVL_Tree::findMin(Node *node){
    while(node->leftSon != nullptr)
        node = node->leftSon;
    return node;
}

void AVL_Tree::balanceTreeHelper(Node *&node)
{
    if (node == nullptr) return;

    int balanceFactor = height(node->leftSon) - height(node->rightSon);

    if (balanceFactor > 1) {
        if (height(node->leftSon->leftSon) >= height(node->leftSon->rightSon)) {
            rotateRight(node);
        } else {
            rotateLeft(node->leftSon);
            rotateRight(node);
        }
    }
    else if (balanceFactor < -1) {
        if (height(node->rightSon->rightSon) >= height(node->rightSon->leftSon)) {
            rotateLeft(node);
        } else {
            rotateRight(node->rightSon);
            rotateLeft(node);
        }
    }

    balanceTreeHelper(node->leftSon);
    balanceTreeHelper(node->rightSon);
}

int AVL_Tree::height(Node *node) {
    if (node == nullptr) return 0;
    return 1 + std::max(height(node->leftSon), height(node->rightSon));
}

void AVL_Tree::rotateLeft(Node *&node) {
    Node* temp = node->rightSon;
    node->rightSon = temp->leftSon;
    temp->leftSon = node;
    node = temp;
}

void AVL_Tree::rotateRight(Node *&node) {
    Node* temp = node->leftSon;
    node->leftSon = temp->rightSon;
    temp->rightSon = node;
    node = temp;
}

bool AVL_Tree::isBalanced(Node*& node)
{
    if (node == nullptr) return true;

    int balanceFactor = height(node->leftSon) - height(node->rightSon);

    if (abs(balanceFactor) > 1) return false;

    return isBalanced(node->leftSon) && isBalanced(node->rightSon);
}

