#include "bst.h"

BST::BST() {}

void BST::add(int v)
{
    root = add(root, v);
}

void BST::traversal()
{
    traversal(root);
}

Node *BST::add(Node *node, int v)
{
    if (node == nullptr)
    {
        return new Node(v);
    }
    if (v < node->key)
    {
        node->left = add(node->left, v);
        if (node->left != nullptr)
        {
            node->left->parent = node;
        }
    }
    else if (v > node->key)
    {
        node->right = add(node->right, v);
        if (node->right != nullptr)
        {
            node->right->parent = node;
        }
    }

    return node;
}

void BST::traversal(Node *node)
{
    if (node != nullptr)
    {
        traversal(node->left);
        qDebug() << node->key << " ";
        traversal(node->right);
    }
}

void BST::remove(int v)
{
    root = remove(root, v);
}

void BST::insertSubTree(Node *node)
{
    if (node != nullptr)
    {
        add(node->key);
        if (node->left != nullptr) insertSubTree(node->left);
        if (node->right != nullptr) insertSubTree(node->right);
    }
}

void BST::removeSubTree(int v)
{
    Node *node = find(v);
    if (node != nullptr)
    {
        removeSubTree(node);
    }
}

Node *BST::find(int v)
{
    return find(root, v);
}

Node *BST::lca(int v1, int v2)
{
    return lca(root, v1, v2);
}

Node *BST::lca(Node *node, int v1, int v2)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->key > v1 && node->key > v2)
    {
        return lca(node->left, v1, v2);
    }
    if (node->key < v1 && node->key < v2)
    {
        return lca(node->right, v1, v2);
    }
    return node;
}

Node *BST::find(Node *node, int v) {
    if (node == nullptr || node->key == v) {
        return node;
    }

    if (v < node->key)
    {
        return find(node->left, v);
    }
    else
    {
        return find(node->right, v);
    }
}

void BST::BST::removeSubTree(Node *node)
{
    if (node == root) root = nullptr;
    if (node == nullptr)
    {
        return;
    }

    removeSubTree(node->left);
    removeSubTree(node->right);

    if (node->parent != nullptr)
    {
        if (node->parent->left == node)
        {
            node->parent->left = nullptr;
        }
        else if (node->parent->right == node)
        {
            node->parent->right = nullptr;
        }
    }

    delete node;
}

Node *BST::remove(Node *node, int v)
{
    if (node == nullptr)
    {
        return node;
    }

    if (v < node->key)
    {
        node->left = remove(node->left, v);
    }
    else if (v > node->key)
    {
        node->right = remove(node->right, v);
    }
    else
    {
        if (node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = minValueNode(node->right);
        node->key = temp->key;
        node->right = remove(node->right, temp->key);
    }
    return node;
}

Node *BST::minValueNode(Node *node)
{
    Node* current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}
