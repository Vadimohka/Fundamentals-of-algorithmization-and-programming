#ifndef BST_H
#define BST_H

#include <QVector>
#include <node.h>

template<typename T>
class BST
{
    Node<T> *root;

    void _addNodeFromOther(const Node<T>* other)
    {
        add(other->key, other->value);
        if (other->left)
        {
            _addNodeFromOther(other->left);
        }
        if (other->right)
        {
            _addNodeFromOther(other->right);
        }
    }

    void _removeNodeFromOther(const Node<T>* other)
    {
        remove(other->key);
        if (other->left)
        {
            _removeNodeFromOther(other->left);
        }
        if (other->right)
        {
            _removeNodeFromOther(other->right);
        }
    }

    void _traverse(Node<T>* node, QVector<T>& vec)
    {
        if (node)
        {
            _traverse(node->left, vec);
            vec.push_back(node->value);
            _traverse(node->right, vec);
        }
    }

    void _destruct(Node<T>* node)
    {
        if (node)
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    long long _countNodes(const Node<T> *root) const
    {
        if (!root)
        {
            return 0;
        }
        return _countNodes(root->left) + _countNodes(root->right) + 1;
    }

public:
    BST()
    {
        root = nullptr;
    }

    BST(const BST& other)
    {
        if (other.root)
        {
            _addNodeFromOther(other.root);
        }
    }

    BST(BST&& other)
    {
        root = other.root;
        other.root = nullptr;
    }

    ~BST()
    {
        if (root)
        {
            delete root;
        }
    }

    Node<T>* getRoot()
    {
        return root;
    }

    long long size()
    {
        return _countNodes(root);
    }

    void clear()
    {
        _destruct(root);
    }

    T& find(long long key)
    {
        Node<T> *search = root;
        while (search)
        {
            if (search->key == key)
            {
                return search->value;
            }

            if (key < search->key)
            {
                search = search->left;
            }
            else
            {
                search = search->right;
            }
        }

        throw new std::invalid_argument("No element with such key found");
    }

    Node<T>* findCommonNode(Node<T>* node1, Node<T>* node2)
    {
        Node<T>* search = root;
        while (search)
        {
            if (search == node1 || search == node2)
            {
                return search;
            }

            if (node1->key < search->key && node2->key < search->key)
            {
                search = search->left;
            }
            else if (node1->key > search->key && node2->key > search->key)
            {
                search = search->right;
            }
            else
            {
                return search;
            }
        }
        return nullptr;
    }

    QVector<T> traverse()
    {
        QVector<T> vec;
        _traverse(root, vec);
        return vec;
    }

    void add(long long key, const T& value)
    {
        Node<T>** target = &root;
        while (*target)
        {
            long long tKey = (*target)->key;
            if (tKey == key)
            {
                (*target)->value = value;
                return;
            }
            else if (key < (*target)->key)
            {
                target = &(*target)->left;
            }
            else
            {
                target = &(*target)->right;
            }
        }

        *target = new Node<T> (key, value);
    }

    void remove(long long key)
    {
        Node<T>** parentBeforeDeletion = &root;
        while (parentBeforeDeletion)
        {
            if ((*parentBeforeDeletion)->key == key)
            {
                break;
            }
            if (key < (*parentBeforeDeletion)->key)
            {
                parentBeforeDeletion = &(*parentBeforeDeletion)->left;
            }
            else
            {
                parentBeforeDeletion = &(*parentBeforeDeletion)->right;
            }
        }
        if (!*parentBeforeDeletion)
        {
            return;
        }

        Node<T>* toDelete = *parentBeforeDeletion;
        if (toDelete->key != key)
        {
            return;
        }

        Node<T>* replacement;
        if (!toDelete->left)
        {
            replacement = toDelete->right;
        }
        else if (!toDelete->right)
        {
            replacement = toDelete->left;
        }
        else
        {
            Node<T>** rightmostFromLeft = &toDelete->left;
            while ((*rightmostFromLeft)->right)
            {
                rightmostFromLeft = &(*rightmostFromLeft)->right;
            }
            replacement = *rightmostFromLeft;
            *rightmostFromLeft = replacement->left;

            replacement->left = toDelete->left;
            replacement->right = toDelete->right;
        }
        *parentBeforeDeletion = replacement;
        toDelete->left = nullptr;
        toDelete->right = nullptr;
        delete toDelete;
        return;
    }

    void addTree(const BST& other)
    {
        if (other.root)
        {
            _addNodeFromOther(other.root);
        }
    }

    void removeTree(const BST& other)
    {
        if (other.root)
        {
            _removeNodeFromOther(other.root);
        }
    }

    void addSubTree(const Node<T>* other)
    {
        if (other)
        {
            _addNodeFromOther(other);
        }
    }

    void removeSubTree(const Node<T>* other)
    {
        if (other)
        {
            _removeNodeFromOther(other);
        }
    }
};

#endif // BST_H
