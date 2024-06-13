#include "tree.h"

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    _destruct(root);
}

Node* Tree::GetTreeRoot()
{
    return root;
}

void Tree::_destruct(Node* node)
{
    if (node != nullptr)
    {
        _destruct(node->left);
        _destruct(node->right);
        delete node;
    }
}

Node* Tree::_insert(Node* node, QPair<int, QString> element)
{
    if (node == nullptr)
    {
        return new Node(element.first, element.second);
    }

    int key = element.first;
    if (key < node->key)
    {
        node->left = _insert(node->left, element);
    }
    else if (key > node->key)
    {
        node->right = _insert(node->right, element);
    }
    else
    {
        node->value = element.second;
    }

    return node;
}

Node* Tree::insert(QPair<int, QString> element)
{
    root = _insert(root, element);
    return root;
}

Node* Tree::_remove(Node* node, int key)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (key < node->key)
    {
        node->left = _remove(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = _remove(node->right, key);
    }
    else
    {
        if (node->left && node->right)
        {
            Node* parent = node;
            Node* successor = node->right;
            while (successor->left != nullptr)
            {
                parent = successor;
                successor = successor->left;
            }
            node->key = successor->key;
            node->value = successor->value;

            if (successor == parent->right)
            {
                parent->right = _remove(successor, successor->key);
            }
            else
            {
                parent->left = _remove(successor, successor->key);
            }
        }
        else if (node->left)
        {
            node = node->left;
        }
        else if (node->right)
        {
            node = node->right;
        }
        else
        {
            node = nullptr;
        }
    }

    return node;
}

void Tree::remove(int key)
{
    root = _remove(root, key);
}

Node* Tree::_search(Node* node, int key)
{
    if (!node || node->key == key)
    {
        return node;
    }

    if (key < node->key)
    {
        return _search(node->left, key);
    }
    else
    {
        return _search(node->right, key);
    }
}

Node* Tree::search(int key)
{
    Node* node = _search(root, key);
    return node;
}

void Tree::_toVector(Node* node, QVector<QPair<int, QString>>& vec)
{
    if (node)
    {
        vec.push_back(QPair<int, QString>(node->key, node->value));
        _toVector(node->left, vec);
        _toVector(node->right, vec);
    }
}

QVector<QPair<int, QString>> Tree::toVector()
{
    QVector<QPair<int, QString>> vec;
    _toVector(root, vec);
    return vec;
}

void Tree::_reverseToVector(Node* node, QVector<QPair<int, QString>>& vec)
{
    if (node)
    {
        _reverseToVector(node->right, vec);
        _reverseToVector(node->left, vec);
        vec.push_back(QPair<int, QString>(node->key, node->value));
    }
}

QVector<QPair<int, QString>> Tree::reverseToVector()
{
    QVector<QPair<int, QString>> vec;
    _reverseToVector(root, vec);
    return vec;
}

void Tree::_byValueToVector(Node* node, QVector<QPair<int, QString>>& vec)
{
    if (node)
    {
        _byValueToVector(node->left, vec);
        vec.push_back(QPair<int, QString>(node->key, node->value));
        _byValueToVector(node->right, vec);
    }
}

QVector<QPair<int, QString>> Tree::byValueToVector()
{
    QVector<QPair<int, QString>> vec;
    _byValueToVector(root, vec);
    return vec;
}

QString Tree::searchValueByKey(int key)
{
    Node* node = _search(root, key);
    if (node != nullptr)
    {
        return node->value;
    }
    else
    {
        return "";
    }
}

Node* Tree::_makeBalanced(QVector<QPair<int, QString>> vec, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    int mid = (left + right) / 2;
    Node* node = new Node(vec[mid].first, vec[mid].second);
    node->left = _makeBalanced(vec, left, mid - 1);
    node->right = _makeBalanced(vec, mid + 1, right);
    return node;
}

void Tree::makeBalanced()
{
    QVector<QPair<int, QString>> vec;
    _byValueToVector(root, vec);
    root = _makeBalanced(vec, 0, vec.size() - 1);
}
