#include "tree.h"
#include <iostream>
#include <ostream>

template<typename T, typename U>
Tree<T, U>::Tree()
{
    root = nullptr;
}

template<typename T, typename U>
Tree<T, U>::Tree(std::pair<T, U> *arr, std::size_t size)
{
    for(int i = 0; i < size; i++)
    {
        this->insert(root, arr[i]->first, arr[i]->second);
    }
    root = nullptr;
}

template<typename T, typename U>
Tree<T, U>::~Tree()
{
    reverseTraverse(root);
    root = nullptr;
}


template<typename T, typename U>
void Tree<T, U>::add(Node<T, U> *&node, T key, U value)
{
    if(node == nullptr)
    {
        node = new Node(key, value);
    }
    else if(key < node->key)
    {
        if(node->left == nullptr)
        {
            node->left = new Node(key, value);
            node->left->parent = std::move(node);
        }
        else add(node->left, key, value);
    }
    else
    {
        if(node->right == nullptr)
        {
            node->right = new Node(key, value);
            node->right->parent = std::move(node);
        }
        else add(node->right, key, value);
    }
}

template<typename T, typename U>
void Tree<T, U>::add(T key, U value)
{
    add(root, key, value);
}

template<typename T, typename U>
void Tree<T, U>::remove(Node<T, U> *&node, T key)
{
    if(node == nullptr) return;
    else if(key < node->key) remove(node->left, key);
    else if(key > node->key) remove(node->right, key);
    else
    {
        if((node->left == nullptr) || (node->right == nullptr))
        {
            Node<T, U>* tmp;

            if(node->left == nullptr)
            {
                tmp = std::move(node->right);
                if(tmp) tmp->parent = std::move(node->parent);

                delete node;
                node = std::move(tmp);
            }
            else
            {
                tmp = node->left;
                if(tmp) tmp->parent = node->parent;

                delete node;
                node = std::move(tmp);
            }

            tmp = nullptr;
        }
        else
        {
            Node<T, U>* maxInLeft = getMax(node->left);
            node->key = maxInLeft->key;
            node->value = maxInLeft->value;
            remove(node->left, maxInLeft->key);
        }
    }
}

template<typename T, typename U>
void Tree<T, U>::remove(T key)
{
    return remove(root, key);
}

template<typename T, typename U>
void Tree<T, U>::remove(Node<T, U>* &node, T key, U value)
{
    if(node == nullptr) return;
    else if(key < node->key) remove(node->left, key, value);
    else if(key > node->key) remove(node->right, key, value);
    else if(key == node->key && value != node->value) remove(node->right, key, value);
    else
    {
        if((node->left == nullptr) || (node->right == nullptr))
        {
            Node<T, U>* tmp;

            if(node->left == nullptr)
            {
                tmp = std::move(node->right);
                if(tmp) tmp->parent = std::move(node->parent);

                delete node;
                node = std::move(tmp);
            }
            else
            {
                tmp = node->left;
                if(tmp) tmp->parent = std::move(node->parent);

                delete node;
                node = std::move(tmp);
            }

            tmp = nullptr;
        }
        else
        {
            Node<T, U>* maxInLeft = getMax(node->left);
            node->key = maxInLeft->key;
            node->value = maxInLeft->value;
            remove(node->left, maxInLeft->key, maxInLeft->value);
        }
    }
}

template<typename T, typename U>
Node<T, U> *Tree<T, U>::find(Node<T, U> *node, T key)
{
    if(node == nullptr || node->key == key) return node;
    return (key < node->key) ? find(node->left, key) : find(node->right, key);
}

template<typename T, typename U>
Node<T, U> *Tree<T, U>::find(T key)
{
    return find(root, key);
}

template<typename T, typename U>
void Tree<T, U>::insertSubtree(Tree<T, U> *subTree)
{
    straightTraverseCopy(subTree->root);
}

template<typename T, typename U>
void Tree<T, U>::removeSubtree(Node<T, U>*& subtreeRoot)
{
    if (subtreeRoot == nullptr) {
        return;
    }
    reverseTraverse(subtreeRoot);
    subtreeRoot = nullptr;
}

template<typename T, typename U>
void Tree<T, U>::removeSubtree(Tree<T, U>*& subTree)
{
    if (subTree == nullptr || subTree->root == nullptr) {
        return;
    }

    reverseTraverseDelete(subTree->root);
}

template<typename T, typename U>
void Tree<T, U>::insertBranch(Node<T, U> *&node, Node<T, U> *branchNode, bool isLeftBranch)
{
    if(branchNode == nullptr) return;
    add(node, branchNode->key, branchNode->value);

    if(isLeftBranch) insertBranch(node, branchNode->left, isLeftBranch);
    else insertBranch(node, branchNode->right, isLeftBranch);
}

