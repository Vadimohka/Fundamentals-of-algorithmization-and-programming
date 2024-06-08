#include "tree.h"

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
}


template<typename T, typename U>
void Tree<T, U>::insert(Node<T, U> *&node, T key, U value)
{
    if(node == nullptr)
    {
        node = new Node(key, value);
    }
    else if(key < node->key)
    {
        if(node->left == nullptr) node->left = new Node(key, value);
        else insert(node->left, key, value);
    }
    else
    {
        if(node->right == nullptr) node->right = new Node(key, value);
        else insert(node->right, key, value);
    }

    updateHeight(node);
    balance(node);
}

template<typename T, typename U>
void Tree<T, U>::insert(T key, U value)
{
    insert(root, key, value);
}

template<typename T, typename U>
Node<T, U> *Tree<T, U>::remove(Node<T, U> *&node, T key)
{
    if(node == nullptr) return nullptr;
    else if(key < node->key) node->left = remove(node->left, key);
    else if(key > node->key) node->right = remove(node->right, key);
    else
    {
        if((node->left == nullptr) || (node->right == nullptr))
        {
            Node<T, U>* tmp;

            if(node->left == nullptr)
            {
                tmp = node->right;
                delete node;
                node = tmp;
            }
            else
            {
                tmp = node->left;
                delete node;
                node = tmp;
            }

            //node = (node->left == nullptr) ? node->right : node->left;
        }
        else
        {
            Node<T, U>* maxInLeft = getMax(node->left);
            node->key = maxInLeft->key;
            node->value = maxInLeft->value;
            node->left = remove(node->left, maxInLeft->key);
        }
    }
    if(node != nullptr)
    {
        updateHeight(node);
        balance(node);
    }

    return node;
}

template<typename T, typename U>
Node<T, U> *Tree<T, U>::remove(T key)
{
    return remove(root, key);
}

template<typename T, typename U>
Node<T, U> *Tree<T, U>::search(Node<T, U> *node, T key)
{
    if(!node) return nullptr;
    if(node->key == key) return node;
    return (key < node->key) ? search(node->left, key) : search(node->right, key);
}

template<typename T, typename U>
Node<T, U> *Tree<T, U>::search(T key)
{
    return search(root, key);
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
void Tree<T, U>::symmetricalPrint(QLineEdit *lineEdit)
{
    symmetricalPrint(root, lineEdit);
}

template<typename T, typename U>
void Tree<T, U>::reversePrint(QLineEdit *lineEdit)
{
    reversePrint(root, lineEdit);
}

template<typename T, typename U>
void Tree<T, U>::straightPrint(QLineEdit *lineEdit)
{
    straightPrint(root, lineEdit);
}

template<typename T, typename U>
void Tree<T, U>::symmetricalPrint(Node<T, U> *node, QLineEdit* lineEdit) //возрастание
{
    if(node == nullptr) return;
    symmetricalPrint(node->left, lineEdit);
    lineEdit->setText(lineEdit->text() + (node->value) + " | ");
    symmetricalPrint(node->right, lineEdit);
}

template<typename T, typename U>
void Tree<T, U>::reversePrint(Node<T, U> *node, QLineEdit* lineEdit) //delete
{
    if(node == nullptr) return;
    reversePrint(node->left, lineEdit);
    reversePrint(node->right, lineEdit);
    lineEdit->setText(lineEdit->text() + (node->value) + " | ");
}

template<typename T, typename U>
void Tree<T, U>::straightPrint(Node<T, U> *node, QLineEdit* lineEdit) //copy
{
    if(node == nullptr) return;
    lineEdit->setText(lineEdit->text() + (node->value) + " | ");
    straightPrint(node->left, lineEdit);
    straightPrint(node->right, lineEdit);
}

template<typename T, typename U>
int Tree<T, U>::getHeight(Node<T, U> *node)
{
    return ((node == nullptr) ? (-1) : (node->height));
}

template<typename T, typename U>
void Tree<T, U>::updateHeight(Node<T, U> *node)
{
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

template<typename T, typename U>
int Tree<T, U>::getBalance(Node<T, U> *node)
{
    return (node == nullptr) ? 0 : getHeight(node->right) - getHeight(node->left);
}

template<typename T, typename U>
void Tree<T, U>::swap(Node<T, U> *&a, Node<T, U> *&b)
{    
    T a_key = a->key;
    a->key = b->key;
    b->key = a_key;

    U a_value = a->value;
    a->value = b->value;
    b->value = a_value;
}

template<typename T, typename U>
void Tree<T, U>::rightRotate(Node<T, U> *&node)
{
    swap(node, node->left);
    Node<T, U>* buffer = node->right;

    node->right = node->left;
    if(node->right) node->left = node->right->left;
    if(node->right) node->right->left = node->right->right;
    if(node->right) node->right->right = buffer;

    updateHeight(node->right);
    updateHeight(node);
}

template<typename T, typename U>
void Tree<T, U>::leftRotate(Node<T, U> *&node)
{
    swap(node, node->right);
    Node<T, U>* buffer = node->left;

    node->left = node->right;
    if(node->left) node->right = node->left->right;
    //if(node->right) node->right->left = node->right->right;
    if(node->left) node->left->right = node->left->left;
    node->left->left = buffer;

    updateHeight(node->left);
    updateHeight(node);
}

template<typename T, typename U>
void Tree<T, U>::balance(Node<T, U> *node)
{
    int balance = getBalance(node);

    if(balance == -2)
    {
        if(getBalance(node->left) == 1) leftRotate(node->left);
        rightRotate(node);
    }
    else if(balance == 2)
    {
        if(getBalance(node->right) == -1) rightRotate(node->right);
        leftRotate(node);
    }
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
