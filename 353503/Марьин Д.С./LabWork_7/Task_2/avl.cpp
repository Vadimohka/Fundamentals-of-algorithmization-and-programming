#include "avl.h"

template<typename T>
AVL<T>::AVL():root(nullptr),_size(0)
{}

template<typename T>
AVL<T>::AVL(const AVL &tree) : root(tree.root),_size(tree._size)
{}

template <typename T>
AVL<T>::AVL(int key ,T v):root(new Node(key, v)),_size(0)
{}

template <typename T>
AVL<T>::~AVL()
{
    clear(root);
}

template<typename T>
typename AVL<T>::Node *AVL<T>::getRoot()
{
    return root;
}

template<typename T>
void AVL<T>::addToTree(Node *p, QTreeWidgetItem *parentItem,QString prefix)
{
    if (p != nullptr)
    {
        if (p == root)
        {
            prefix = "Root : ";
        }
        if (parentItem != nullptr)
        {
            qDebug() << "Key: " << p->key;
            parentItem->setText(0, prefix + QString::number(p->key));
        }

        if (p->left != nullptr)
        {
            QTreeWidgetItem* leftItem = new QTreeWidgetItem();
            parentItem->addChild(leftItem);
            addToTree(p->left, leftItem,"Left : ");
        }

        if (p->right != nullptr)
        {
            QTreeWidgetItem* rightItem = new QTreeWidgetItem();
            parentItem->addChild(rightItem);
            addToTree(p->right, rightItem,"Right : ");
        }
    }
}

template<typename T>
void AVL<T>::addToTree(int key, T val , QTreeWidget* tree)
{
    insert(key,val);
    tree->clear(); // Clear the tree widget
    auto* item = new QTreeWidgetItem(tree);
    addToTree(root,item);
}

template <typename T>
typename AVL<T>::Node* AVL<T>::insert(Node* p,int key , T val)
{
    if(p == nullptr)
    {
       _size++;
       return new Node(key,val);
    }
    if(key < p->key)
    {
        p->left = insert(p->left,key,val);
    }
    else
    {
        p->right = insert(p->right,key,val);
    }
    return Balance(p);
}

template <typename T>
void AVL<T>::insert(int key , T val)
{
    root = insert(root,key,val);
}

template<typename T>
void AVL<T>::remove(int key)
{
    remove(root,key);
}

template <typename T>
typename AVL<T>::Node* AVL<T>::remove(Node* p,int key)
{
    if(p == nullptr)
    {
        return nullptr;
    }
    if(key < p->key)
    {
        p->left = remove(p->left,key);
    }
    else if(key > p->key)
    {
        p->right = remove(p->right,key);
    }
    else
    {
        Node* q = p->left;
        Node* r = p->right;
        delete p;
        if(r == nullptr)
        {
            return q;
        }
        Node* min = FindMin(r);
        min->right = RemoveMin(r);
        min->left = q;
        return Balance(min);
    }
}

template <typename T>
void AVL<T>::print(Node* p, QString& str)
{
    if (p != nullptr)
    {
        print(p->left,str); // print left subtree
        str += QString::number(p->key)+ " -> ";
        qDebug() << p->key << " "; // print current node
        print(p->right,str); // print right subtree
    }
    return;
}

template <typename T>
QString AVL<T>::print()
{
    QString s = "";
    if(root != nullptr)
    {
        print(root,s);
        s += "\n";
        qDebug() << "\n";
    }
    return s;
}

template <typename T>
void AVL<T>::reverse_print(Node* p,QString& s)
{
    if (p != nullptr)
    {
        reverse_print(p->right,s);
        s += QString::number(p->key) + "->";
        qDebug() << p->key << " "; // print current node
        reverse_print(p->left,s); // print left subtree
    }
}

template <typename T>
QString AVL<T>::reverse_print()
{
    QString s = "";
    reverse_print(root,s);
    qDebug() << "\n";
    s+= "\n";
    return s;
}

template<typename T>
void AVL<T>::Balance()
{
    root = Balance(root);
}

template<typename T>
void AVL<T>::updateTree(QTreeWidget* tree)
{
    Balance();
    tree->clear(); // Clear the tree widget
    auto* item = new QTreeWidgetItem(tree);
    addToTree(root,item);
}

template <typename T>
void AVL<T>::clear()
{
    while(root != nullptr)
    {
        root = remove(root,root->key);
    }
}

template <typename T>
size_t AVL<T>::Height(Node *p)
{
    return p ? p->height : 0;
}

template <typename T>
int AVL<T>::BFactor(Node *p)
{
    return Height(p->right) - Height(p->left);
}

template <typename T>
void AVL<T>::FixHeight(Node *p)
{
    size_t left = Height(p->left);
    size_t right = Height(p->right);
    p->height = (left > right ? left : right) + 1;
}

template <typename T>
typename AVL<T>::Node *AVL<T>::RotateRight(Node *p)
{
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    FixHeight(p);
    FixHeight(q);
    return q;
}

template <typename T>
typename AVL<T>::Node *AVL<T>::RotateLeft(Node *q)
{
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    FixHeight(p);
    FixHeight(q);
    return p;
}

template <typename T>
typename AVL<T>::Node *AVL<T>::Balance(Node *p)
{
    FixHeight(p);
    if(BFactor(p) == 2)
    {
        if (BFactor(p->right) < 0)
        {
            p->right = RotateRight(p->right);// big left rotate
        }
        return RotateLeft(p);
    }
    if(BFactor(p) == -2)
    {
        if (BFactor(p->left) > 0)
        {
            p->left = RotateLeft(p->left);// big right rotate
        }
        return RotateRight(p);
    }
    return p;
}

template <typename T>
typename AVL<T>::Node *AVL<T>::FindMin(Node *p)
{
    return p->left ? FindMin(p->left) : p;
}

template<typename T>
typename AVL<T>::Node *AVL<T>::FindMax(AVL::Node *p)
{
    return p->right ? FindMax(p->right) : p;
}

template <typename T>
typename AVL<T>::Node *AVL<T>::RemoveMin(Node *p)
{
    if(p->left == nullptr)
    {
        return p->right;
    }
    p->left = RemoveMin(p->left);
    return Balance(p);
}

template <typename T>
void AVL<T>::clear(Node *p)
{
    if(p != nullptr)
    {
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

template <typename T>
T AVL<T>::find(int key)
{
    Node* p = root;
    while(p != nullptr)
    {
        if(key < p->key)
        {
            p = p->left;
        }
        else if(key > p->key)
        {
            p = p->right;
        }
        else
        {
            return p->value;
        }
    }
    qDebug() << "Key not found" << "\n";
    return T();
}

template <typename T>
size_t AVL<T>::maxDepth(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        if (leftDepth > rightDepth)
        {
            return(leftDepth + 1);
        }
        else
        {
            return(rightDepth + 1);
        }
    }
}

template<typename T>
size_t AVL<T>::maxDepth()
{
    return maxDepth(root);
}

template class AVL<QString>;
