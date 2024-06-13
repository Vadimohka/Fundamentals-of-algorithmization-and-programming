#ifndef TREE_H
#define TREE_H

#include <QVector>

template <typename T>

struct Node
{
    int key;
    Node<T> *left;
    Node<T> *right;
    T data;

    Node(int key, T value): key(key), data(value)
    {
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class Tree
{
public:
    Tree(): root(nullptr){}

    void add(int key, T value)
    {
        if(!find(key))
        {
            root = addElement(root, key, value);
        }

    }

    void remove(int key)
    {
        root = removeElement(root, key);
    }

    bool find(int key)
    {
        return findElement(root, key);
    }

    QVector<int> inOrderTraverse()
    {
        QVector<int> keys;
        inOrderTraverseElemnts(root, keys);
        return keys;
    }

    QVector<int> postOrderTraverse()
    {
        QVector<int> keys;
        postOrderTraverseElements(root, keys);
        return keys;
    }

    QVector<int> preOrderTraverse()
    {
        QVector<int> keys;
        preOrderTraverseElements(root, keys);
        return keys;
    }

    void insert(Node<T> *subtree)
    {
        if(subtree == nullptr )
        {
            return ;
        }
        insertSubtree(subtree);
    }

    void deleteSubtree(Node<T> *subtree)
    {
        if(subtree == nullptr)
        {
            return ;
        }
        removeSubtree(subtree);
    }

    Node<T> *findTheSmallestCommonAncestor(int key1, int key2)
    {
        return findTheSmallestCommonAncestorOfTwoNodes(root, key1, key2);
    }

    Node<T> *getRoot()
    {
        return root;
    }

private:
    Node<T> *root;

    Node<T> *addElement(Node<T> *anotherNode, int key, T value)
    {
        if(anotherNode == nullptr)
        {
            return new Node<T>(key, value);
        }
        // if(key < anotherNode->key)
        // {
        //     anotherNode->left = addElement(anotherNode->left, key, value);
        // }
        // if(key > anotherNode->key)
        // {
        //     anotherNode->right = addElement(anotherNode->right, key, value);
        // }
        if(value < anotherNode->data)
        {
            anotherNode->left = addElement(anotherNode->left, key, value);
        }
        if(value > anotherNode->data)
        {
            anotherNode->right = addElement(anotherNode->right, key, value);
        }
        return anotherNode;
    }

    bool findElement(Node<T> *node, int key)
    {
        if(node == nullptr)
        {
            return false;
        }
        if(key == node->key)
        {
            return true;
        }
        else if(key < node->key)
        {
            return findElement(node->left, key);
        }
        else
        {
            return findElement(node->right, key);
        }
    }

    Node<T> *findMinimum(Node<T> *node)
    {
        while(node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    Node<T> *removeElement(Node<T> *node, int key)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
        if(key < node->key)
        {
            node->left = removeElement(node->left, key);
        }
        else if(key > node->key)
        {
            node->right = removeElement(node->right, key);
        }
        else
        {
            if(node->left == nullptr)
            {
                Node<T> *temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == nullptr)
            {
                Node<T> *temp = node->left;
                delete node;
                delete temp;
            }
            Node<T> *temp = findMinimum(node->right);
            node->key = temp->key;
            node->data = temp->data;
            node->right = removeElement(node->right, temp->key);
        }
        return node;
    }

    void inOrderTraverseElemnts(Node<T> *node, QVector<int> &keys)
    {
        if(node != nullptr)
        {
            keys.append(node->key);
            inOrderTraverseElemnts(node->left, keys);
            keys.push_back(node->key);
            inOrderTraverseElemnts(node->left, keys);
            inOrderTraverseElemnts(node->right, keys);
        }
    }

    void postOrderTraverseElements(Node<T> *node, QVector<int> &keys)
    {
        if(node != nullptr)
        {
            postOrderTraverseElements(node->left, keys);
            postOrderTraverseElements(node->right, keys);
            keys.append(node->key);
        }
    }

    void preOrderTraverseElements(Node<T> *node, QVector<int> &keys)
    {
        if(node != nullptr)
        {
            keys.append(node->key);
            preOrderTraverseElements(node->left, keys);
            preOrderTraverseElements(node->right, keys);
        }
    }

    void removeSubtree(Node<T> *subtree)
    {
        root = removeElement(root, subtree->key);
        if(subtree->right)
        {
            removeSubtree(subtree->right);
        }
        if(subtree->left)
        {
            removeSubtree(subtree->left);
        }
    }

    void insertSubtree(Node<T> *subtree)
    {
        root = addElement(root, subtree->key, subtree->data);
        if(subtree->right)
        {
            insertSubtree(subtree->right);
        }
        if(subtree->left)
        {
            insertSubtree(subtree->left);
        }
    }

    Node<T> *findTheSmallestCommonAncestorOfTwoNodes(Node<T> *node, int key1, int key2)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
        if(node->key > key1 && node->key > key2)
        {
            return findTheSmallestCommonAncestorOfTwoNodes(node->left, key1, key2);
        }
        if(node->key < key2 && node->key < key2)
        {
            return findTheSmallestCommonAncestorOfTwoNodes(node->right, key1, key2);
        }
        return node;
    }
};

#endif // TREE_H