template<typename T, typename U>
void Tree<T, U>::insertBranch(Node<T, U> *branchNode, bool isLeftBranch)
{
    insertBranch(root, branchNode, isLeftBranch);
}

template<typename T, typename U>
void Tree<T, U>::insertBranch(Tree<T, U> *branch, bool isLeftBranch)
{
    insertBranch(branch->root, isLeftBranch);
}

template<typename T, typename U>
void Tree<T, U>::removeBranch(Node<T, U> *&node, Node<T, U> *branchNode, bool isLeftBranch)
{
    if(branchNode == nullptr) return;

    remove(node, branchNode->key, branchNode->value);

    if(isLeftBranch) removeBranch(node, branchNode->left, isLeftBranch);
    else removeBranch(node, branchNode->right, isLeftBranch);
}

template<typename T, typename U>
void Tree<T, U>::removeBranch(Node<T, U> *branchNode, bool isLeftBranch)
{
    removeBranch(root, branchNode, isLeftBranch);
}

template<typename T, typename U>
void Tree<T, U>::removeBranch(Tree<T, U> *branch, bool isLeftBranch)
{
    removeBranch(branch->root, isLeftBranch);
}

template<typename T, typename U>
Node<T, U> *Tree<T, U>::getMax(Node<T, U> *&node)
{
    if(node == nullptr) return nullptr;
    if(node->right == nullptr) return node;
    else return getMax(node->right);
}

template<typename T, typename U>
Node<T, U> *Tree<T, U>::getMin(Node<T, U> *&node)
{
    if(node == nullptr) return nullptr;
    if(node->left == nullptr) return node;
    else return getMin(node->left);
}

template<typename T, typename U>
void Tree<T, U>::symmetricalTraverse()
{
    symmetricalTraverse(root);
}

template<typename T, typename U>
void Tree<T, U>::reverseTraverse()
{
    reverseTraverse(root);
}


template<typename T, typename U>
void Tree<T, U>::symmetricalTraverse(Node<T, U> *&node) //возрастание
{
    if(node == nullptr) return;
    symmetricalTraverse(node->left);
    std::cout << node->key << " - " << node->value.toStdString() << std::endl;
    symmetricalTraverse(node->right);
}

template<typename T, typename U>
void Tree<T, U>::reverseTraverse(Node<T, U>*& node)
{
    if (node == nullptr) {
        return;
    }

    reverseTraverse(node->left);
    reverseTraverse(node->right);

    delete node;
    node = nullptr;
}


template<typename T, typename U>
void Tree<T, U>::straightTraverseCopy(Node<T, U>* newNode) //copy
{
    if(newNode == nullptr) return;
    add(newNode->key, newNode->value);
    straightTraverseCopy(newNode->left);
    straightTraverseCopy(newNode->right);
}

template<typename T, typename U>
void Tree<T, U>::reverseTraverseDelete(Node<T, U> *newNode)
{
    if(newNode == nullptr) return;
    reverseTraverseDelete(newNode->left);
    reverseTraverseDelete(newNode->right);
    remove(root, newNode->key, newNode->value);
}

template<typename T, typename U>
Node<T, U> *Tree<T, U>::lowestCommonAncestor(Node<T, U> *u, Node<T, U> *v)
{
    Node<T, U> *a, *b;
    a = u;
    b = v;

    int h1 = depth(a);
    int h2 = depth(b);

    while (h1 != h2) {
        if (h1 > h2) {
            a = std::move(a->parent);
            h1--;
        } else {
            b = std::move(b->parent);
            h2--;
        }
    }

    while (a != b) {
        a = std::move(a->parent);
        b = std::move(b->parent);
    }

    return a;
}

template<typename T, typename U>
T Tree<T, U>::lowestCommonAncestor(T u, T v)
{
    if(find(u) && find(v)) return (lowestCommonAncestor(find(u), find(v)))->key;
    else return -12345667521387612;
}


template<typename T, typename U>
int Tree<T, U>::depth(Node<T, U> *&node)
{
    if(node == nullptr) return -1;
    return 1 + depth(node->parent);
}

template<typename T, typename U>
void Tree<T, U>::fillTreeWidget(QTreeWidgetItem *&parent, Node<T, U> *node)
{
    if (node == nullptr) return;

    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0, QString::number(node->key) + '(' + node->value + ')');

    fillTreeWidget(item, node->left);
    fillTreeWidget(item, node->right);
}

